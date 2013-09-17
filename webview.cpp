#include "webview.h"
#include "cookiejar.h"
#include "networkaccessmanager.h"

#include <QWebSecurityOrigin>
#include <QWebFrame>

QT_BEGIN_NAMESPACE

WebView::WebView(QWidget *parent) :
    QWebView(parent),
    m_webPage(new QWebPage(this)),
    s_networkAccessManager(new NetworkAccessManager())
{
    s_networkAccessManager->setCookieJar(new CookieJar);
    m_webPage->setNetworkAccessManager(s_networkAccessManager);
    setPage(m_webPage);
}

void WebView::loadUrl(const QString &url)
{
    m_curentUrl = QUrl(url);

    load(m_curentUrl);
}

QT_END_NAMESPACE
