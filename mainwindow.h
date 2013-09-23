#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_HEADER
QT_BEGIN_NAMESPACE

class WebView;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void load();

private:
    QString getUrl();
    void setShortCut();

    WebView* viewer_;
};

QT_END_NAMESPACE
QT_END_HEADER
#endif // MAINWINDOW_H
