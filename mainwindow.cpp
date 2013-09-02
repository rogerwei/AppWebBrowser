#include "mainwindow.h"

#include "webview.h"
#include <QHBoxLayout>
#include <QDir>
#include <QDebug>

QT_BEGIN_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      viewer_(new WebView(this))
{
    QWidget* widget = new QWidget(this);

    QHBoxLayout* layout = new QHBoxLayout(widget);
    layout->setMargin(1);

    viewer_->loadUrl(("http://www.spark56.com"));
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

QT_END_NAMESPACE
