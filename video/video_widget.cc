#include "video/video_widget.h"
#include <boost/filesystem.hpp>
#include "ui_video_widget.h"

video_widget::video_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::video_widget)
{
    ui->setupUi(this);
    ui->volume_bar->setValue(100);
    ui->progress_bar->setValue(0);
    ui->play->setIcon(this->style()->standardIcon(QStyle::SP_MediaPlay));
    ui->stop->setIcon(this->style()->standardIcon(QStyle::SP_MediaStop));
    ui->mute->setIcon(this->style()->standardIcon(QStyle::SP_MediaVolumeMuted));
    ui->player->set_notify_interval(100);
    ui->player->set_mute (true);

    connect (ui->player, &video_player::file_changed, [=] (const QString& qstr) {emit video_widget::file_changed (qstr);});
    connect (ui->progress_area,&progress_label::stepped_into_invalid, [=] (qint64 pos_in , qint64 pos_out) {emit video_widget::stepped_into_invalid(pos_in,pos_out);});
    position_conn_ = connect (ui->player, &video_player::position_changed, this, &video_widget::on_position_changed);
}

video_widget::~video_widget()
{
    delete ui;
}

void video_widget::on_play_clicked()
{
    if(ui->player->state() == video_player::stopped_state)
    {
        ui->player->play_video();
    }
    else
    {
        ui->player->pause_video(ui->player->state()!= video_player::paused_state);
    }
}

void video_widget::on_player_duration_changed(qint64 max_time)
{
    ui->progress_bar->setMaximum(max_time);
    ui->progress_area->set_duration (max_time);

    duration_ = get_time_str(max_time);
    ui->video_clock->setText("00:00:00/" + duration_);

    emit duration_changed(max_time);
}


void video_widget::on_position_changed(qint64 position)
{
    ui->video_clock->setText(get_time_str(position) + "/" + duration_);
    ui->progress_bar->setValue(position);
    ui->progress_area->set_position (position);
}


void video_widget::reboot_section()
{
    if (!section_.empty ())
    {
        for (auto && iter : section_)
        {
            std::get <0> (iter) = true;
        }
    }
}

void video_widget::clear_section()
{
    section_.clear ();
}

void video_widget::switch_play_pause()
{
    on_play_clicked ();
}

void video_widget::on_player_state_changed(video_player::state_enum state)
{
    if(state == video_player::playing_state)
    {
        ui->play->setIcon(this->style()->standardIcon(QStyle::SP_MediaPause));
        ui->progress_bar->setEnabled(true);
        ui->player->set_volume(((float)(ui->volume_bar->value()))/100);
        ui->stop->setEnabled(true);
    }
    else if(state == video_player::stopped_state)
    {
        ui->progress_bar->setValue(0);
        ui->progress_bar->setEnabled(false);
        ui->stop->setEnabled(false);
        ui->play->setIcon(this->style()->standardIcon(QStyle::SP_MediaPlay));
    }
    else
    {
        ui->player->pause_video(true);
        ui->play->setIcon(this->style()->standardIcon(QStyle::SP_MediaPlay));
    }

    emit state_changed(state);
}

void video_widget::on_player_mute_changed(bool is_mute)
{
    if(is_mute)
    {
        ui->mute->setIcon(this->style()->standardIcon(QStyle::SP_MediaVolumeMuted));
    }
    else
    {
        ui->mute->setIcon(this->style()->standardIcon(QStyle::SP_MediaVolume));
    }
}

void video_widget::on_stop_clicked()
{
    if(ui->player->state()!= video_player::stopped_state)
    {
        ui->player->stop_video();
    }
}

void video_widget::on_volume_bar_sliderMoved(int position)
{
    ui->player->set_volume((static_cast<float> (position)) / 100);
}

void video_widget::set_file(const QString &file)
{
    ui->player->set_file(file);
}

QString video_widget::file() const noexcept
{
    return ui->player->file ();
}

void video_widget::play_video()
{
    ui->player->play_video();
}

