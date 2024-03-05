#ifndef slic3r_GUI_WebView_hpp_
#define slic3r_GUI_WebView_hpp_

#include <wx/wx.h>
#include <wx/webview.h>


namespace Slic3r {

class WebViewPanel : public wxFrame
{
public:
    WebViewPanel(wxWindow* parent);
    WebViewPanel();

private:
    wxWebView *webView;
};
} // namespace WebViewExample

#endif // WEBVIEW_EXAMPLE_HPP