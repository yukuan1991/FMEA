#include "fmea_ribbon.h"

#include <array>
#include <base/lang/move.hpp>
#include <QDebug>
#include <QButtonGroup>
#include <QMessageBox>

using namespace std;

fmea_ribbon::fmea_ribbon(QWidget *parent)
    :ribbon (parent)
{
    vector<ui_group> edit;
    edit.resize (2);
    {
        vector<ui_group> edit;
        edit.resize (1);
        button_cell b;
        b.add ("导入", QPixmap ("png/导入.png"), import);
        b.set_title ("文件(vaf file)");
        edit.at (0) = ::move (b);
        add_tab (edit, "编辑");
    }

    {
        vector<ui_group> edit;
        edit.resize (1);
        button_cell b;
        b.add ("项目名称", QPixmap ("png/035.png"), set_project_name);
        b.add ("产品类型", QPixmap ("png/036.png"), set_type);
        b.add ("过程责任", QPixmap ("png/037.png"), set_responsibility);
        b.add ("核心小组", QPixmap ("png/038.png"), set_core);
        b.add ("关键日期", QPixmap ("png/039.png"), set_date);
        b.add ("FMEA编号", QPixmap ("png/040.png"), set_number);
        b.add ("FMEA日期", QPixmap ("png/041.png"), set_f_date);
        b.add ("编织者", QPixmap ("png/042.png"), set_auther);
        b.set_title ("属性设置");
        edit.at (0) = ::move (b);
        add_tab (edit, "设置");
    }
    inti_con();
}


void fmea_ribbon::inti_con()
{
    connect (cut, &ribbon_tool::clicked, [] { QMessageBox::information (nullptr, "新建", "新建点击"); });

    connect (import, &ribbon_tool::clicked, this, &fmea_ribbon::file_import);

    connect (set_project_name, &ribbon_tool::clicked, this, &fmea_ribbon::file_set_project_name);
    connect (set_type, &ribbon_tool::clicked, this, &fmea_ribbon::file_set_type);
    connect (set_responsibility, &ribbon_tool::clicked, this, &fmea_ribbon::file_set_responsibility);
    connect (set_core, &ribbon_tool::clicked, this, &fmea_ribbon::file_set_core);
    connect (set_date, &ribbon_tool::clicked, this, &fmea_ribbon::file_set_date);
    connect (set_number, &ribbon_tool::clicked, this, &fmea_ribbon::file_set_number);
    connect (set_f_date, &ribbon_tool::clicked, this, &fmea_ribbon::file_set_f_date);
    connect (set_auther, &ribbon_tool::clicked, this, &fmea_ribbon::file_set_auther );

    connect (this, &fmea_ribbon::set_enabled, import, &ribbon_tool::setEnabled);
    connect(this, &fmea_ribbon::set_enabled, set_project_name, &ribbon_tool::setEnabled);
    connect(this, &fmea_ribbon::set_enabled, set_type, &ribbon_tool::setEnabled);
    connect(this, &fmea_ribbon::set_enabled, set_responsibility, &ribbon_tool::setEnabled);
    connect(this, &fmea_ribbon::set_enabled, set_core, &ribbon_tool::setEnabled);
    connect(this, &fmea_ribbon::set_enabled, set_date, &ribbon_tool::setEnabled);
    connect(this, &fmea_ribbon::set_enabled, set_number, &ribbon_tool::setEnabled);
    connect(this, &fmea_ribbon::set_enabled, set_f_date, &ribbon_tool::setEnabled);
    connect(this, &fmea_ribbon::set_enabled, set_auther, &ribbon_tool::setEnabled);

}


