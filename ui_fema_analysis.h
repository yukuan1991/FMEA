/********************************************************************************
** Form generated from reading UI file 'fema_analysis.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEMA_ANALYSIS_H
#define UI_FEMA_ANALYSIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "video/video_widget.h"

QT_BEGIN_NAMESPACE

class Ui_fema_analysis
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *form;
    QHBoxLayout *horizontalLayout;
    video_widget *video_player;
    QWidget *player;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLabel *core_value;
    QLabel *type_value;
    QLabel *date_value;
    QLabel *responsibility_value;
    QLabel *number_value;
    QLabel *auther_value;
    QLabel *name;
    QLabel *f_date_value;
    QLabel *date;
    QLabel *type;
    QLabel *number;
    QLabel *responsibility;
    QLabel *f_date;
    QLabel *core;
    QLabel *auther;
    QLabel *name_value;

    void setupUi(QWidget *fema_analysis)
    {
        if (fema_analysis->objectName().isEmpty())
            fema_analysis->setObjectName(QStringLiteral("fema_analysis"));
        fema_analysis->resize(1020, 687);
        verticalLayout = new QVBoxLayout(fema_analysis);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        form = new QTableView(fema_analysis);
        form->setObjectName(QStringLiteral("form"));

        verticalLayout->addWidget(form);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        video_player = new video_widget(fema_analysis);
        video_player->setObjectName(QStringLiteral("video_player"));

        horizontalLayout->addWidget(video_player);

        player = new QWidget(fema_analysis);
        player->setObjectName(QStringLiteral("player"));

        horizontalLayout->addWidget(player);

        widget_2 = new QWidget(fema_analysis);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        core_value = new QLabel(widget_2);
        core_value->setObjectName(QStringLiteral("core_value"));

        gridLayout->addWidget(core_value, 3, 1, 1, 1);

        type_value = new QLabel(widget_2);
        type_value->setObjectName(QStringLiteral("type_value"));

        gridLayout->addWidget(type_value, 1, 1, 1, 1);

        date_value = new QLabel(widget_2);
        date_value->setObjectName(QStringLiteral("date_value"));

        gridLayout->addWidget(date_value, 0, 3, 1, 1);

        responsibility_value = new QLabel(widget_2);
        responsibility_value->setObjectName(QStringLiteral("responsibility_value"));

        gridLayout->addWidget(responsibility_value, 2, 1, 1, 1);

        number_value = new QLabel(widget_2);
        number_value->setObjectName(QStringLiteral("number_value"));

        gridLayout->addWidget(number_value, 1, 3, 1, 1);

        auther_value = new QLabel(widget_2);
        auther_value->setObjectName(QStringLiteral("auther_value"));

        gridLayout->addWidget(auther_value, 3, 3, 1, 1);

        name = new QLabel(widget_2);
        name->setObjectName(QStringLiteral("name"));

        gridLayout->addWidget(name, 0, 0, 1, 1);

        f_date_value = new QLabel(widget_2);
        f_date_value->setObjectName(QStringLiteral("f_date_value"));

        gridLayout->addWidget(f_date_value, 2, 3, 1, 1);

        date = new QLabel(widget_2);
        date->setObjectName(QStringLiteral("date"));

        gridLayout->addWidget(date, 0, 2, 1, 1);

        type = new QLabel(widget_2);
        type->setObjectName(QStringLiteral("type"));

        gridLayout->addWidget(type, 1, 0, 1, 1);

        number = new QLabel(widget_2);
        number->setObjectName(QStringLiteral("number"));

        gridLayout->addWidget(number, 1, 2, 1, 1);

        responsibility = new QLabel(widget_2);
        responsibility->setObjectName(QStringLiteral("responsibility"));

        gridLayout->addWidget(responsibility, 2, 0, 1, 1);

        f_date = new QLabel(widget_2);
        f_date->setObjectName(QStringLiteral("f_date"));

        gridLayout->addWidget(f_date, 2, 2, 1, 1);

        core = new QLabel(widget_2);
        core->setObjectName(QStringLiteral("core"));

        gridLayout->addWidget(core, 3, 0, 1, 1);

        auther = new QLabel(widget_2);
        auther->setObjectName(QStringLiteral("auther"));

        gridLayout->addWidget(auther, 3, 2, 1, 1);

        name_value = new QLabel(widget_2);
        name_value->setObjectName(QStringLiteral("name_value"));

        gridLayout->addWidget(name_value, 0, 1, 1, 1);


        horizontalLayout->addWidget(widget_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);

        retranslateUi(fema_analysis);

        QMetaObject::connectSlotsByName(fema_analysis);
    } // setupUi

    void retranslateUi(QWidget *fema_analysis)
    {
        fema_analysis->setWindowTitle(QApplication::translate("fema_analysis", "Form", Q_NULLPTR));
        core_value->setText(QString());
        type_value->setText(QString());
        date_value->setText(QString());
        responsibility_value->setText(QString());
        number_value->setText(QString());
        auther_value->setText(QString());
        name->setText(QApplication::translate("fema_analysis", "\351\241\271\347\233\256\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        f_date_value->setText(QString());
        date->setText(QApplication::translate("fema_analysis", "\345\205\263\351\224\256\346\227\245\346\234\237\357\274\232", Q_NULLPTR));
        type->setText(QApplication::translate("fema_analysis", "\344\272\247\345\223\201\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        number->setText(QApplication::translate("fema_analysis", "FMEA\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        responsibility->setText(QApplication::translate("fema_analysis", "\350\277\207\347\250\213\350\264\243\344\273\273\357\274\232", Q_NULLPTR));
        f_date->setText(QApplication::translate("fema_analysis", "FMEA\346\227\245\346\234\237\357\274\232", Q_NULLPTR));
        core->setText(QApplication::translate("fema_analysis", "\346\240\270\345\277\203\345\260\217\347\273\204\357\274\232", Q_NULLPTR));
        auther->setText(QApplication::translate("fema_analysis", "\347\274\226\347\273\207\350\200\205\357\274\232", Q_NULLPTR));
        name_value->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class fema_analysis: public Ui_fema_analysis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEMA_ANALYSIS_H
