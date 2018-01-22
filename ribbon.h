#pragma once
#include <QTabWidget>
#include <base/lang/not_null.h>
#include <memory>
#include <QToolButton>
#include <QPushButton>
#include <QTabBar>
#include <QHBoxLayout>
#include <QLabel>
#include <QStyleOption>
#include <QLineEdit>
#include <QPainter>
#include <QMenu>
#include <gsl/span>
#include <variant>
#include <functional>

class ribbon_tool;
class ribbon_button;

class ribbon : public QTabWidget
{
    Q_OBJECT
signals:
    void file_new ();
    void file_open ();
    void file_save ();
    void file_saveas ();
    void file_exit ();
    void set_enabled(bool);
protected:
    using button_init = std::function<void (ribbon_tool*)>;

    struct button_cell
    {
        void add (QString text, const QPixmap & pix, ribbon_tool *& member)
        {
            auto init_code = [member = &member] (ribbon_tool * tool) { *member = tool; };
            auto tool = make_button (pix, text);
            data_.emplace_back (std::move (tool), init_code);
        }
        void add (QString text, const QPixmap & pix, button_init init_code = nullptr)
        {
            auto tool = make_button (pix, text);
            data_.emplace_back (std::move (tool), init_code);
        }
        void add (std::unique_ptr<ribbon_tool> tool, button_init init_code = nullptr)
        {
            data_.emplace_back (std::move (tool), init_code);
        }
        QString title () const noexcept { return title_; }
        void set_title (const QString & title) noexcept { title_ = title; }
        auto begin () const noexcept { return data_.begin (); }
        auto begin () noexcept { return data_.begin (); }
        auto end () const noexcept { return data_.end (); }
        auto end () noexcept { return data_.end (); }
    private:
        std::vector<std::pair<std::unique_ptr<ribbon_tool>, button_init>> data_;
        QString title_;
    };

    struct frame_group
    {
        void add (QString text, const QPixmap & pix, ribbon_tool *& member)
        {
            auto init_code = [member = &member] (ribbon_tool * tool) { *member = tool; };
            add (text, pix, init_code);
        }
        void add (QString text, const QPixmap & pix, button_init init_code = nullptr)
        {
            auto tool = make_icon (pix, text);
            data_.emplace_back (std::move (tool), init_code);
        }
        QString title () const noexcept { return title_; }
        void set_title (const QString & title) noexcept { title_ = title; }

        auto begin () const noexcept { return data_.begin (); }
        auto begin () noexcept { return data_.begin (); }
        auto end () const noexcept { return data_.end (); }
        auto end () noexcept { return data_.end (); }

    private:
        QString title_;
        std::vector<std::pair<std::unique_ptr<ribbon_tool>, button_init>> data_;
    };
    using ui_group = std::variant<button_cell, frame_group>;
public:
    void add_tab(gsl::span<ui_group> group, const QString &name);
    ribbon (QWidget * parent = nullptr);
private:
    static std::unique_ptr<ribbon_tool> make_button (const QPixmap & icon, const QString & text);
    static std::unique_ptr<ribbon_tool> make_icon (const QPixmap & icon, const QString & text);

    void setup_ui ();
    void setup_menu ();
    std::unique_ptr<QLayout> setup_layout ();
    std::unique_ptr<QWidget> make_tab (gsl::span<ui_group> ui);
    static void setup_button_block (QWidget * ret, QBoxLayout *layout, button_cell g);
    static void setup_icon_block (QWidget * ret, QBoxLayout * layout, frame_group g);

    static constexpr auto button_size = QSize (40, 40);
    static constexpr auto icon_size = QSize (32, 32);
};

class ribbon_button : public QPushButton
{
    Q_OBJECT
public:
    template<typename ... Args>
    ribbon_button (Args && ... p) : QPushButton (std::forward<Args> (p)...) {}
};

class ribbon_menu : public QMenu
{
    Q_OBJECT
public:
    template<typename ... Args>
    ribbon_menu (Args && ... p) : QMenu (std::forward<Args> (p)...) {}
};

class ribbon_tool : public QToolButton
{
    Q_OBJECT
public:
    template<typename ... Args>
    ribbon_tool (Args && ... p) : QToolButton (std::forward<Args> (p)...) {}
};

class ribbon_bar : public QTabBar
{
    Q_OBJECT
public:
    ribbon_bar (QWidget * parent = nullptr) : QTabBar (parent) {}
};

class ribbon_edit : public QLineEdit
{
    Q_OBJECT
public:
    template<typename ... Args>
    ribbon_edit (Args && ... p) : QLineEdit (std::forward<Args> (p)...) {}
};

class layout_horizontal : public QHBoxLayout
{
    Q_OBJECT
public:
    template<typename ... Args>
    layout_horizontal (Args && ... p) : QHBoxLayout (std::forward<Args> (p)...) {}
    void set_w (int w) { w_ = w; }
protected:
    QSize maximumSize () const override
    {
        if (w_ == -1)
        {
            return QHBoxLayout::maximumSize ();
        }
        else
        {
            return QSize (w_, QHBoxLayout::maximumSize ().height ());
        }
    }
    QSize minimumSize () const override
    {
        if (w_ == -1)
        {
            return QHBoxLayout::minimumSize ();
        }
        else
        {
            return QSize (w_, QHBoxLayout::minimumSize ().height ());
        }
    }
private:
    int w_ = -1;
};



class ribbon_menu_item : public QWidget
{
    Q_OBJECT
public:
    ribbon_menu_item(const QPixmap& pix, const QString& text, QWidget *parent = 0)
        :QWidget (parent)
    {
        QLabel* label_icon = new QLabel(this);
        label_icon->setFixedSize(24, 24);
        label_icon->setScaledContents(true);
        label_icon->setPixmap(pix);

        QLabel* label_text = new QLabel(text,this);
        label_text->setAlignment (Qt::AlignLeft | Qt::AlignVCenter);

        QHBoxLayout* layout = new QHBoxLayout;
        layout->setContentsMargins(1, 1, 1, 1);
        layout->setSpacing(1);
        layout->addWidget(label_icon);
        layout->addWidget(label_text);
        setLayout(layout);

        setFixedWidth(100);
        setFixedHeight (32);
    }
    ~ribbon_menu_item()
    {}

protected:
    void paintEvent(QPaintEvent*) override {
        QStyleOption opt;
        opt.init(this);
        QPainter p(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    }

private:

};




