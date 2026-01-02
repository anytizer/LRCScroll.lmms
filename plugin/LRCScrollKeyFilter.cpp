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

                // 4. Implement specific logic (e.g., handling Arrow keys for scrolling)
                if (keyEvent->key() == Qt::Key_Up || keyEvent->key() == Qt::Key_Down)
                {
                    // Handle scroll logic here
                    // return true; // Return true if you consume the event
                }

                // key necessity:
                // space: pause, continue
                // zoom text
                // increase speed
                // decrease speed
                // increase pixels distance per frame
            }
            
            // 5. Always pass unhandled events to the base class
            return QObject::eventFilter(obj, event);
        }
    }
}

#endif // LMMS_PLUGINS_LRCSCROLL_LRCSCROLLKEYFILTER_H