/**
 * LRCScrollView.h
 * (c) 2026 Bimal Poudel <@anytizer:github>
 */

#ifndef LMMS_PLUGINS_LRCSCROLL_LRCSCROLLVIEW_H
#define LMMS_PLUGINS_LRCSCROLL_LRCSCROLLVIEW_H

#include "LRCScroll.h"
#include "LRCScrollView.h"
#include "VerticalMarquee.h"
#include "TimestampEditor.h"

#include "ToolPluginView.h"

#include <QStackedWidget>
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

                // window geometry
                int width = 600;
                int height = 400;

                LRCScroll* m_plugin;
                QHBoxLayout* layout = new QHBoxLayout();
                QStackedWidget* stack; //  = new QStackedWidget();
                
                // stacked widgets
                TimestampEditor* tse;// = new TimestampEditor(nullptr);
                VerticalMarquee* marquee;

                QString getText();
                
                void setupParent(int width, int height);
                void setupTimestampEditor(int width, int height);
                void setupMarquee(int width, int height);
                
                
                //void clearLayout();
                
                public:
                LRCScrollView(LRCScroll* plugin);
                ~LRCScrollView();
                
                void show(int index); // widget sequence in the stack
                void animate(); // show scroller

                int fontSize = 18;
                void sizeFactor(int key); // font size speed factor
                void fontSizeChanged(); // font size speed factor

                void speedFactor(int key); // adjust the timer interval
                
            protected:
                void closeEvent(QCloseEvent* event) override;
                // void focusInEvent(QFocusEvent* event) override;
                // void focusOutEvent(QFocusEvent* event) override;
                // void changeEvent(QEvent *event) override;
                
                // @see LRCScrollKeyFilter
                //void keyPressEvent(QKeyEvent* event) override;
        };
    }
}

#endif // LMMS_PLUGINS_LRCSCROLL_LRCSCROLLVIEW_H