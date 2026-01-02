/**
 * LRCScrollView.cpp
 * (c) 2026 Bimal Poudel <@anytizer:github>
 */

#ifndef LMMS_PLUGINS_LRCSCROLL_LRCSCROLLVIEW_CPP
#define LMMS_PLUGINS_LRCSCROLL_LRCSCROLLVIEW_CPP

#include "LRCScroll.h"
#include "LRCScrollView.h"
#include "VerticalMarquee.h"
#include "TimestampEditor.h"
#include "LRCScrollKeyFilter.h"

namespace lmms
{
    namespace gui
    {
        using lmms::LRCScroll;
        
        LRCScrollView::LRCScrollView(LRCScroll* plugin): ToolPluginView(plugin), m_plugin(plugin)
        {
            this->setFixedSize(this->width, this->height);
            this->hide();
			
            this->setupTimestampEditor(this->width, this->height);
            this->setupMarquee(this->width, this->height);
            this->setupParent(this->width, this->height);
            
            // prepare the stack
            this->stack = new QStackedWidget();
            this->stack->addWidget(this->tse);
            this->stack->addWidget(this->marquee);
            this->show(0);

            QHBoxLayout* layout = new QHBoxLayout();
            layout->addWidget(this->stack);
            this->setLayout(layout);

            // 'this' sets the filter owner
            LRCScrollKeyFilter* filter = new LRCScrollKeyFilter(this);
            //filter->F10(); // switch scroll panel or editor mode
            this->installEventFilter(filter);
        }

        void LRCScrollView::show(int index)
        {
            qDebug() << "Showing stack # " << index;
            this->stack->setCurrentIndex(index%this->stack->count());
        }

        void LRCScrollView::prepareToAnimate()
        {
            marquee->setText(this->getText());
            //this->show(1);
        }


        void LRCScrollView::sizeFactor(int key)
        {
            int sizeChangeFactor = 1;

            if(key == Qt::Key_Plus) sizeChangeFactor = 1;
            if(key == Qt::Key_Minus) sizeChangeFactor = -1;

            this->fontSize += sizeChangeFactor;
            if(this->fontSize > 48) this->fontSize = 48;
            if(this->fontSize < 9) this->fontSize = 9;

            this->fontSizeChanged();
        }

        void LRCScrollView::speedFactor(int key)
        {
            int adjust = 0;
            if(key == Qt::Key_Up) adjust = -5;
            if(key == Qt::Key_Down) adjust = 5;

            this->marquee->ticksChanged(adjust);
        }

        void LRCScrollView::alignmentFactor(int key)
        {
            int direction = 0;
            if(key == Qt::LeftArrow) direction -= 1;
            if(key == Qt::Key_Left) direction -= 1;
            if(key == Qt::RightArrow) direction += 1;
            if(key == Qt::Key_Right) direction += 1;

            this->marquee->alignmentDirectionChanged(direction);
        }


        void LRCScrollView::setupTimestampEditor(int width, int height)
        {
            this->tse = new TimestampEditor(nullptr);
            this->tse->resize(width, height);
        }

        void LRCScrollView::setupParent(int width, int height)
        {
            QWidget* parent = this->parentWidget();
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

        void LRCScrollView::setupMarquee(int width, int height)
        {
            this->marquee = new VerticalMarquee(this);
            this->marquee->setWindowTitle("LRCScroll"); // transparent & frameless
            this->marquee->resize(width, height);
            
            QFont font = QFont();
            font.setFamily("Helvatica");
            font.setFamilies({"Consolas", "Helvatica"});
            font.setBold(true);
            font.setPointSize(this->fontSize);
            this->marquee->setFont(font);
        }

        void LRCScrollView::fontSizeChanged()
        {
            QFont font = this->font();
            font.setPointSize(this->fontSize);
            this->marquee->setFont(font);
         
            this->marquee->recalculateDisplayHeight();         
        }

        LRCScrollView::~LRCScrollView()
        {
        }




        // void LRCScrollView::focusInEvent(QFocusEvent *event)
        // {
        //     Q_UNUSED(event);
        //     qDebug() << "Window gained focus. Changing to framed.";
        // }

        // void LRCScrollView::focusOutEvent(QFocusEvent *event)
        // {
        //     Q_UNUSED(event);
        //     qDebug() << "Window lost focus. Changing to frameless.";
        // }

        // void LRCScrollView::changeEvent(QEvent *event)
        // {
        //     // QWidget* parent = parentWidget();
        //     // if (event->type() == QEvent::ActivationChange)
        //     // {
        //     //     if (parent->isActiveWindow())
        //     //     {
        //     //         // Fully opaque when focused
        //     //         parent->setWindowOpacity(1.0);
        //     //         this->setWindowOpacity(1.0);
        //     //     }
        //     //     else
        //     //     {
        //     //         // Transparent when focus is lost (e.g., 50% opacity)
        //     //         parent->setWindowOpacity(0.3);
        //     //         this->setWindowOpacity(0.3);
        //     //     }
        //     // }
        // }

        void LRCScrollView::closeEvent(QCloseEvent* event)
        {
            this->tse->stopTimer();
            qDebug() << "LRC Timer should be stopped!";
        }

        // void LRCScrollView::clearLayout()
        // {
        //     // if (!this->layout) return;

        //     // QLayoutItem *item;
        //     // while ((item = this->layout->takeAt(0)) != nullptr)
        //     // {
        //     //     if (item->widget())
        //     //     {
        //     //         item->widget()->deleteLater();
        //     //     }
        //     //     delete item;
        //     // }
        // }

        // void LRCScrollView::keyPressEvent(QKeyEvent* event)
        // {
        //     bool accepted = true;
        //     switch(event->key())
        //     {
        //     case Qt::Key_F10:
        //         // hide TSE
        //         qDebug() << "F10 from LRCScrollView...";
        //         //this->layout->removeWidget(this->tse);
 
        //         marquee->setText(this->getText());
        //         this->show(1);
        //         //this->stack->setCurrentIndex(index);

        //         //marquee->show();

        //         // this->clearLayout();
        //         // this->layout->addWidget(marquee);
        //         // this->setLayout(this->layout);
        //         break;
        //     case Qt::Key_Escape:
        //         // close the window and show editor
        //         qDebug() << "ESC from LRCScrollView.";
        //         this->show(0);
        //         break;
        //     default:
        //         accepted = false;    
        //         break;
        //     }

        //     if(accepted) event->accept();
        // }

        QString LRCScrollView::getText()
        {
            return this->tse->getLyrics(true);
        }
    }
}

#endif // LMMS_PLUGINS_LRCSCROLL_LRCSCROLLVIEW_CPP