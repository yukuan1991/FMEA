#pragma once
#include "ribbon.h"


class fmea_ribbon : public ribbon
{
    Q_OBJECT
signals:
    void file_import();
    void file_set_project_name();
    void file_set_type();
    void file_set_responsibility();
    void file_set_core();
    void file_set_date();
    void file_set_number();
    void file_set_f_date();
    void file_set_auther();
public:
    fmea_ribbon(QWidget * parent = nullptr);
private:
    ribbon_tool * cut = nullptr, * copy = nullptr, * paste = nullptr, * del = nullptr;
    ribbon_tool * import = nullptr;

    ribbon_tool * set_project_name = nullptr, * set_type = nullptr, *set_responsibility = nullptr
            , * set_core = nullptr, * set_date = nullptr, * set_number = nullptr, * set_f_date = nullptr, * set_auther = nullptr;

    void inti_con();
};
