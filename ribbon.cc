#include "ribbon.h"
#include <QHBoxLayout>
#include <base/lang/scope.hpp>
#include <base/lang/move.hpp>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QMenu>
#include <QApplication>
#include <QFrame>
#include <QLineEdit>
#include <QTabBar>
#include <QWidgetAction>
#include <base/io/file/file.hpp>
#include <variant>
#include <QButtonGroup>
#include <QDebug>

using namespace std;

ribbon::ribbon(QWidget *parent)
    :QTabWidget (parent)
{
    this->setTabBar (new ribbon_bar (this));

    setMaximumHeight (130);
    setMinimumHeight (130);
    setup_ui ();
}

void ribbon::add_tab(gsl::span<ui_group> group, const QString &name)
{
    addTab (make_tab(group).release (), name);
}

std::unique_ptr<ribbon_tool> ribbon::make_button(const QPixmap &raw_icon, const QString &text)
{
    const auto icon = raw_icon.scaled (button_size);
    auto button = make_unique<ribbon_tool> ();

    button->setIconSize (icon.size ());
    button->setIcon (icon);
    button->setText (text);
    button->setObjectName (text);
    button->setToolButtonStyle (Qt::ToolButtonTextUnderIcon);
    button->setAutoRaise (true);

    return button;
}

std::unique_ptr<ribbon_tool> ribbon::make_icon(const QPixmap &icon, const QString &text)
{
    auto button = make_unique<ribbon_tool> ();

    button->setIconSize (icon_size);
    button->setIcon (icon);
    button->setText (text);
    button->setObjectName (text);
    button->setToolTip (text);

    button->setCheckable (true);

    return button;
}


void ribbon::setup_ui()
{
    setup_menu ();

    //std::array<ui_group, 3> tab_content;

    //button_cell b;

    //b.add ("按钮1", QPixmap ("png/导出.png"));
    //b.add ("按钮2", QPixmap ("png/导出.png"));
    //b.add ("按钮3", QPixmap ("png/导出.png"));
    //b.set_title ("第A类");
    //tab_content.at (0) = ::move (b);


    //b.add ("按钮1", QPixmap ("png/导出.png"));
    //b.add ("按钮2", QPixmap ("png/导出.png"));
    //b.set_title ("第B类");
    //tab_content.at (1) = ::move (b);



    //ribbon_tool* jiagong = null, * yuancailiao = null, * chanchengpin = null;
    //frame_group c;
    //c.add (tr ("加工"), QPixmap ("png/加工.png"), jiagong);
    //c.add (tr ("原材料"), QPixmap ("png/原材料.png"), yuancailiao);
    //c.add (tr ("产成品"), QPixmap ("png/产成品.png"), chanchengpin);
    //c.set_title ("图形绘画");

    //tab_content.at (2) = ::move (c);

    //this->addTab (make_tab (tab_content).release (), "测试");

    //auto group = new QButtonGroup (this);
    //group->addButton (jiagong);
    //group->addButton (yuancailiao);
    //group->addButton (chanchengpin);

    //using func_type = void (QButtonGroup::*) (QAbstractButton *);
    //auto func = func_type {&QButtonGroup::buttonClicked};
    //connect (group, func, [] (auto&&o){ qDebug () << o->objectName (); });
}


unique_ptr<QWidgetAction> make_action (const QPixmap & pix, const QString & text, QWidget * parent = nullptr)
{
    auto action = make_unique<QWidgetAction> (parent);
    action->setDefaultWidget (new ribbon_menu_item(pix, text, parent));

    return action;
}

