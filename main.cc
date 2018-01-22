#include "fmea_main.h"
#include <QApplication>
#include <QApplication>
#include <boost/filesystem.hpp>
#include <base/io/file/file.hpp>
#include <boost/range/adaptors.hpp>
#include <QDebug>
#include <QStyleFactory>
#include "verification/verification.h"
#include <QTimer>

void set_style ()
{
    using namespace boost::filesystem;

    auto rng = boost::make_iterator_range (directory_iterator ("."), directory_iterator ());

    std::string qss;
    for (auto & it : rng)
    {
        if (it.path ().extension ().string () == ".css")
        {
            auto res = file::read_all (it.path ().string ().data ());
            if (res)
            {
                qss += res.value ();
            }
        }
    }
    qApp->setStyleSheet (QString::fromStdString (qss));
    qApp->setFont (QFont ("宋体", 11));
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(!verification_process())
    {
        return -1;
    }

    set_style ();
    fmea_main w;
    w.resize (1366, 768);
    w.show();

    QTimer timer;
    timer.setInterval (1000);
    timer.setSingleShot (true);
    QObject::connect (&timer, &QTimer::timeout, [&] { check_date (); timer.start (); });
    timer.start ();

    return a.exec();
}
