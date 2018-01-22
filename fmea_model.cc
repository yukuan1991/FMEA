#include "fmea_model.h"
#include<base/lang/not_null.h>
#include <assert.h>
#include <QDebug>
#include <QColor>
#include <QFontMetrics>
#include <QJsonDocument>
#include <base/lang/scope.hpp>
#include <vector>

fmea_model::fmea_model(QObject *parent)
    :QAbstractTableModel(parent)
{
//    for (auto & it : header_)
//    {
//        data_[it] = {};
//    }

    for (auto & it : header_)
    {
        QVariantMap map = data_[it.first].toMap ();
        map[it.second] = QVariantList ();

        data_[it.first] = map;
    }
}

int fmea_model::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED (parent);
   return rows + 2;
}
int fmea_model::columnCount(const QModelIndex &parent) const
{
     Q_UNUSED (parent);
    return static_cast<int> (header_.size ());
}
QVariant fmea_model::data(const QModelIndex &index, int role) const
{
    const auto row = index.row ();
    const auto col = index.column ();

    if (row >= rowCount () or col >= columnCount ())
    {
        return {};
    }

    if (Qt::DisplayRole == role)
    {
        if (row < 2)
        {
            return titleData (index);
        }
        else
        {
            return contentData (index);
        }

    }

    if (Qt::ToolTipRole == role)
    {
        const auto content = data (index).toString ();
        return content;
    }

    if (Qt::BackgroundColorRole == role)
    {
        if (row < 2)
        {
            return QColor (244, 244, 244);
        }
        else
        {
            return {};
        }
    }

    if (Qt::TextAlignmentRole == role)
    {
        return Qt::AlignHCenter;
    }

    if (Qt::SizeHintRole == role)
    {
        const auto content = data (index).toString ();
        const auto metrics = QFontMetrics (QFont ("宋体", 11));
        return QSize (metrics.width (content), metrics.height ());
    }

    return {};
}

QVariant fmea_model::titleData(const QModelIndex &index) const
{
    if (index.row () < 0 or index.column () < 0)
    {
        qDebug () << __PRETTY_FUNCTION__ << " " << __LINE__;
        return {};
    }


    const auto row = static_cast<size_t> (index.row ());
    const auto col = static_cast<size_t> (index.column ());

    if (row == 0)
    {
        return header_.at (col).first;
    }
    else
    {
        return header_.at (col).second;
    }
}

QVariant fmea_model::contentData(const QModelIndex &index) const
{
    const auto row = index.row ();
    const auto col = index.column ();

    const auto firstHeader = data (this->index (0, col)).toString ();
    const auto secondHeader = data (this->index (1, col)).toString ();


    if (secondHeader.startsWith (calculatedHeaderPrefix))
    {
        const auto data1 = handleString(data (this->index (row, col - 1)).toString ());
        if (not data1)
        {
            return {};
        }

        const auto data2 = handleString(data (this->index (row, col - 2)).toString ());
        if (not data2)
        {
            return {};
        }

        const auto data3 = handleString(data (this->index (row, col - 3)).toString ());
        if (not data3)
        {
            return {};
        }

        return data1.value () * data2.value () * data3.value ();
    }
    assert (row >= 2);
    return data_[firstHeader].toMap ()[secondHeader].toList ().at (row - 2);
}

bool fmea_model::setData(const QModelIndex &index, const QVariant &value, int role)
{
    SCOPE_EXIT { dataChanged (this->index (0, 0), this->index (rowCount () - 1, columnCount () - 1)); };

    const auto row = index.row ();
    const auto col = index.column ();

    if (row >= rowCount () or col >= columnCount () or row < 2)
    {
        return false;
    }

    if (Qt::EditRole == role)
    {
        const auto firstHeader = data (this->index (0, col)).toString ();
        const auto secondHeader = data (this->index (1, col)).toString ();

        auto secondMap = data_[firstHeader].toMap ();

        auto list = secondMap[secondHeader].toList ();

        const auto real_row = row - 2;
        assert (real_row >= 0 and real_row < list.size ());

        list[real_row] = value;
        secondMap[secondHeader] = list;
        data_[firstHeader] = secondMap;

        return true;
    }
    return false;
}

QVariantMap fmea_model::dump() const
{
    return data_;
}


void fmea_model::load(QVariantMap map)
{
    beginResetModel ();
    data_ = map;
    rows = data_.begin ().value ().toMap ().begin ().value ().toList ().size ();
    endResetModel ();
}


void fmea_model::clear()
{
    for (int i = 2; i < rowCount (); i ++)
    {
        for (int j = 0; j < columnCount (); j ++)
        {
            setData (this->index (i, j), QVariant (), Qt::EditRole);
        }
    }
}

Qt::ItemFlags fmea_model::flags(const QModelIndex &index) const
{
    if (index.row() > 1)
    {
        return QAbstractTableModel::flags (index) | Qt::ItemIsEditable;
    }
    else
    {
        return Qt::ItemIsEnabled;
    }
}

fmea_model::~fmea_model()
{

}

void fmea_model::setRowCount(int newRow)
{
    if (newRow <= 0 or newRow == rows)
    {
        return;
    }

    beginResetModel ();

    for (auto & it : data_)
    {
        auto secondMap = it.toMap ();

        for (auto & l : secondMap)
        {
            auto list = l.toList ();
            if (newRow > rows)
            {
                for (int i = 0; i < newRow - rows; i ++)
                {
                    list.append (QVariant ());
                }
            }
            else
            {
                for (int i = 0; i < rows - newRow; i ++)
                {
                    list.pop_back ();
                }
            }

            l = list;
        }

        it = secondMap;
    }
    rows = newRow;
    endResetModel ();
}

std::optional<int> fmea_model::handleString(const QString &str)
{
    bool isOk = false;
    const auto i = str.split (" ").front ().toInt (&isOk);
    if (isOk)
    {
        return i;
    }
    else
    {
        return {};
    }
}



