/**
 * LRCScrollView.cpp
 * (c) 2026 Bimal Poudel <@anytizer:github>
 */

#ifndef LMMS_PLUGINS_LRCSCROLL_LRCSCROLLVIEW_CPP
#define LMMS_PLUGINS_LRCSCROLL_LRCSCROLLVIEW_CPP

#include "LRCScroll.h"
#include "LRCScrollView.h"
#include "TimestampEditor.h"

#include <QLayoutItem>

namespace lmms
{
    namespace gui
    {
        using lmms::LRCScroll;
        
        LRCScrollView::LRCScrollView(LRCScroll* plugin): ToolPluginView(plugin), m_plugin(plugin)
        {
            int width = 600;
            int height = 400;
            
            this->clearLayout();
            
            //tse->setFixedWidth(width);
            //tse->setFixedHeight(height);
            this->layout->addWidget(tse);
            this->setLayout(this->layout);
            this->setWindowOpacity(.3);

            this->hide();
			this->setFixedSize(width, height);
			QWidget* parent = parentWidget();
			if(parent!=nullptr)
			{
                parent->hide();
				parent->resize(width, height);
				Qt::WindowFlags flags = parent->windowFlags();
				//flags |= Qt::MSWindowsFixedSizeDialogHint;
				flags &= ~Qt::WindowMaximizeButtonHint;
				flags |= Qt::WindowStaysOnTopHint;
				parent->setWindowFlags(flags);
            }
        }

        LRCScrollView::~LRCScrollView()
        {

        }

        void LRCScrollView::focusInEvent(QFocusEvent *event)
        {
            Q_UNUSED(event);
            qDebug() << "Window gained focus. Changing to framed.";
        }

        void LRCScrollView::focusOutEvent(QFocusEvent *event)
        {
            Q_UNUSED(event);
            qDebug() << "Window lost focus. Changing to frameless.";
        }

        void LRCScrollView::changeEvent(QEvent *event)
        {
            // QWidget* parent = parentWidget();
            // if (event->type() == QEvent::ActivationChange)
            // {
            //     if (parent->isActiveWindow())
            //     {
            //         // Fully opaque when focused
            //         parent->setWindowOpacity(1.0);
            //         this->setWindowOpacity(1.0);
            //     }
            //     else
            //     {
            //         // Transparent when focus is lost (e.g., 50% opacity)
            //         parent->setWindowOpacity(0.3);
            //         this->setWindowOpacity(0.3);
            //     }
            // }
        }

        void LRCScrollView::closeEvent(QCloseEvent* event)
        {
            this->tse->stopTimer();
            qDebug() << "LRC Timer should be stopped!";
        }

        void LRCScrollView::clearLayout()
        {
            if (!this->layout) return;

            QLayoutItem *item;
            while ((item = this->layout->takeAt(0)) != nullptr)
            {
                if (item->widget())
                {
                    item->widget()->deleteLater();
                }
                delete item;
            }
        }
    }
}

#endif // LMMS_PLUGINS_LRCSCROLL_LRCSCROLLVIEW_CPP