void ribbon::setup_menu()
{
    auto file = new ribbon_button ("  文件", this);
    auto menu = new ribbon_menu (file);
    file->setMenu (menu);

    auto action =  make_action (QPixmap ("png/新建.png"), "新建");
    connect (action.get (), &QAction::triggered, this, &ribbon::file_new);
    menu->addAction (action.release ());

    action =  make_action (QPixmap ("png/打开.png"), "打开");
    connect (action.get (), &QAction::triggered, this, &ribbon::file_open);
    menu->addAction (action.release ());

    action =  make_action (QPixmap ("png/保存.png"), "保存");
    connect (action.get (), &QAction::triggered, this, &ribbon::file_save);
    connect (this, &ribbon::set_enabled, action.get(), &QAction::setEnabled);
    menu->addAction (action.release ());

    action =  make_action (QPixmap ("png/另存为.png"), "另存为");
    connect (action.get (), &QAction::triggered, this, &ribbon::file_saveas);
    connect (this, &ribbon::set_enabled, action.get(), &QAction::setEnabled);
    menu->addAction (action.release ());

    action =  make_action (QPixmap ("png/退出.png"), "退出");
    connect (action.get (), &QAction::triggered, this, &ribbon::file_exit);
    menu->addAction (action.release ());

    menu->setContentsMargins(10, 0, 0, 0);
}

std::unique_ptr<QWidget> ribbon::make_tab(gsl::span<ui_group> ui)
{
    auto ret = make_unique<QWidget> ();

    auto layout = make_unique<QHBoxLayout> ();

    layout->setContentsMargins (1, 1, 1, 1);
    layout->setSpacing (1);
    for (auto & it : ui)
    {
        if (it.index () == 0)
        {
            auto g = std::move (get<0> (it));
            setup_button_block (ret.get (), layout.get (), std::move (g));
        }
        else if (it.index () == 1)
        {
            auto g = std::move (get<1> (it));
            setup_icon_block (ret.get (), layout.get (), std::move (g));
        }
    }

    layout->addItem (new QSpacerItem (0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    ret->setLayout (layout.release ());
    return ret;
}

void ribbon::setup_button_block (QWidget * ret, QBoxLayout * layout, button_cell g)
{
    auto block_layout = make_unique<QVBoxLayout> ();
    block_layout->setContentsMargins (1, 1, 1, 1);
    block_layout->setSpacing (1);

    auto upper_layout = make_unique<QHBoxLayout> ();
    upper_layout->setSpacing(10);
    upper_layout->setContentsMargins(10, 0, 10, 0);

    for (auto & it : g)
    {
        auto btn = std::move (it.first);
        if (it.second != nullptr)
        {
            (it.second) (btn.get ());
        }

        upper_layout->addWidget (btn.release ());
    }

    block_layout->addLayout (upper_layout.release ());
    auto label = new QLabel (g.title ());
    label->setAlignment (Qt::AlignHCenter | Qt::AlignBottom);
    block_layout->addWidget (label);
    layout->addLayout (block_layout.release (), 0);

    auto line = new QFrame (ret);
    line->setFrameShape (QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
    layout->addWidget (line);

}

void ribbon::setup_icon_block(QWidget * ret, QBoxLayout * layout, frame_group g)
{
    auto block_layout = make_unique<QVBoxLayout> ();
    block_layout->setContentsMargins (1, 1, 1, 1);
    block_layout->setSpacing (1);

    auto frame = new QFrame (ret);
    frame->setFrameShape(QFrame::StyledPanel);
    frame->setFrameShadow(QFrame::Raised);

    auto frame_layout = make_unique<QHBoxLayout> ();
    frame_layout->setContentsMargins(1, 1, 1, 1);
    frame_layout->setSpacing(1);

    for (auto & it : g)
    {
        auto btn = ::move (it.first);
        if (it.second != nullptr)
        {
            (it.second) (btn.get ());
        }
        frame_layout->addWidget (btn.release ());
    }
    frame->setLayout (frame_layout.release ());
    block_layout->addWidget (frame);


    auto label = new QLabel (g.title ());
    label->setAlignment (Qt::AlignHCenter | Qt::AlignBottom);
    block_layout->addWidget (label);
    layout->addLayout (block_layout.release ());

    auto line = new QFrame (ret);
    line->setFrameShape (QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
    layout->addWidget (line);
}
