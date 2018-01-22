#pragma once
#include <QAbstractTableModel>
#include <base/lang/not_null.h>
#include <QVariantList>
#include <optional>

class fmea_model : public QAbstractTableModel
{
public:
    fmea_model(QObject *parent = null);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant titleData (const QModelIndex & index) const;
    QVariant contentData (const QModelIndex & index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    QVariantMap dump() const;
    void load (QVariantMap map);

    //QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    void clear ();

    Qt::ItemFlags flags (const QModelIndex & index) const override;
    ~fmea_model () override;
    void setRowCount (int newRow);
    static std::optional<int> handleString(const QString &str);
private:

    std::vector<std::pair<QString, QString>> header_  =
    {
        {"设计功能要求/作业内容", "设计功能要求/作业内容"},
        {"失效特征","潜在失效模式"},
        {"失效特征","潜在失效起因"},
        {"失效特征","潜在失效影响"},
        {"失效特征","控制预防措施"},
        {"失效特征","探测控制措施"},
        {"评定标准","严重度（S）"},
        {"评定标准","频度（O）"},
        {"评定标准","探测度（D）"},
        {"评定标准","风险顺序数（RPN）"},
        {"行动","建议措施"},
        {"行动","决定措施"},
        {"行动","责任人"},
        {"行动","截止日期"},
        {"行动","严重度（S）"},
        {"行动","频度（O）"},
        {"行动","探测度（D）"},
        {"行动","风险顺序数（RPN）"}
    };
    QString calculatedHeaderPrefix = "风险顺序数";

    QVariantMap data_;


    int rows = 0;
};


