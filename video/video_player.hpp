#ifndef VIDEO_PLAYER_H
#define VIDEO_PLAYER_H

#include <QtAVWidgets>
#include <AVPlayer.h>
#include <memory>
#include <ciso646>

class video_player : public QtAV::GLWidgetRenderer2
{
    Q_OBJECT

public: // types
    using state_enum = typename QtAV::AVPlayer::State;
    static constexpr state_enum playing_state = QtAV::AVPlayer::PlayingState;
    static constexpr state_enum paused_state = QtAV::AVPlayer::PausedState;
    static constexpr state_enum stopped_state = QtAV::AVPlayer::StoppedState;

public: // functions
    /// 常规构造
    video_player(QWidget *parent = nullptr) : QtAV::GLWidgetRenderer2(parent)
    {
        player_->setAutoLoad (false);
        player_->setRenderer(this);
        connect(player_.get(), &QtAV::AVPlayer::stateChanged, [=](auto state) {emit this->state_changed(state); });
        connect(player_.get(), &QtAV::AVPlayer::durationChanged, [=](auto d) {emit this->duration_changed(d); });
        connect(player_->audio(), &QtAV::AudioOutput::muteChanged, [=] (bool b){emit mute_changed(b); });
        connect(player_.get(), &QtAV::AVPlayer::seekableChanged, [=] {emit seekable_changed(); });
        connect(player_.get(), &QtAV::AVPlayer::positionChanged, [=](auto i) {this->position_changed(i); });
        connect(player_.get(), &QtAV::AVPlayer::speedChanged, this, &video_player::speed_changed);
        connect(player_.get(), &QtAV::AVPlayer::sourceChanged, [=]() {emit file_changed(player_->file()); });
        connect(player_->audio(), &QtAV::AudioOutput::volumeChanged, this, &video_player::volume_changed);
        connect(player_.get(), &QtAV::AVPlayer::startPositionChanged, this, &video_player::start_position_changed);
        connect(player_.get(), &QtAV::AVPlayer::notifyIntervalChanged, this, &video_player::notify_interval_changed);
    }
    /// 默认析构
    virtual ~video_player() = default;

    /// 播放已经载入的视频
    auto play_video() { player_->play(); }

    /// 文件路径
    QString file() const noexcept { return player_->file(); }
    /// 载入文件
    auto set_file(const QString& file) { player_->stop (); return player_->setFile(file); }

    /// 设置视频播放进度
    auto set_position(long long int pos) { player_->seek(pos);}
    /// 获取播放进度
    auto position() const noexcept { return player_->position();}

    ///静音属性
    auto set_mute(bool b) { player_->audio()->setMute(b);}
    ///是否已经静音
    auto is_mute() const noexcept { return player_->audio()->isMute();}

    ///音量
    auto set_volume(float percent) noexcept { player_->audio()->setVolume(percent);}
    auto volume() const noexcept { return player_->audio()->volume();}

    /// 停止视频播放
    auto stop_video() { player_->stop();}

    ///设置是否暂停
    auto pause_video(bool b) { if (player_->state () != stopped_state) player_->pause(b);}
    void pause(bool) = delete;


    auto set_speed(float f) { player_->setSpeed(f); }
    auto speed() const noexcept { return player_->speed(); }

    /// 起始位置
    void set_start_position (long long int pos) { player_->setStartPosition (pos);}
    long long int start_position () const noexcept { return player_->startPosition ();}

    /// 返回当前播放器的状态
    auto state() const noexcept { return player_->state(); }

    /// 是否可搜寻
    bool is_seekable() const noexcept { return player_->isSeekable(); }

    /// 播放时长
    long long int duration () const noexcept { return player_->duration ();}

    /// 通知时间变更的间隔
    int notify_interval () const noexcept { return player_->notifyInterval ();}
    /// 设置通知时间变更的间隔
    void set_notify_interval (int msec) noexcept { player_->setNotifyInterval (msec); }

    /// 卸载媒体
    void unload () { /*player_->unload ();*/ }

signals:
    /// 当播放状态改变时触发
    void state_changed(video_player::state_enum);

    /// 当播放进度改变时触发
    void position_changed(qint64);

    /// 当视频的总长度改变时触发
    void duration_changed(qint64);

    /// 当静音状态变更时触发
    void mute_changed(bool);

    /// 当视频的可搜寻状态变更时触发
    void seekable_changed();

    /// 视频播放速度改变时触发
    void speed_changed(float);

    /// 当文件改变时发出的信号
    void file_changed(QString);

    /// 音量变化时发出的信号
    void volume_changed(float);

    /// 起始位置更改时发出的信号
    void start_position_changed (qint64);

    /// 通知时间间隔改变时发出的信号
    void notify_interval_changed ();

private:
    /// 播放器对象
    std::unique_ptr<QtAV::AVPlayer> player_ = std::make_unique<QtAV::AVPlayer> ();
};



#endif // VIDEO_PLAYER_H
