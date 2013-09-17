#include "mainwindow.h"

#include "webview.h"
#include <QHBoxLayout>
#include <QDir>
#include <QDebug>
#include <QNetworkProxyFactory>
#include <QSettings>
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

    //viewer_->loadUrl(("http://www.spark56.com"));
    //viewer_->loadUrl("http://v.youku.com/v_playlist/f16675792o1p1.html");
    //viewer_->loadUrl("http://www.spark56.com/app/index.do");
    layout->addWidget(viewer_);

    setWindowTitle(QStringLiteral("星火物流V2.0"));
    setWindowIcon(QIcon(":/images/res/favicon.ico"));
    viewer_->setFocus();
    setCentralWidget(widget);
    showMaximized();
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::load()
{
    QString url = getUrl();
    viewer_->loadUrl(url);
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

QT_END_NAMESPACE
