#include "fema_analysis.h"
#include "ui_fema_analysis.h"
#include <QInputDialog>
#include <QDebug>
#include "openvaf.h"
#include <base/lang/not_null.h>
#include <QJsonDocument>

using namespace std;

fema_analysis::fema_analysis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fema_analysis)
{
    ui->setupUi(this);
    ui->form->setModel(model);
    ui->form->setItemDelegate(delegate);
    ui->form->setEditTriggers (QAbstractItemView::DoubleClicked);
    set_form();
}

fema_analysis::~fema_analysis()
{
    delete ui;
}

void fema_analysis::set_task_count()
{
    QInputDialog dlg;
    dlg.setWindowTitle ("新建");
    dlg.setLabelText ("请填写操作步数");
    dlg.setOkButtonText ("确 定");
    dlg.setCancelButtonText ("取 消");
    dlg.setInputMode (QInputDialog::IntInput);
    dlg.setIntRange (0, 1000);
    if (dlg.exec () == QDialog::Accepted)
    {
        auto row = dlg.intValue ();
        model->setRowCount (row);
    }
}

void fema_analysis::load(string_view data)
{
    const auto arr = QByteArray::fromRawData (data.data (), static_cast<int> (data.size ()));
    auto result = QJsonDocument::fromJson (arr).toVariant ().toMap ();
    auto form = result ["form"].toMap ();
    auto formvalue = result["attribute"].toMap ();
    ui->name_value->setText (formvalue["项目名称"].toString());
    ui->type_value->setText (formvalue["产品类型"].toString());
    ui->responsibility_value->setText (formvalue["过程责任"].toString());
    ui->core_value->setText (formvalue["核心小组"].toString());

    ui->date_value->setText (formvalue["关键日期"].toString());
    ui->number_value->setText (formvalue["FMEA编号"].toString());
    ui->f_date_value->setText (formvalue["FMEA日期"].toString());
    ui->auther_value->setText (formvalue["编织者"].toString());

    model->load (form);
}

void fema_analysis::set_form()
{
    ui->form->verticalHeader()->setDefaultSectionSize(20);
    ui->form->verticalHeader()->setVisible(false);//不显示纵向表头
    ui->form->horizontalHeader()->setVisible(false);//不显示横向表头
    ui->form->setSpan(0,0,2,1);
    ui->form->setSpan(0,1,1,5);
    ui->form->setSpan(0,6,1,4);
    ui->form->setSpan(0,10,1,8);
}

std::string fema_analysis::export_data()
{
    QVariantMap map;
    map ["form"] = model->dump ();
    map ["attribute"] = getvalue();
    return QJsonDocument::fromVariant (map).toJson ().toStdString ();
}

void fema_analysis::set_project_name()
{
    QInputDialog dlg;
    dlg.setWindowTitle ("修改项目名称");
    dlg.setLabelText ("请填写新项目名称");
    dlg.setOkButtonText ("确 定");
    dlg.setCancelButtonText ("取 消");
    dlg.setInputMode (QInputDialog::TextInput);
    //dlg.setIntRange (0, 1000);
    if (dlg.exec () == QDialog::Accepted)
    {
        auto value = dlg.textValue ();
        ui->name_value->setText (value);
    }
}

void fema_analysis::set_type()
{
    QInputDialog dlg;
    dlg.setWindowTitle ("修改产品类型");
    dlg.setLabelText ("请填写新产品类型");
    dlg.setOkButtonText ("确 定");
    dlg.setCancelButtonText ("取 消");
    dlg.setInputMode (QInputDialog::TextInput);
    //dlg.setIntRange (0, 1000);
    if (dlg.exec () == QDialog::Accepted)
    {
        auto value = dlg.textValue ();
        ui->type_value->setText (value);
    }
}

