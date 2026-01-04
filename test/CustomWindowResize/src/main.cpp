#include "CustomWindow.h"
#include <QApplication>
#include <QCursor>

// CustomWindow::CustomWindow(QWidget *parent) : QWidget(parent) {
//     // Typically used with frameless windows
//     // setWindowFlags(Qt::FramelessWindowHint); 
//     setMouseTracking(true); // Important: allows mouseMoveEvent without clicking
//     resize(400, 300);
// }

// void CustomWindow::updateCursorShape(const QPoint &pos) {
//     m_onLeft = pos.x() <= MARGIN;
//     m_onRight = pos.x() >= width() - MARGIN;
//     m_onTop = pos.y() <= MARGIN;
//     m_onBottom = pos.y() >= height() - MARGIN;

//     if ((m_onTop && m_onLeft) || (m_onBottom && m_onRight)) {
//         setCursor(Qt::SizeFDiagCursor);
//     } else if ((m_onTop && m_onRight) || (m_onBottom && m_onLeft)) {
//         setCursor(Qt::SizeBDiagCursor);
//     } else if (m_onLeft || m_onRight) {
//         setCursor(Qt::SizeHorCursor);
//     } else if (m_onTop || m_onBottom) {
//         setCursor(Qt::SizeVerCursor);
//     } else {
//         setCursor(Qt::ArrowCursor);
//     }
// }

// void CustomWindow::mousePressEvent(QMouseEvent *event) {
//     if (event->button() == Qt::LeftButton) {
//         // If the cursor is over any edge, start resizing
//         if (m_onLeft || m_onRight || m_onTop || m_onBottom) {
//             m_isResizing = true;
//         }
//     }
// }

// void CustomWindow::mouseMoveEvent(QMouseEvent *event) {
//     if (!m_isResizing) {
//         updateCursorShape(event->pos());
//     } else {
//         QRect rect = geometry();

//         if (m_onLeft) rect.setLeft(mapToParent(event->pos()).x());
//         if (m_onRight) rect.setRight(mapToParent(event->pos()).x());
//         if (m_onTop) rect.setTop(mapToParent(event->pos()).y());
//         if (m_onBottom) rect.setBottom(mapToParent(event->pos()).y());

//         // Set the new geometry (Qt handles minimum size constraints automatically)
//         setGeometry(rect);
//     }
// }

// void CustomWindow::mouseReleaseEvent(QMouseEvent *event) {
//     m_isResizing = false;
//     updateCursorShape(event->pos());
// }

// Standard main function to launch the app
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    CustomWindow w;
    w.show();
    return a.exec();
}