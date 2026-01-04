#include "CustomWindow.h"

CustomWindow::CustomWindow(QWidget *parent) : QWidget(parent)
{
    // // This tells Qt to keep the contents of the widget and only 
    // // paint the newly exposed areas during a resize.
    // setAttribute(Qt::WA_StaticContents);

    // setAttribute(Qt::WA_NoSystemBackground);
    // setAttribute(Qt::WA_OpaquePaintEvent);
    
    // Remove the standard title bar
    //setWindowFlags(Qt::FramelessWindowHint);
    setMouseTracking(true); // Required to track mouse without clicking
    setMinimumSize(200, 150);
    resize(400, 300);
    setStyleSheet("background-color: #0767a7; border: 4px solid #cd6605;");
}

void CustomWindow::updateCursorShape(const QPointF &pos) {
    if (m_isResizing) return;

    m_onLeft = pos.x() <= MARGIN;
    m_onRight = pos.x() >= width() - MARGIN;
    m_onTop = pos.y() <= MARGIN;
    m_onBottom = pos.y() >= height() - MARGIN;

    QCursor cursor = Qt::ArrowCursor;
    if ((m_onLeft && m_onTop) || (m_onRight && m_onBottom))
        cursor = Qt::SizeFDiagCursor;
    else if ((m_onRight && m_onTop) || (m_onLeft && m_onBottom))
        cursor = Qt::SizeBDiagCursor;
    else if (m_onLeft || m_onRight)
        cursor = Qt::SizeHorCursor;
    else if (m_onTop || m_onBottom)
        cursor = Qt::SizeVerCursor;
    
    if (this->cursor().shape() != cursor.shape())
    {
        setCursor(cursor);
    }
}

void CustomWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton)
    {
        // If the cursor is on any margin: start resizing
        if (m_onLeft || m_onRight || m_onTop || m_onBottom)
        {
            m_isResizing = true;
        }
    }





    // mover
    if (event->button() == Qt::LeftButton) {
        // Check if we are clicking in the "Title Bar" area
        if (event->pos().y() < 40) { 
            // Store the offset from the top-left of the window
            m_dragPosition = event->globalPosition().toPoint() - frameGeometry().topLeft();
            event->accept();
        }
    }
}



void CustomWindow::mouseMoveEvent(QMouseEvent *event) {
    if (!m_isResizing) {
        updateCursorShape(event->position());
    } else {
        // Use globalPosition to avoid the "jumping" feedback loop
        QPoint globalPos = event->globalPosition().toPoint();
        QRect newGeometry = geometry();

        if (m_onRight) {
            newGeometry.setRight(globalPos.x());
        }
        if (m_onLeft) {
            // Ensure we don't push the left edge past the right edge (minus min width)
            int newLeft = globalPos.x();
            if (newGeometry.right() - newLeft >= minimumWidth()) {
                newGeometry.setLeft(newLeft);
            }
        }
        if (m_onBottom) {
            newGeometry.setBottom(globalPos.y());
        }
        if (m_onTop) {
            // Ensure we don't push the top edge past the bottom edge (minus min height)
            int newTop = globalPos.y();
            if (newGeometry.bottom() - newTop >= minimumHeight()) {
                newGeometry.setTop(newTop);
            }
        }

        setGeometry(newGeometry);
    }


    // mover
    if (event->buttons() & Qt::LeftButton && !m_dragPosition.isNull()) {
        // Move the window to the new global position minus the original offset
        move(event->globalPosition().toPoint() - m_dragPosition);
        event->accept();
    }
}

// void CustomWindow::mouseMoveEvent(QMouseEvent *event) {
//     if (!m_isResizing) {
//         updateCursorShape(event->pos());
//     } else {
//         QRect newGeometry = geometry();
//         QPointF globalPos = event->globalPosition();

//         // Right side resize
//         if (m_onRight)
//         {
//             newGeometry.setRight(globalPos.x());
//         }
        
//         // Left side resize (Changes X and Width)
//         if (m_onLeft)
//         {
//             newGeometry.setLeft(globalPos.x());
//         }
        
//         // Bottom side resize
//         if (m_onBottom)
//         {
//             newGeometry.setBottom(globalPos.y());
//         }
        
//         // Top side resize (Changes Y and Height)
//         if (m_onTop)
//         {
//             newGeometry.setTop(globalPos.y());
//         }

//         // Apply geometry only if it meets minimum constraints
//         if (newGeometry.width() >= minimumWidth() && newGeometry.height() >= minimumHeight())
//         {
//             setGeometry(newGeometry);
//         }
//     }
// }

void CustomWindow::mouseReleaseEvent(QMouseEvent *event) {
    m_isResizing = false;
    updateCursorShape(event->pos());

    m_dragPosition = QPoint(); // Reset the offset
}



/**

// implementation of nativeEvent

#ifdef Q_OS_WIN
#include <windows.h>
#include <windowsx.h>

bool CustomWindow::nativeEvent(const QByteArray &eventType, void *message, qintptr *result) {
    MSG* msg = static_cast<MSG*>(message);

    if (msg->message == WM_NCHITTEST) {
        // Get the global mouse position from the message
        int xPos = GET_X_LPARAM(msg->lParam);
        int yPos = GET_Y_LPARAM(msg->lParam);

        // Convert global coordinates to local widget coordinates
        QPoint localPos = mapFromGlobal(QPoint(xPos, yPos));
        
        int x = localPos.x();
        int y = localPos.y();
        int w = width();
        int h = height();

        // Determine if the mouse is within the resizing borders
        bool onLeft = (x < BORDER_WIDTH);
        bool onRight = (x > w - BORDER_WIDTH);
        bool onTop = (y < BORDER_WIDTH);
        bool onBottom = (y > h - BORDER_WIDTH);

        // Return the specific "Hit Test" value to Windows
        if (onLeft && onTop) *result = HTTOPLEFT;
        else if (onLeft && onBottom) *result = HTBOTTOMLEFT;
        else if (onRight && onTop) *result = HTTOPRIGHT;
        else if (onRight && onBottom) *result = HTBOTTOMRIGHT;
        else if (onLeft) *result = HTLEFT;
        else if (onRight) *result = HTRIGHT;
        else if (onTop) *result = HTTOP;
        else if (onBottom) *result = HTBOTTOM;
        else {
            // If not on a border, let Qt handle it (treat as client area)
            return QWidget::nativeEvent(eventType, message, result);
        }

        return true; // We handled the event
    }
    else
    {
        // This treats the entire window body as a title bar for dragging
        *result = HTCAPTION; 
        return true;
    }


    // mover
    if (msg->message == WM_NCHITTEST) {
        QPoint localPos = mapFromGlobal(QPoint(GET_X_LPARAM(msg->lParam), GET_Y_LPARAM(msg->lParam)));
        
        // 1. Check for resize borders first (keep your existing logic here)
        // ... (if on border, set *result and return true) ...

        // 2. Define a draggable "Title Bar" area (e.g., top 40 pixels)
        const int TITLE_BAR_HEIGHT = 40;
        if (localPos.y() < TITLE_BAR_HEIGHT) {
            *result = HTCAPTION;
            return true;
        }
    }



    return QWidget::nativeEvent(eventType, message, result);
}
#endif
*/