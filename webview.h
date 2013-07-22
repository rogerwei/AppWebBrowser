#ifndef WEBVIEW_H
#define WEBVIEW_H

#include <QWebView>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE
class NetworkAccessManager;

class WebView : public QWebView
{
    Q_OBJECT
public:
    explicit WebView(QWidget *parent = 0);
    
    void loadUrl(const QString &url);

signals:
    
public slots:
    
private:
    QWebPage *m_webPage;
    NetworkAccessManager* s_networkAccessManager;
    QUrl m_curentUrl;
};

QT_END_HEADER

QT_END_NAMESPACE
#endif // WEBVIEW_H
