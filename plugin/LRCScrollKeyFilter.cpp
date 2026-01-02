/**
 * LRCScrollKeyFilter.cpp
 * (c) 2026 Bimal Poudel <@anytizer:github>
 */

#ifndef LMMS_PLUGINS_LRCSCROLL_LRCSCROLLKEYFILTER_CPP
#define LMMS_PLUGINS_LRCSCROLL_LRCSCROLLKEYFILTER_CPP

#include <QObject>
#include <QEvent>
#include <QKeyEvent>
#include <QDebug>

#include "LRCScrollKeyFilter.h"

namespace lmms
{
    namespace gui
    {
        bool LRCScrollKeyFilter::eventFilter(QObject* obj, QEvent* event)
        {
            if (event->type() == QEvent::KeyPress)
            {
                auto* keyEvent = static_cast<QKeyEvent*>(event);
                qDebug() << "Key pressed:" << keyEvent->key() << "Text:" << keyEvent->text();

                // key necessity:
                // space: pause, continue
                // zoom text
                // increase speed
                // decrease speed
                // increase pixels distance per frame
                // escape: switch

                bool accepted = true;
                int key = keyEvent->key();
                bool ctrlWasPressed = keyEvent->modifiers().testFlag(Qt::ControlModifier);
                switch(key)
                {
                    case Qt::Key_F9:
                        this->view->show(0);
                        break;
                    case Qt::Key_F10:
                        this->view->prepareToAnimate();
                        this->view->show(1);
                        break;
                    case Qt::Key_Escape:
                        //this->view->hide();
                        this->view->show(1);
                        break;
                    case Qt::Key_Plus:
                    case Qt::Key_Minus:
                        if(ctrlWasPressed)
                        {
                            // @todo double the effect
                            this->view->sizeFactor(key);
                        }
                        else
                        {
                            this->view->sizeFactor(key);
                        }
                        break;
                    case Qt::Key_Up:
                    case Qt::Key_Down:
                        this->view->speedFactor(key);
                        break;
                    case Qt::Key_Left:  
                    case Qt::LeftArrow:
                    case Qt::Key_Right:
                    case Qt::RightArrow:
                        this->view->alignmentFactor(key);
                        break;
                    default:
                        accepted = false;
                        break;
                }
                if(accepted) { event->accept(); return accepted; }
            }
            
            // 5. Always pass unhandled events to the base class
            return QObject::eventFilter(obj, event);
        }
    }
}

#endif // LMMS_PLUGINS_LRCSCROLL_LRCSCROLLKEYFILTER_H