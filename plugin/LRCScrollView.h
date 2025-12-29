/**
 * LRCScrollView.h
 * (c) 2026 Bimal Poudel <@anytizer:github>
 */

#ifndef LMMS_PLUGINS_LRCSCROLL_LRCSCROLLVIEW_H
#define LMMS_PLUGINS_LRCSCROLL_LRCSCROLLVIEW_H

#include "LRCScroll.h"
#include "LRCScrollView.h"

#include "ToolPluginView.h"

#include <QHBoxLayout>

namespace lmms
{
    namespace gui
    {
        class LRCScrollView: public ToolPluginView
        {
            private:
                Q_OBJECT

                LRCScroll* m_plugin;
                QHBoxLayout* layout = new QHBoxLayout();

                void clearLayout();
            
            public:
                LRCScrollView(LRCScroll* plugin);
                ~LRCScrollView();
        };
    }
}

#endif // LMMS_PLUGINS_LRCSCROLL_LRCSCROLLVIEW_H