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
            int width = 500;
            int height = 500;
            
            this->clearLayout();
            TimestampEditor* tse = new TimestampEditor(nullptr);
            //tse->setFixedWidth(width);
            //tse->setFixedHeight(height);
            this->layout->addWidget(tse);
            this->setLayout(this->layout);
            //tse->show();

			this->hide();
			this->setFixedSize(width + 20, height + 20);
			QWidget* parent = parentWidget();
			if(parent!=nullptr)
			{
                parent->hide();
				parent->resize(width+20, height+20);
				Qt::WindowFlags flags = parent->windowFlags();
				flags |= Qt::MSWindowsFixedSizeDialogHint;
				flags &= ~Qt::WindowMaximizeButtonHint;
				flags |= Qt::WindowStaysOnTopHint;
				parent->setWindowFlags(flags);
            }

        }

        LRCScrollView::~LRCScrollView()
        {

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