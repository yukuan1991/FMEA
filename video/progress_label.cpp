#include "progress_label.h"
#include <string>
#include <base/lang/scope.hpp>
#include <QPainter>
#include <QMenu>
#include <algorithm>
#include <QDebug>
#include <QMouseEvent>
#include <assert.h>

void progress_label::init()
{

}

void progress_label::set_duration(qint64 duration)
{
    if (duration == total_) return;
    total_ = duration;
    emit duration_changed (duration);

    menu_->clear ();
    auto action_clear_invalid = menu_->addAction ("清除无效区域");

    connect (action_clear_invalid, &QAction::triggered, this, &progress_label::clear_invalid_area);

    repaint ();
}

void progress_label::set_position(qint64 pos)
{
    SCOPE_EXIT
    {
        repaint ();
    };

    assert (boundaries_.size () % 2 == 0);
    if (pos == pos_) return;
    pos_ = pos;
    emit position_changed (pos);


    unsigned i=0;
    unsigned rank = -1;

    for (; i < boundaries_.size (); i++)
    {
        if (boundaries_[i] < pos)
        {
            rank = i;
        }
        else
        {
            break;
        }
    }

    if (rank %2 == 0)
    {
        assert (rank + 1 < boundaries_.size ());
        emit stepped_into_invalid (boundaries_[rank], boundaries_[rank + 1]);
    }
}

bool progress_label::add_invalid(const std::pair<qint64, qint64> &p)
{
    assert (p.first < p.second);
    assert (boundaries_.size () % 2 == 0);

    SCOPE_EXIT
    {
        std::sort (boundaries_.begin (), boundaries_.end ());
        repaint ();
    };

    if (boundaries_.empty ())
    {
        boundaries_.emplace_back (p.first);
        boundaries_.emplace_back (p.second);
        return true;
    }

    int first_rank = -1;
    int second_rank = -1;

    for (unsigned i = 0; i < boundaries_.size (); i ++)
    {
        if (boundaries_[i] < p.first)
        {
            first_rank = static_cast<int>(i);
        }
        if (boundaries_[i] < p.second)
        {
            second_rank = static_cast<int>(i);
        }
    }

    if (first_rank != second_rank or first_rank % 2 == 0)
    {
        return false;
    }

    boundaries_.push_back (p.first);
    boundaries_.push_back (p.second);

    return true;
}

bool progress_label::is_invalid_pos(int pos)
{
    assert (color_start_.size () % 2 == 0);
    for (unsigned i = 0; i < color_start_.size (); i++)
    {
        if (pos < color_start_[i])
        {
            return i % 2;
        }
    }
    return false;
}

void progress_label::clear_invalid_area()
{
    assert (right_click_pos_ >= 0);
    assert (color_start_.size () % 2 == 0);
    assert (!color_start_.empty ());

    unsigned j = 0;
    for (unsigned i = 0; i < color_start_.size (); i ++)
    {
        if (right_click_pos_ >= color_start_[i])
        {
            j = i;
        }
        else
        {
            break;
        }
    }

    assert (j % 2 == 0);
    assert (j + 1 < color_start_.size ());
    boundaries_.erase (boundaries_.begin ()+ j, boundaries_.begin () + j + 2);

    repaint ();
    right_click_pos_ = -1;
}

void progress_label::paintEvent(QPaintEvent*)
{
    if (total_ == 0)
    {
        return;
    }

    color_start_.clear ();
    pix_to_pos.clear ();

    int pix_pos = pos_ * width () / total_;

    QVector<QPoint> pt { {pix_pos, height() / 2}, {pix_pos - height() / 5, 0}, {pix_pos + height() / 5, 0} };

    QPainter painter{ this };
    painter.setRenderHint (QPainter::Antialiasing);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor (0, 166, 173));
    painter.drawPolygon(QPolygon{ pt });

    painter.setBrush (QColor (32, 90, 167));
    painter.drawRect(0, height() / 2, width(), height());

    if (boundaries_.empty ())
    {
        return;
    }

    painter.setBrush(QColor (183, 183, 183));
    for (uint32_t i = 0; i < boundaries_.size() - 1; i++)
    {
        auto start_pos = boundaries_[i] * static_cast<unsigned long long>(width ()) / total_;
        auto end_pos = boundaries_[i + 1] * static_cast<unsigned long long> (width ()) / total_ - 1;

        color_start_.emplace_back (start_pos);
        pix_to_pos.emplace_back (start_pos, boundaries_[i]);

        if (i % 2 == 1) continue;

        painter.drawRect (start_pos, height () / 2, end_pos - start_pos, height ());
    }

    color_start_.emplace_back (boundaries_.back () * width () / total_);

    assert (color_start_.size () == boundaries_.size ());
}

void progress_label::mouseReleaseEvent(QMouseEvent *ev)
{
    for (auto iter = color_start_.begin (); iter != color_start_.end (); ++iter)
    {
        assert (iter + 1 == color_start_.end () or (*iter) < (*(iter + 1)));
    }


    QLabel::mouseReleaseEvent (ev);
    if (ev->button () != Qt::RightButton or clearable_ == false or ev->pos ().y () < height () / 2)
    {
        return;
    }

    if (!is_invalid_pos (ev->pos ().x ()))
    {
        return;
    }

    right_click_pos_ = ev->pos ().x ();

    menu_->exec (QCursor::pos ());
}
