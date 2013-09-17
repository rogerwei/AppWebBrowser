#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::addLibraryPath("./plugins");


    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));

    MainWindow w;
    w.load();
    w.show();
    
    return a.exec();
}