void fema_analysis::set_responsibility()
{
    QInputDialog dlg;
    dlg.setWindowTitle ("修改过程责任");
    dlg.setLabelText ("请填写新过程责任");
    dlg.setOkButtonText ("确 定");
    dlg.setCancelButtonText ("取 消");
    dlg.setInputMode (QInputDialog::TextInput);
    //dlg.setIntRange (0, 1000);
    if (dlg.exec () == QDialog::Accepted)
    {
        auto value = dlg.textValue ();
        ui->responsibility_value->setText (value);
    }
}

void fema_analysis::set_core()
{
    QInputDialog dlg;
    dlg.setWindowTitle ("修改核心小组");
    dlg.setLabelText ("请填写新核心小组");
    dlg.setOkButtonText ("确 定");
    dlg.setCancelButtonText ("取 消");
    dlg.setInputMode (QInputDialog::TextInput);
    //dlg.setIntRange (0, 1000);
    if (dlg.exec () == QDialog::Accepted)
    {
        auto value = dlg.textValue ();
        ui->core_value->setText (value);
    }
}

void fema_analysis::set_date()
{
    QInputDialog dlg;
    dlg.setWindowTitle ("修改关键日期");
    dlg.setLabelText ("请填写新关键日期");
    dlg.setOkButtonText ("确 定");
    dlg.setCancelButtonText ("取 消");
    dlg.setInputMode (QInputDialog::TextInput);
    //dlg.setIntRange (0, 1000);
    if (dlg.exec () == QDialog::Accepted)
    {
        auto value = dlg.textValue ();
        ui->date_value->setText (value);
    }
}

void fema_analysis::set_number()
{
    QInputDialog dlg;
    dlg.setWindowTitle ("修改FMEA编号");
    dlg.setLabelText ("请填写新FMEA编号");
    dlg.setOkButtonText ("确 定");
    dlg.setCancelButtonText ("取 消");
    dlg.setInputMode (QInputDialog::TextInput);
    //dlg.setIntRange (0, 1000);
    if (dlg.exec () == QDialog::Accepted)
    {
        auto value = dlg.textValue ();
        ui->number_value->setText (value);
    }
}

void fema_analysis::set_f_date()
{
    QInputDialog dlg;
    dlg.setWindowTitle ("修改FMEA日期");
    dlg.setLabelText ("请填写新FMEA日期");
    dlg.setOkButtonText ("确 定");
    dlg.setCancelButtonText ("取 消");
    dlg.setInputMode (QInputDialog::TextInput);
    //dlg.setIntRange (0, 1000);
    if (dlg.exec () == QDialog::Accepted)
    {
        auto value = dlg.textValue ();
        ui->f_date_value->setText (value);
    }
}

void fema_analysis::set_auther()
{
    QInputDialog dlg;
    dlg.setWindowTitle ("修改编织者");
    dlg.setLabelText ("请填写新编织者");
    dlg.setOkButtonText ("确 定");
    dlg.setCancelButtonText ("取 消");
    dlg.setInputMode (QInputDialog::TextInput);
    //dlg.setIntRange (0, 1000);
    if (dlg.exec () == QDialog::Accepted)
    {
        auto value = dlg.textValue ();
        ui->auther_value->setText (value);
    }
}

bool fema_analysis::import(string_view view)
{
    auto data = readVaf (view);

    model->setRowCount (static_cast<int>(data.size ()));
    model->clear ();
    for(size_t i = 0; i < data.size(); i++)
    {
        const auto sized_i = static_cast<int> (i);
        qDebug() << data.at (i).name;
        model->setData (model->index(sized_i + 2, 0), QVariant (data.at (i).name), Qt::EditRole);
    }
    return true;
}

QVariantMap fema_analysis::getvalue()
{
    QVariantMap map;

    map ["项目名称"] = ui->name_value->text ();
    map ["产品类型"] = ui->type_value->text ();
    map ["过程责任"] = ui->responsibility_value->text ();
    map ["核心小组"] = ui->core_value->text ();
    map ["关键日期"] = ui->date_value->text ();
    map ["FMEA日期"] = ui->f_date_value->text ();
    map ["FMEA编号"] = ui->number_value->text ();
    map ["编织者"] = ui->auther_value->text ();

    return map;
}

