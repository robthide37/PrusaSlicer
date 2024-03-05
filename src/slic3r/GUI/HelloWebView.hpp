#include <wx/wx.h>
#include <WebView2.h>
#include <wil/com.h>

class MyWebView : public wxPanel
{
public:
    MyWebView(wxWindow *      parent,
              const wxString &initialUrl,
              const wxPoint & pos  = wxDefaultPosition,
              const wxSize &  size = wxDefaultSize);
    ~MyWebView();

    void Navigate(const wxString &url);
    void Resize(int width, int height);

private:
    void OnSize(wxSizeEvent &event);

    wil::com_ptr<ICoreWebView2Controller> m_controller;
    wil::com_ptr<ICoreWebView2>           m_webView;

    wxDECLARE_EVENT_TABLE();
};
