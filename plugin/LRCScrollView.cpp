#ifndef LMMS_PLUGINS_LRCSCROLL_LRCSCROLLVIEW_CPP
#define LMMS_PLUGINS_LRCSCROLL_LRCSCROLLVIEW_CPP

#include "LRCScroll.h"
#include "LRCScrollView.h"

namespace lmms::gui
{
    using lmms::LRCScroll;
    
    LRCScrollView::LRCScrollView(LRCScroll* plugin)
		: ToolPluginView(plugin),
		m_plugin(plugin)
	{
    }

}


#endif LMMS_PLUGINS_LRCSCROLL_LRCSCROLLVIEW_CPP