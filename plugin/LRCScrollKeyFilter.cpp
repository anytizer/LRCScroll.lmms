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
            // 1. Check event type first
            if (event->type() == QEvent::KeyPress)
            {
                // 2. Use static_cast safely since we checked the type
                auto* keyEvent = static_cast<QKeyEvent*>(event);
                
                // 3. Use Qt's native logging (more efficient than std::endl)
                qDebug() << "Key pressed:" << keyEvent->key() << "Text:" << keyEvent->text();

                // // 4. Implement specific logic (e.g., handling Arrow keys for scrolling)
                // if (keyEvent->key() == Qt::Key_Up || keyEvent->key() == Qt::Key_Down)
                // {
                //     // Handle scroll logic here
                //     // return true; // Return true if you consume the event
                // }

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
                        this->view->animate(); // marquee->setText(this->getText());
                        this->view->show(1);
                        break;
                    case Qt::Key_Escape:
                        //this->view->show(0);
                        this->view->hide();
                        //this.view->close();
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