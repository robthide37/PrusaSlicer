#include "PrinterWebView.hpp"

#include "I18N.hpp"
#include "slic3r/GUI/PrinterWebView.hpp"
#include "slic3r/GUI/wxExtensions.hpp"
#include "slic3r/GUI/GUI_App.hpp"
#include "slic3r/GUI/MainFrame.hpp"
#include "libslic3r_version.h"

#include <wx/sizer.h>
#include <wx/string.h>
#include <wx/toolbar.h>
#include <wx/textdlg.h>
#include <wx/webview.h>

namespace pt = boost::property_tree;

namespace Slic3r { namespace GUI {

}}