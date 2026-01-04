#include "CustomWindow.h"

CustomWindow::CustomWindow(QWidget *parent) : QWidget(parent) {
    // Remove the standard title bar
    //setWindowFlags(Qt::FramelessWindowHint);
    setMouseTracking(true); // Required to track mouse without clicking
    setMinimumSize(200, 150);
    resize(400, 300);
    setStyleSheet("background-color: #2d2d2d; border: 1px solid #555;");
}

void CustomWindow::updateCursorShape(const QPoint &pos) {
    if (m_isResizing) return;

    m_onLeft = pos.x() <= MARGIN;
    m_onRight = pos.x() >= width() - MARGIN;
    m_onTop = pos.y() <= MARGIN;
    m_onBottom = pos.y() >= height() - MARGIN;

    if ((m_onLeft && m_onTop) || (m_onRight && m_onBottom))
        setCursor(Qt::SizeFDiagCursor);
    else if ((m_onRight && m_onTop) || (m_onLeft && m_onBottom))
        setCursor(Qt::SizeBDiagCursor);
    else if (m_onLeft || m_onRight)
        setCursor(Qt::SizeHorCursor);
    else if (m_onTop || m_onBottom)
        setCursor(Qt::SizeVerCursor);
    else
        setCursor(Qt::ArrowCursor);
}

void CustomWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        // If the cursor is on any margin, start resizing
        if (m_onLeft || m_onRight || m_onTop || m_onBottom) {
            m_isResizing = true;
        }
    }
}

void CustomWindow::mouseMoveEvent(QMouseEvent *event) {
    if (!m_isResizing) {
        updateCursorShape(event->pos());
    } else {
        QRect newGeometry = geometry();
        QPoint globalPos = event->globalPos();

        // Right side resize
        if (m_onRight) {
            newGeometry.setRight(globalPos.x());
        }
        // Left side resize (Changes X and Width)
        if (m_onLeft) {
            newGeometry.setLeft(globalPos.x());
        }
        // Bottom side resize
        if (m_onBottom) {
            newGeometry.setBottom(globalPos.y());
        }
        // Top side resize (Changes Y and Height)
        if (m_onTop) {
            newGeometry.setTop(globalPos.y());
        }

        // Apply geometry only if it meets minimum constraints
        if (newGeometry.width() >= minimumWidth() && newGeometry.height() >= minimumHeight()) {
            setGeometry(newGeometry);
        }
    }
}

void CustomWindow::mouseReleaseEvent(QMouseEvent *event) {
    m_isResizing = false;
    updateCursorShape(event->pos());
}