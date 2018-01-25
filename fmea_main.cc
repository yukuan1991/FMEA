#include "fmea_main.h"
#include "ui_fmea_main.h"
#include "fema_analysis.h"
#include <QStyleFactory>
#include <QMessageBox>
#include <QMdiSubWindow>

#include <base/io/file/file.hpp>
#include <base/utils/charset.hpp>
#include <QFileDialog>
#include "openvaf.h"
#include "json.hpp"
#include <QDebug>

using nlohmann::json;
using namespace std;


fmea_main::fmea_main(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fmea_main)
{
    ui->setupUi(this);
    ui->mdi->setViewMode (QMdiArea::TabbedView);
    inti_con();
    set_button_enabled();
    setStyle (QStyleFactory::create ("fusion"));
    setWindowTitle("FEMA");
}

fmea_main::~fmea_main()
{
    delete ui;
}

fema_analysis * fmea_main::active_canvas_view()
{
    if(QMdiSubWindow* active_subwindow = ui->mdi->activeSubWindow())
    {
        fema_analysis* canvas_ptr = dynamic_cast<fema_analysis*>(active_subwindow->widget());
        return canvas_ptr;
    }
    else
    {
        return nullptr;
    }
}

void fmea_main::set_button_enabled()
{
    const bool has_canvas_view = (active_canvas_view() != nullptr);
    ui->rib->set_enabled(has_canvas_view);
}

void fmea_main::create_analysis()
{
    auto w = create_window ("未命名");
    w->set_task_count ();
}

void fmea_main::fmea_open()
{
    const auto path = QFileDialog::getOpenFileName (this, "文件打开", ".", tr ("Fmea File (*.fmea)"));
    if (path.isEmpty ())
    {
        return;
    }

    auto res = file::read_all (::utf_to_sys (path.toStdString ()).data ());
    if (not res)
    {
        QMessageBox::information (this, "打开", "文件无法打开,读取失败");
        return;
    }
    try
    {
        auto w = create_window (path);
        w->load (res.value ());
    }
    catch (std::exception &)
    {
        QMessageBox::information (this, "打开", "文件格式错误 无法打开");
        return;
    }
}

not_null<fema_analysis *> fmea_main::create_window(const QString &title)
{
    auto v_win = make_unique<fema_analysis> ();
    v_win->setAttribute (Qt::WA_DeleteOnClose);
    auto w = ui->mdi->addSubWindow (v_win.get ());
    w->setWindowTitle (title);
    w->setWindowState (Qt::WindowMaximized);
    return v_win.release ();
}

void fmea_main::inti_con()
{
    connect (ui->rib, &ribbon::file_new, this, &fmea_main::create_analysis);
    connect (ui->rib, &ribbon::file_open, this, &fmea_main::fmea_open);
    connect (ui->rib, &ribbon::file_save, this, &fmea_main::on_save);
    connect (ui->rib, &ribbon::file_saveas, this, &fmea_main::on_save_as);
    connect (ui->rib, &ribbon::file_exit, this, &fmea_main::close);
    connect(ui->mdi, &QMdiArea::subWindowActivated, this, &fmea_main::set_button_enabled);

    connect (ui->rib, &fmea_ribbon::file_import, this, &fmea_main::fmea_import);

    connect (ui->rib, &fmea_ribbon::file_set_project_name, this, &fmea_main::fmea_set_project_name);
    connect (ui->rib, &fmea_ribbon::file_set_type , this, &fmea_main::fmea_set_type);
    connect (ui->rib, &fmea_ribbon::file_set_responsibility, this, &fmea_main::fmea_set_responsibility);
    connect (ui->rib, &fmea_ribbon::file_set_core , this, &fmea_main::fmea_set_core);
    connect (ui->rib, &fmea_ribbon::file_set_date , this, &fmea_main::fmea_set_date );
    connect (ui->rib, &fmea_ribbon::file_set_number , this, &fmea_main::fmea_set_number);
    connect (ui->rib, &fmea_ribbon::file_set_f_date , this, &fmea_main::fmea_set_f_date );
    connect (ui->rib, &fmea_ribbon::file_set_auther , this, &fmea_main::fmea_set_auther );
}

void fmea_main::fmea_import()
{
    const auto path = QFileDialog::getOpenFileName (this, "文件打开", ".", tr ("Fmea File (*.vaf)"));
    if (path.isEmpty ())
    {
        return;
    }

    auto res = file::read_all (::utf_to_sys (path.toStdString ()).data ());
    if (not res)
    {
        QMessageBox::information (this, "打开", "文件无法打开,读取失败");
        return;
    }
    try
    {
        auto w = current_sub_window ();
        if (w == nullptr)
        {
            return;
        }

        w->import(res.value ());
    }
    catch (std::exception &)
    {
        QMessageBox::information (this, "打开", "文件格式错误 无法打开");
        return;
    }
}

void fmea_main::on_save()
{
    const auto active = ui->mdi->currentSubWindow ();
    if (active == nullptr)
    {
        return;
    }
    auto w = dynamic_cast<fema_analysis *> (active->widget ());

    if (w == nullptr)
    {
        return;
    }

    if (const auto title_path = active->windowTitle ();
            title_path == "未命名")
    {
        const auto path = QFileDialog::getSaveFileName(this, "文件保存", ".", tr ("Fmea File (*.fmea)"));
        active->setWindowTitle(path);
        const auto data = w->export_data ();
        file::write_buffer (::utf_to_sys (path.toStdString ()).data (), data);
    }
    else
    {
        const auto data = w->export_data ();
        file::write_buffer (::utf_to_sys (title_path.toStdString ()).data (), data);
    }
}

void fmea_main::on_save_as()
{

    const auto active = ui->mdi->currentSubWindow ();
    if (active == nullptr)
    {
        return;
    }
    auto w = dynamic_cast<fema_analysis *> (active->widget ());

    if (w == nullptr)
    {
        return;
    }
    const auto path = QFileDialog::getSaveFileName(this, "文件保存", ".", tr ("Fmea File (*.fmea)"));
    active->setWindowTitle(path);
    const auto data = w->export_data ();
    file::write_buffer (::utf_to_sys (path.toStdString ()).data (), data);
}

void fmea_main::fmea_set_project_name()
{
    auto w = current_sub_window ();
    w->set_project_name ();
}

void fmea_main::fmea_set_type()
{
    auto w = current_sub_window ();
    w->set_type ();
}

void fmea_main::fmea_set_responsibility()
{
    auto w = current_sub_window ();
    w->set_responsibility ();
}

void fmea_main::fmea_set_core()
{
    auto w = current_sub_window ();
    w->set_core ();
}

void fmea_main::fmea_set_date()
{
    auto w = current_sub_window ();
    w->set_date ();
}

void fmea_main::fmea_set_number()
{
    auto w = current_sub_window ();
    w->set_number ();
}

void fmea_main::fmea_set_f_date()
{
    auto w = current_sub_window ();
    w->set_f_date ();
}

void fmea_main::fmea_set_auther()
{
    auto w = current_sub_window ();
    w->set_auther ();
}

fema_analysis *fmea_main::current_sub_window()
{
    const auto active = ui->mdi->currentSubWindow ();
    if (active == nullptr)
    {
        return nullptr;
    }
    auto w = dynamic_cast<fema_analysis *> (active->widget ());

    return w;
}
