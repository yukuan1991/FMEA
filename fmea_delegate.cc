#include "fmea_delegate.h"
#include <QComboBox>
#include <QDebug>
#include <QStyleOptionViewItem>
#include <QStringListModel>
#include <base/lang/not_null.h>
#include <QLineEdit>
#include <assert.h>
#include <boost/range/algorithm/find_first_of.hpp>


using std::begin;
using std::end;
using boost::find_first_of;

fmea_delegate::fmea_delegate(QObject *parent)
    :QStyledItemDelegate (parent)
{

}

QWidget *fmea_delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    const auto col = index.column ();
    auto model = index.model ();

    const auto firstHeader = model->data (model->index (0, col)).toString ();
    const auto secondHeader = model->data (model->index (1, col)).toString ();

    const auto doubleHeader = std::make_pair (firstHeader, secondHeader);

    if (editHeader_.find (doubleHeader) != end (editHeader_))
    {
        return new QLineEdit (parent);
    }
    else if (combo_severnessLevel_Header_.find (doubleHeader) != end (combo_severnessLevel_Header_))
    {
        QStringList oneToTen;
        for (int i = 1; i <= 10; i ++)
        {
            oneToTen << QString::number (i) + " " + severnessLevel.at (i);
        }
        auto combo = new QComboBox (parent);
        combo->addItems (oneToTen);
        return combo;
    }
    else if (combo_frequency_Header_.find (doubleHeader) != end (combo_frequency_Header_))
    {
        QStringList oneToTen;
        for (int i = 1; i <= 10; i ++)
        {
            oneToTen << QString::number (i) + " " + frequency.at (i);
        }
        auto combo = new QComboBox (parent);
        combo->addItems (oneToTen);
        return combo;
    }
    else if (combo_detectionLevel_Header_.find (doubleHeader) != end (combo_detectionLevel_Header_))
    {
        QStringList oneToTen;
        for (int i = 1; i <= 10; i ++)
        {
            oneToTen << QString::number (i) + " " + detectionLevel.at (i);
        }
        auto combo = new QComboBox (parent);
        combo->addItems (oneToTen);
        return combo;
    }

    return null;
}



void fmea_delegate::setEditorData(QWidget *editor, const QModelIndex &index) const//编辑开始之前调用
{
    const auto col = index.column ();
    auto model = index.model ();

    const auto firstHeader = model->data (model->index (0, col)).toString ();
    const auto secondHeader = model->data (model->index (1, col)).toString ();

    const auto doubleHeader = std::make_pair (firstHeader, secondHeader);

    if (editHeader_.find (doubleHeader) != end (editHeader_))
    {
        auto edit = dynamic_cast<QLineEdit*> (editor); assert (edit);
        edit->setText (index.data ().toString ());
    }
    else if (combo_severnessLevel_Header_.find (doubleHeader) != end (combo_severnessLevel_Header_) or
             combo_frequency_Header_.find (doubleHeader) != end (combo_frequency_Header_) or
             combo_detectionLevel_Header_.find (doubleHeader) != end (combo_detectionLevel_Header_))
    {
        auto combo = dynamic_cast<QComboBox*> (editor); assert (combo);
        const auto text = index.data ().toString ();

        if (not text.isEmpty ())
        {
            combo->setCurrentText (text);
        }
    }
}

void fmea_delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const//编辑之后调用
{
    const auto col = index.column ();
    const auto firstHeader = model->data (model->index (0, col)).toString ();
    const auto secondHeader = model->data (model->index (1, col)).toString ();

    const auto doubleHeader = std::make_pair (firstHeader, secondHeader);

    if (editHeader_.find (doubleHeader) != end (editHeader_))
    {
        const auto edit = dynamic_cast<QLineEdit*>(editor); assert (edit);
        model->setData (index, edit->text ());
    }
    else if (combo_severnessLevel_Header_.find (doubleHeader) != end (combo_severnessLevel_Header_) or
             combo_frequency_Header_.find (doubleHeader) != end (combo_frequency_Header_) or
             combo_detectionLevel_Header_.find (doubleHeader) != end (combo_detectionLevel_Header_))
    {
        const auto combo = dynamic_cast<QComboBox*>(editor); assert (combo);
        model->setData (index, combo->currentText ());
    }
}


fmea_delegate::~fmea_delegate()
{

}
