/********************************************************************************
** Form generated from reading UI file 'fmea_main.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FMEA_MAIN_H
#define UI_FMEA_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "fmea_ribbon.h"

QT_BEGIN_NAMESPACE

class Ui_fmea_main
{
public:
    QVBoxLayout *verticalLayout;
    fmea_ribbon *rib;
    QMdiArea *mdi;

    void setupUi(QWidget *fmea_main)
    {
        if (fmea_main->objectName().isEmpty())
            fmea_main->setObjectName(QStringLiteral("fmea_main"));
        fmea_main->resize(400, 300);
        verticalLayout = new QVBoxLayout(fmea_main);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        rib = new fmea_ribbon(fmea_main);
        rib->setObjectName(QStringLiteral("rib"));

        verticalLayout->addWidget(rib);

        mdi = new QMdiArea(fmea_main);
        mdi->setObjectName(QStringLiteral("mdi"));

        verticalLayout->addWidget(mdi);

        verticalLayout->setStretch(1, 1);

        retranslateUi(fmea_main);

        QMetaObject::connectSlotsByName(fmea_main);
    } // setupUi

    void retranslateUi(QWidget *fmea_main)
    {
        fmea_main->setWindowTitle(QApplication::translate("fmea_main", "FMEA", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class fmea_main: public Ui_fmea_main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FMEA_MAIN_H
