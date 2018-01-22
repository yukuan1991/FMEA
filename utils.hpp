#ifndef UTILS_HPP
#define UTILS_HPP
#include <QtGlobal>

struct action_ratio
{
    qreal processing, moving, checking, waiting;
};

struct overall_stats
{
    qreal max_val = 0, min_val = 0, average = 0, deviation = 0;
};

#endif // UTILS_HPP
