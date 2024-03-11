// Webview Panel created by Steve.
#include "HelloWebView.hpp"
#include <wx/webview.h>
#include <wx/msw/webview_edge.h>
#include <wx/msw/webview_ie.h>
#include <WebView2.h>


namespace Slic3r {
namespace GUI {

WebViewPanel::WebViewPanel(wxWindow *parent, const wxString &initialUrl) : wxPanel(parent, wxID_ANY)
{

    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);

    m_webView = CreateWebView(parent, initialUrl);
    sizer->Add(m_webView, 1, wxEXPAND | wxALL, 5);
}

WebViewPanel::~WebViewPanel()
{

}

wxWebView* WebViewPanel::CreateWebView(wxWindow* parent, const wxString& initialUrl) {

    wxWebViewIE::MSWSetEmulationLevel(wxWEBVIEWIE_EMU_IE10);
    wxWebView *webview = wxWebView::New(parent, wxID_ANY, initialUrl, wxDefaultPosition, wxDefaultSize,
                                        wxWebViewBackendIE);

    webview->LoadURL(initialUrl);
    webview->EnableContextMenu(true);
    webview->EnableAccessToDevTools(true);

    return webview;

}


} // namespace GUI

} // namespace Slic3r