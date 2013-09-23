#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::addLibraryPath("./plugins");

    QFontDatabase::addApplicationFont(QStringLiteral("宋体"));
    QFontDatabase::addApplicationFont(QStringLiteral("微软雅黑"));
    QFontDatabase::addApplicationFont(QStringLiteral("幼圆"));

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));

    MainWindow w;
    w.load();
    w.show();
    
    return a.exec();
}
