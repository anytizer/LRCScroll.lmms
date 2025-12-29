#ifndef LMMS_PLUGINS_LRCSCROLL_LRCSCROLLVIEW_H
#define LMMS_PLUGINS_LRCSCROLL_LRCSCROLLVIEW_H

#include "LRCScrollView.h"
#include "LRCScroll.h"

namespace lmms::gui
{
    using lmms::LRCScroll;
    
    class LRCScrollView: public ToolPluginView
    {
        private:
			Q_OBJECT

			LRCScroll* m_plugin;
        
        public:
            LRCScrollView(LRCScroll* plugin);
    };
}

#endif // LMMS_PLUGINS_LRCSCROLL_LRCSCROLLVIEW_H