void video_widget::pause_video(bool b)
{
    ui->player->pause_video(b);
}

void video_widget::stop_video()
{
    ui->player->stop_video();
}

float video_widget::speed()
{
    return ui->player->speed();
}

void video_widget::set_speed(float speed)
{
    ui->player->set_speed(speed);
}

void video_widget::set_position(long long position)
{
    ui->player->set_position(position);
}

long long video_widget::position() const noexcept
{
    return ui->player->position();
}

video_player::state_enum video_widget::state()
{
    return ui->player->state();
}

bool video_widget::set_progress_label_position(std::pair<unsigned long long, unsigned long long> pos)
{
    return ui->progress_area->add_invalid(pos);
}

const std::vector<qint64> &video_widget::retrieve_invalid()
{
    return ui->progress_area->retrieve_invalid();
}

void video_widget::set_invalid(const std::vector<qint64> &data)
{
    ui->progress_area->set_invalid(data);
}

void video_widget::set_mark_enabled(bool b)
{
    if(b)
    {
        ui->progress_area->show();
    }
    else
    {
        ui->progress_area->hide();
    }
}

bool video_widget::is_mark_enabled()
{
    return ui->progress_area->isVisible();
}

long long video_widget::duration()
{
    return ui->player->duration();
}

void video_widget::unload()
{
    ui->player->unload ();
}

void video_widget::clear_invalid()
{
    ui->progress_area->clear_invalid();
}

bool video_widget::is_clearable()
{
    return ui->progress_area->is_clearable ();
}

void video_widget::set_clearable(bool b)
{
    ui->progress_area->set_clearable (b);
}

void video_widget::add_section(unsigned long long start_time,unsigned long long end_time)
{
    section_.emplace_back (start_time, end_time);
}

void video_widget::open_section_function(bool b)
{
    if (b)
    {
        section_fuction_is_working = true;
        //ui->progress_bar->setEnabled (false);
        connect (ui->player, &video_player::position_changed, this, &video_widget::playable_section_control);
        //connect (ui->player, &video_player::state_changed, this, &video_widget::jump_function);
    }
    else
    {
        section_.clear ();
        section_fuction_is_working = false;
        //ui->progress_bar->setEnabled (true);
        disconnect (ui->player, &video_player::position_changed, this, &video_widget::playable_section_control);
        //disconnect (ui->player, &video_player::state_changed, this, &video_widget::jump_function);
    }
}

QString video_widget::get_time_str(long long position)
{
    std::vector<char> buf (50);
    ::memset(buf.data(), 0x00, buf.size());

    int hour = position / 3600 / 1000;
    int minutes = position / 1000 % 3600 / 60;
    int seconds = position / 1000 % 3600 % 60;
    int one_tenth = position % 1000 / 100;

    snprintf(buf.data(), buf.size(), "%d:%02d:%02d.%1d", hour, minutes, seconds, one_tenth);
    assert (buf [buf.size() - 1] == '\0');

    return buf.data();
}

void video_widget::on_mute_clicked()
{
    if(!ui->player->is_mute())
    {
        ui->player->set_mute(true);
    }
    else
    {
        ui->player->set_mute(false);
    }
}



void video_widget::on_progress_bar_sliderPressed()
{
    disconnect (position_conn_);
}

void video_widget::on_progress_bar_sliderReleased()
{
    ui->player->set_position (ui->progress_bar->value ());
    position_conn_ = connect (ui->player, &video_player::position_changed, this, &video_widget::on_position_changed);
}

void video_widget::playable_section_control(qint64 position)
{
    if (section_fuction_is_working)
    {
        if (!section_.empty ())
        {
            for (auto && iter : section_)
            {
                auto start_time = iter.first;
                auto end_time = iter.second;

                if (static_cast<uint64_t> (position) < start_time)
                {
                    set_position (start_time);
                    return;
                }
                else if (static_cast<uint64_t>(position) >= end_time)
                {
                    continue;
                }
                else
                {
                    return;
                }
            }
            stop_video ();
        }
    }
}


