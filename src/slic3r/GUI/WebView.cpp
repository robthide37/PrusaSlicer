#include <wx/wx.h>
#include <wx/webview.h>


namespace Slic3r {

class WebViewPanel : public wxFrame
{
public:
    WebViewPanel() : wxFrame(nullptr, wxID_ANY, "WebView example", wxDefaultPosition, {1024, 768}) {}

private:
    wxWebView *webView = wxWebView::New(this,
                                        wxID_ANY,
                                        "https://docs.wxwidgets.org/latest/",
                                        wxDefaultPosition,
                                        wxDefaultSize,
                                        "webkit2",
                                        0,
                                        "myWebView");
};

/*class WebViewPanel : public wxFrame
{
public:
    WebViewPanel() : wxFrame(nullptr, wxID_ANY, "WebView example", wxDefaultPosition, {1024, 768})
    {
        webView = wxWebView::New(this,
                                 wxID_ANY,
                                 "https://docs.wxwidgets.org/latest/",
                                 wxDefaultPosition,
                                 wxDefaultSize,
                                 "webkit2",
                                 0,
                                 "myWebView");
    }

private:
    wxWebView* webView;
};*/

class Application : public wxApp
{
    bool OnInit() override { return (new WebViewPanel)->Show(); }
};
} // namespace WebViewExample