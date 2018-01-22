#pragma once
#include<QStyledItemDelegate>
#include<base/lang/not_null.h>
#include <set>

class fmea_delegate : public QStyledItemDelegate
{
public:
    fmea_delegate(QObject *parent = null);
    QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    //void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

    ~fmea_delegate () override;
private:
    std::set<std::pair<QString, QString>> editHeader_  =
    {
        {"设计功能要求/作业内容", "设计功能要求/作业内容"},
        {"失效特征","潜在失效模式"},
        {"失效特征","潜在失效起因"},
        {"失效特征","潜在失效影响"},
        {"失效特征","控制预防措施"},
        {"失效特征","探测控制措施"},
        {"行动","建议措施"},
        {"行动","决定措施"},
        {"行动","责任人"},
        {"行动","截止日期"}
    };

    std::set<std::pair<QString, QString>> combo_severnessLevel_Header_ =
    {
        {"行动","严重度（S）"},
        {"评定标准","严重度（S）"},
    };
    std::set<std::pair<QString, QString>> combo_frequency_Header_ =
    {
        {"行动","频度（O）"},
        {"评定标准","频度（O）"},
    };
    std::set<std::pair<QString, QString>> combo_detectionLevel_Header_ =
    {
        {"行动","探测度（D）"},
        {"评定标准","探测度（D）"}
    };

    std::map<int, QString> severnessLevel =
    {
        {1, "无"},
        {2, "很轻微"},
        {3, "轻微"},
        {4, "很低"},
        {5, "低"},
        {6, "中等"},
        {7, "高"},
        {8, "很高"},
        {9, "有警告的严重危害"},
        {10, "无警告的严重危害"}
    };
    std::map<int, QString> frequency =
    {
        {1, "极低：失效不太可能发生,≦0.01个 每1000辆/项目"},
        {2, "低：相对很少发生的失效,≧0.1个 每1000辆/项目"},
        {3, "低：相对很少发生的失效,≧0.5个 每1000辆/项目"},
        {4, "中等：偶然性失效,≧1个  每1000辆/项目"},
        {5, "中等：偶然性失效,≧2个  每1000辆/项目"},
        {6, "中等：偶然性失效,≧5个  每1000辆/项目"},
        {7, "高：经常性失效,≧10个 每1000辆/项目"},
        {8, "高：经常性失效,≧20个 每1000辆/项目"},
        {9, "很高：持续性失效, ≧50个 每1000辆/项目"},
        {10, "很高：持续性失效,≧100个 每1000辆/项目"}
    };
    std::map<int, QString> detectionLevel =
    {
        {1, "几乎肯定"},
        {2, "很多"},
        {3, "多"},
        {4, "中上"},
        {5, "中等"},
        {6, "少"},
        {7, "很少"},
        {8, "极少"},
        {9, "很极少"},
        {10, "绝对不肯定"}
    };
};


