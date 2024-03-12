#ifndef slic3r_PrinterWebView_hpp_
#define slic3r_PrinterWebView_hpp_

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

    wxWebView *m_webView;

private:
    wxWebView *CreateWebView(wxWindow *parent, const wxString &initialUrl);
    // TODO: Create Dynamical API Key function

};
}
}     // namespace Slic3r::GUI
#endif // slic3r_PrinterWebView_hpp