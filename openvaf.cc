#include "openvaf.h"

#include <QMap>
#include <vector>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>
#include <base/lang/scope.hpp>
#include <QDirIterator>
#include <base/io/file/file.hpp>
#include <base/utils/charset.hpp>
#include <boost/range/algorithm_ext/push_back.hpp>
#include <boost/range/adaptor/transformed.hpp>


using boost::adaptors::transformed;
using boost::push_back;
using std::end;
using std::vector;
using std::string_view;

/// 传入一个JSON的字符串然后会解析出一个文件中的所有任务信息
vector<taskInfo> readVaf (string_view data)
{
    QByteArray arr (data.data (), static_cast<int> (data.size ()));

    QJsonParseError err;
    auto doc = QJsonDocument::fromJson (arr, &err);

    if (err.error != QJsonParseError::NoError)
    {
        return {};
    }

    auto top = doc.object ().toVariantMap ();
    if (top.empty ())
    {
        return {};
    }

    auto form = top.find ("form");
    if (form == end (top))
    {
        return {};
    }

    auto formValue = form.value ().toMap ();
    if (formValue.empty ())
    {
        return {};
    }

    auto res = formValue.find ("结果");
    if (res == end (formValue))
    {
        return {};
    }

    auto resValue = res.value ();
    if (resValue.type () != QVariant::List)
    {
        return {};
    }

    auto resList = resValue.toList ();
    if (resList.isEmpty ())
    {
        return {};
    }

    vector<taskInfo> ret;
    ret.reserve (static_cast<size_t> (resList.size ()));

    auto taskList = formValue.find ("作业内容");
    auto taskListValue = taskList.value ().toList ();
    if (taskListValue.size () != resList.size ())
    {
        return {};
    }

    int i = 0;
    for (auto & it : resList)
    {
        SCOPE_EXIT { i ++; };
        if (it.type () != QVariant::Map)
        {
            return {};
        }

        auto map = it.toMap ();
        auto stdTime = map.find ("标准时间");

        if (stdTime == end (map))
        {
            return {};
        }

        bool isOk = false;
        const auto stdTimeValue = stdTime.value ().toDouble (&isOk);
        if (!isOk)
        {
            return {};
        }

        auto taskType = map.find ("操作分类");

        if (taskType == end (map))
        {
            return {};
        }

        auto taskTypeValue = taskType.value ().toString ();

        workType type;
        if (taskTypeValue == "加工")
        {
            type = workType::Processing;
        }
        else if (taskTypeValue == "搬运")
        {
            type = workType::Moving;
        }
        else if (taskTypeValue == "检查")
        {
            type = workType::Checking;
        }
        else if (taskTypeValue == "等待")
        {
            type = workType::Waiting;
        }
        else
        {
            return {};
        }

        auto taskName = taskListValue.at (i);

        if (taskName.type () != QVariant::String)
        {
            return {};
        }

        const auto taskNameValue = taskName.toString ();

        taskInfo info;
        info.name = taskNameValue;
        info.stdTime = stdTimeValue;
        info.type = type;
        ret.emplace_back (::move (info));
    }

    return ret;
}


QStringList findAll (const QString & path, const QStringList & filter)
{
    QStringList ret;
    QDirIterator it (path, filter, QDir::Files, QDirIterator::Subdirectories);

    while (it.hasNext ())
    {
        ret << it.next ();
    }

    return ret;
}


/// 用法: collectVaf (目录) 可以收集该目录下所有的vaf信息
QMap<QString, vector<taskInfo>> collectVaf (const QString & folder)
{
    const auto files = findAll (folder, QStringList () << "*.vaf");

    QMap<QString, vector<taskInfo>> ret;
    for (auto & it : files)
    {
        auto content = file::read_all (::utf_to_sys (it.toStdString ()).data ());
        if (content)
        {
            ret [it] = readVaf (content.value ());
        }
    }

    return ret;
}

vector<qint64> readVafInvalid(string_view data)
{
    QByteArray arr (data.data (), static_cast<int> (data.size ()));

    QJsonParseError err;
    auto doc = QJsonDocument::fromJson (arr, &err);

    if (err.error != QJsonParseError::NoError)
    {
        return {};
    }

    auto top = doc.object ().toVariantMap ();
    if (top.empty ())
    {
        return {};
    }

    auto invalid = top.find ("invalid").value ().toList ();

    if (invalid.empty ())
    {
        return {};
    }

    std::vector<qint64> ret;

    push_back (ret, invalid | transformed ([] (auto && v) { return v.toLongLong (); }));

    return ret;
}

QString readVafVideoPath(std::string_view data)
{
    QByteArray arr (data.data (), static_cast<int> (data.size ()));

    QJsonParseError err;
    auto doc = QJsonDocument::fromJson (arr, &err);

    if (err.error != QJsonParseError::NoError)
    {
        return {};
    }

    auto top = doc.object ().toVariantMap ();
    if (top.empty ())
    {
        return {};
    }

    auto path = top.find ("video-file").value ().toString ();

    return path;
}
