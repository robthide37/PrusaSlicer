// Webview Panel created by Steve.
#include "PrinterWebView.hpp"

#include "slic3r/GUI/wxExtensions.hpp"
#include "slic3r/GUI/GUI_App.hpp"
#include "slic3r/GUI/MainFrame.hpp"
#include "libslic3r_version.h"

#include <wx/sizer.h>
#include <wx/string.h>
#include <wx/toolbar.h>
#include <wx/textdlg.h>

#include "CR3DWebView.hpp"
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
    sizer->Add(m_webView, 1, wxEXPAND);
}

WebViewPanel::~WebViewPanel()
{

}

wxWebView* WebViewPanel::CreateWebView(wxWindow* parent, const wxString& initialUrl) {

    //wxWebViewIE::MSWSetEmulationLevel(wxWEBVIEWIE_EMU_IE11);
    wxWebView *webview = WebView::CreateWebView(parent, initialUrl);

    webview->LoadURL(initialUrl);
    webview->EnableContextMenu(true);
    webview->EnableAccessToDevTools(true);

    return webview;
}


} // namespace GUI

} // namespace Slic3r