#ifndef slic3r_HelloWebView_hpp_
#define slic3r_HelloWebView_hpp_

#include <wx/wx.h>
#include <WebView2.h>
#include <wil/com.h>
#include <wx/webview.h>
#include <wx/msw/webview_edge.h>
#include <wx/msw/webview_ie.h>

namespace Slic3r { namespace GUI {

class WebViewPanel : public wxPanel
{
public:
    WebViewPanel(wxWindow *parent, const wxString &initialUrl);
    ~WebViewPanel();

    wxWebView *CreateWebView(wxWindow* parent, const wxString &initialUrl);
    wxWebView *m_webView;

private:

};
}
}     // namespace Slic3r::GUI
#endif // HelloWebView.hpp