/********************************************************************************
** Form generated from reading UI file 'video_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEO_WIDGET_H
#define UI_VIDEO_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "video/progress_label.h"
#include "video/video_player.hpp"

QT_BEGIN_NAMESPACE

class Ui_video_widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    video_player *player;
    QHBoxLayout *horizontalLayout;
    QToolButton *mute;
    QSlider *volume_bar;
    QFrame *line_6;
    QToolButton *play;
    QToolButton *stop;
    QFrame *line_7;
    QVBoxLayout *verticalLayout_4;
    progress_label *progress_area;
    QSlider *progress_bar;
    QLabel *video_clock;

    void setupUi(QWidget *video_widget)
    {
        if (video_widget->objectName().isEmpty())
            video_widget->setObjectName(QStringLiteral("video_widget"));
        video_widget->resize(494, 455);
        verticalLayout_2 = new QVBoxLayout(video_widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        player = new video_player(video_widget);
        player->setObjectName(QStringLiteral("player"));

        verticalLayout->addWidget(player);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        mute = new QToolButton(video_widget);
        mute->setObjectName(QStringLiteral("mute"));
        mute->setEnabled(true);

        horizontalLayout->addWidget(mute);

        volume_bar = new QSlider(video_widget);
        volume_bar->setObjectName(QStringLiteral("volume_bar"));
        volume_bar->setEnabled(true);
        volume_bar->setMaximum(100);
        volume_bar->setPageStep(10);
        volume_bar->setSliderPosition(100);
        volume_bar->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(volume_bar);

        line_6 = new QFrame(video_widget);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_6);

        play = new QToolButton(video_widget);
        play->setObjectName(QStringLiteral("play"));
        play->setCheckable(false);

        horizontalLayout->addWidget(play);

        stop = new QToolButton(video_widget);
        stop->setObjectName(QStringLiteral("stop"));
        stop->setEnabled(false);
        stop->setCheckable(false);

        horizontalLayout->addWidget(stop);

        line_7 = new QFrame(video_widget);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_7);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        progress_area = new progress_label(video_widget);
        progress_area->setObjectName(QStringLiteral("progress_area"));

        verticalLayout_4->addWidget(progress_area);

        progress_bar = new QSlider(video_widget);
        progress_bar->setObjectName(QStringLiteral("progress_bar"));
        progress_bar->setEnabled(false);
        progress_bar->setMaximum(100);
        progress_bar->setTracking(true);
        progress_bar->setOrientation(Qt::Horizontal);
        progress_bar->setTickPosition(QSlider::NoTicks);

        verticalLayout_4->addWidget(progress_bar);


        horizontalLayout->addLayout(verticalLayout_4);

        video_clock = new QLabel(video_widget);
        video_clock->setObjectName(QStringLiteral("video_clock"));

        horizontalLayout->addWidget(video_clock);

        horizontalLayout->setStretch(6, 1);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 1);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(video_widget);

        QMetaObject::connectSlotsByName(video_widget);
    } // setupUi

    void retranslateUi(QWidget *video_widget)
    {
        video_widget->setWindowTitle(QApplication::translate("video_widget", "Form", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        mute->setToolTip(QApplication::translate("video_widget", "\351\235\231\351\237\263\345\274\200\345\205\263", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        mute->setText(QString());
#ifndef QT_NO_TOOLTIP
        play->setToolTip(QApplication::translate("video_widget", "\346\222\255\346\224\276/\346\232\202\345\201\234 (\346\214\211\344\270\213\347\251\272\346\240\274\345\210\207\346\215\242)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        play->setText(QString());
#ifndef QT_NO_TOOLTIP
        stop->setToolTip(QApplication::translate("video_widget", "\345\201\234\346\255\242", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        stop->setText(QString());
        progress_area->setText(QString());
        video_clock->setText(QApplication::translate("video_widget", "00:00:00/00:00:00", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class video_widget: public Ui_video_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEO_WIDGET_H
