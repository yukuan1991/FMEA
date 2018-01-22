#ifndef VIDEO_WIDGET_H
#define VIDEO_WIDGET_H

#include <QWidget>
#include "video/video_player.hpp"
#include <tuple>

namespace Ui {
class video_widget;
}

class video_widget : public QWidget
{
    Q_OBJECT

public:
    explicit video_widget(QWidget *parent = 0);
    ~video_widget();

public:
    /// 修改视频路径
    void set_file(const QString &file);

    QString file () const noexcept;
    /// 播放视频
    void play_video();
    /// 暂停视频
    void pause_video(bool b = true);
    /// 停止播放
    void stop_video();
    /// 获取视频播放速度
    float speed();
    /// 设置视频播放速度
    void set_speed(float speed);
    /// 设置视频播放进度
    void set_position(long long int position);
    /// 获取视频播放进度
    long long int position()const noexcept;
    /// 获取视频播放状态
    video_player::state_enum state();
    /// 设置标记无效的进度条的位置
    bool set_progress_label_position(std::pair<unsigned long long, unsigned long long> pos);
    const std::vector<qint64> &retrieve_invalid();
    /// 载入标记位置
    void set_invalid(const std::vector<qint64> &data);
    /// 是否隐藏黄色进度条
    void set_mark_enabled(bool b);
    /// 标记无效的进度条是否可见
    bool is_mark_enabled();
    /// 获取当前视频总长度
    long long int duration();

    /// 卸载媒体
    void unload ();

    /// 清除标记时间段
    void clear_invalid ();

    /// 无效时间能否被清除
    bool is_clearable ();

    /// 设置无效时间能否被清除
    void set_clearable (bool b);

    /// 设置可播放区间
    void add_section (unsigned long long start_time, unsigned long long end_time);

    /// 播放区间功能是否开启
    void open_section_function (bool b);

    /// 清除播放区域
    void clear_section ();

    ///在播放暂停中切换
    void switch_play_pause ();

private:
    QString get_time_str (long long int pos);
    void on_position_changed(qint64 position);

    /// 重用播放区域
    void reboot_section ();

signals:
    /// 视频播放速度改变
    void speed_changed(float);

    /// 视频播放状态改变
    void state_changed(video_player::state_enum);

    /// 视频总长度改变
    void duration_changed (qint64);

    /// 视频文件改变
    void file_changed (QString);

    /// 当播放进入了标记无效区域
    void stepped_into_invalid(qint64,qint64);

private slots:
    /// 当播放按钮被按下
    void on_play_clicked();

    /// 当停止按钮被按下
    void on_stop_clicked();

    /// 当音量条被移动
    void on_volume_bar_sliderMoved(int position);

    /// 当静音按钮被按下
    void on_mute_clicked();

    /// 处理视频总长度的改变
    void on_player_duration_changed(qint64 max_time);

    /// 处理视频播放状态的改变
    void on_player_state_changed(video_player::state_enum state);

    /// 处理视频静音状态的改变
    void on_player_mute_changed(bool is_mute);

    /// 当视频播放进度条的被按住
    void on_progress_bar_sliderPressed();

    /// 当视频播放进度条被放开
    void on_progress_bar_sliderReleased();

    /// 视频播放区间控制
    void playable_section_control (qint64 position);

private:
    Ui::video_widget *ui;

    QString duration_ = "00:00:00";

    QMetaObject::Connection position_conn_;

    std::vector <std::pair <unsigned long long, unsigned long long>> section_;

    bool section_fuction_is_working = false;


};



#endif // VIDEO_WIDGET_H
