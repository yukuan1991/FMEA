#pragma once

#include <QWidget>
#include "json.hpp"
#include <string_view>
#include "openvaf.h"
#include <string_view>
#include "fmea_model.h"
#include "fmea_delegate.h"
#include <string_view>
#include <vector>
using nlohmann::json;
namespace Ui {
class fema_analysis;
}

class fema_analysis : public QWidget
{
    Q_OBJECT

public:
    explicit fema_analysis(QWidget *parent = 0);
    virtual ~fema_analysis();
    void set_task_count ();
    void load (std::string_view data);
    void set_form();
    std::string export_data ();

    void set_project_name();
    void set_type();
    void set_responsibility();
    void set_core();
    void set_date();
    void set_number();
    void set_f_date();
    void set_auther();

    bool import (std::string_view view);

    QVariantMap getvalue();
private:
    json result_data();
    Ui::fema_analysis *ui;
    fmea_model * model = new fmea_model (this);
    fmea_delegate * delegate = new fmea_delegate (this);
};

