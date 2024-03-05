#include "MyWebView.hpp"

wxBEGIN_EVENT_TABLE(MyWebView, wxPanel) EVT_SIZE(MyWebView::OnSize) wxEND_EVENT_TABLE()

    MyWebView::MyWebView(wxWindow *parent, const wxString &initialUrl, const wxPoint &pos, const wxSize &size)
    : wxPanel(parent, wxID_ANY, pos, size)
{
    CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);

    CreateCoreWebView2Environment(
        Callback<ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler>(
            [this, initialUrl](HRESULT result, ICoreWebView2Environment *env) -> HRESULT {
                if (SUCCEEDED(result)) {
                    env->CreateCoreWebView2Controller(
                        GetHWND(),
                        Callback<ICoreWebView2CreateCoreWebView2ControllerCompletedHandler>(
                            [this, initialUrl](HRESULT result, ICoreWebView2Controller *controller) -> HRESULT {
                                if (SUCCEEDED(result)) {
                                    m_controller = controller;
                                    m_controller->get_CoreWebView2(&m_webView);
                                    m_webView->put_IsVisible(TRUE);
                                    Resize(size.GetWidth(), size.GetHeight());
                                    Navigate(initialUrl);
                                }
                                return S_OK;
                            })
                            .Get());
                }
                return S_OK;
            })
            .Get());
}

MyWebView::~MyWebView() { CoUninitialize(); }

void MyWebView::Navigate(const wxString &url)
{
    if (m_webView) {
        m_webView->Navigate(url.wc_str());
    }
}

void MyWebView::Resize(int width, int height)
{
    if (m_controller) {
        m_controller->put_Bounds({0, 0, width, height});
    }
}

void MyWebView::OnSize(wxSizeEvent &event)
{
    wxSize size = event.GetSize();
    Resize(size.GetWidth(), size.GetHeight());
    event.Skip();
}
