#pragma once

#include <QWidget>
#include <base/lang/not_null.h>
#include <string>

namespace Ui {
class fmea_main;
}

class QMdiArea;
class QMdiSubWindow;
class fema_analysis;

class fmea_main : public QWidget
{
    Q_OBJECT
public:
    explicit fmea_main(QWidget *parent = 0);
    virtual ~fmea_main();
    QMdiArea * area ();
    fema_analysis * active_canvas_view();

private:
    Ui::fmea_main *ui;
    void set_button_enabled();
    void create_analysis ();
    void fmea_open();
    not_null<fema_analysis*> create_window (const QString & title);
    void inti_con();
    void fmea_import();
    void on_save();
    void on_save_as();

    void fmea_set_project_name();
    void fmea_set_type();
    void fmea_set_responsibility();
    void fmea_set_core();
    void fmea_set_date();
    void fmea_set_number();
    void fmea_set_f_date();
    void fmea_set_auther();
    fema_analysis * current_sub_window ();
};
