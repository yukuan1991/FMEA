#ifndef PROGRESS_LABEL_H
#define PROGRESS_LABEL_H
#include <memory>
#include <QLabel>
#include <QMenu>
#include <QDebug>


class progress_label : public QLabel
{
    Q_OBJECT
public:
    template <typename ... ARGS>
    progress_label(ARGS&& ... args) : QLabel (std::forward<ARGS>(args)...)
    {
        init ();
    }
    void init ();

    ~progress_label () override {  }

public:
    /// 总时长
    void set_duration(qint64 duration);
    auto duration() { return total_; }

    /// 时间点
    auto position () { return pos_; }
    void set_position (qint64 pos);

    /// 无效时间
    bool add_invalid (const std::pair<qint64, qint64>& p);
    const auto& retrieve_invalid () { return boundaries_; }
    void set_invalid (const std::vector<qint64>& data) { boundaries_ = data; repaint ();}

    /// 可清除无效时间
    bool is_clearable () { return clearable_;}
    void set_clearable (bool b) { clearable_ = b;}

    void clear_invalid ()
    {
        boundaries_.clear();
        repaint ();
    }

signals:
    void duration_changed (qint64);
    void position_changed (qint64);
    void stepped_into_invalid (qint64, qint64);

private:
    bool is_invalid_pos (int pos);
    void clear_invalid_area ();

protected:
    void paintEvent(QPaintEvent* event) override;
    void mouseReleaseEvent (QMouseEvent *ev) override;
private:
    qint64 total_ = 0;
    long long int pos_ = 0;
    std::vector<qint64> boundaries_;
    std::vector<qint64> color_start_;
    std::vector<std::pair<qint64, qint64>> pix_to_pos;
    std::unique_ptr<QMenu> menu_ = std::make_unique<QMenu> ();

    bool clearable_ = false;
    int right_click_pos_ = -1;
};

#endif // PROGRESS_LABEL_H
