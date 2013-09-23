#include "mainwindow.h"

#include "webview.h"
#include <QHBoxLayout>
#include <QDebug>
#include <QSettings>
#include <QAction>
#include <QCoreApplication>

QT_BEGIN_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      viewer_(new WebView(this))
{
    QWebSettings *settings = QWebSettings::globalSettings();
    settings->setAttribute(QWebSettings::PluginsEnabled, true);//
    settings->setAttribute(QWebSettings::JavascriptEnabled, true);//JavaScript
    QWidget* widget = new QWidget(this);
    QHBoxLayout* layout = new QHBoxLayout(widget);
    layout->setMargin(1);
    layout->addWidget(viewer_);

    setWindowTitle(QStringLiteral("星火物流V2.1"));
    setWindowIcon(QIcon(":/images/res/favicon.ico"));
    viewer_->setFocus();

    setShortCut();
    setCentralWidget(widget);
    showMaximized();
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::load()
{
    viewer_->loadUrl("http://www.spark56.com/app/login.do");
}

const QString appGroup = "app";
const QString keyUrl = "url";

QString MainWindow::getUrl()
{
    QSettings setting(QCoreApplication::applicationDirPath()+ "/spark56.ini", QSettings::IniFormat,this);
    setting.beginGroup(appGroup);
    QString url = setting.value(keyUrl).toString();
    setting.endGroup();
    return url;
}

void MainWindow::setShortCut()
{
    QAction* action = new QAction(parent());
    action->setShortcut(QKeySequence::Refresh);
    connect(action, SIGNAL(triggered()), viewer_, SLOT(reload()));
    this->addAction(action);
}
QT_END_NAMESPACE
