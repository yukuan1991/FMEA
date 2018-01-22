#pragma once
#include <QString>
#include <vector>
#include <string_view>
#include <QStringList>

enum class workType
{
    Processing = 0, Checking = 1, Moving = 2, Waiting = 3
};

struct taskInfo
{
    QString name;
    qreal stdTime;
    workType type;
};

std::vector<taskInfo> readVaf (std::string_view data);
std::vector<qint64> readVafInvalid (std::string_view data);
QString readVafVideoPath (std::string_view data);
QStringList findAll (const QString & path, const QStringList & filter);
QMap<QString, std::vector<taskInfo>> collectVaf (const QString & folder);

