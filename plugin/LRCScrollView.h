/**
 * LRCScrollView.h
 * (c) 2026 Bimal Poudel <@anytizer:github>
 */

#ifndef LMMS_PLUGINS_LRCSCROLL_LRCSCROLLVIEW_H
#define LMMS_PLUGINS_LRCSCROLL_LRCSCROLLVIEW_H

#include "LRCScroll.h"
#include "LRCScrollView.h"
#include "TimestampEditor.h"

#include "ToolPluginView.h"

#include <QHBoxLayout>
#include <QCloseEvent>

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
                
                TimestampEditor* tse = new TimestampEditor(nullptr);

                void clearLayout();
            
            public:
                LRCScrollView(LRCScroll* plugin);
                ~LRCScrollView();
                void setFramed(bool tf);
            
            protected:
                void closeEvent(QCloseEvent* event) override;
                void focusInEvent(QFocusEvent* event) override;
                void focusOutEvent(QFocusEvent* event) override;
                void changeEvent(QEvent *event) override;
                void keyPressEvent(QKeyEvent* event) override;
        };
    }
}

#endif // LMMS_PLUGINS_LRCSCROLL_LRCSCROLLVIEW_H