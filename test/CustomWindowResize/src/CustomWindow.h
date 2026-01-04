#include <QWidget>
#include <QMouseEvent>

class CustomWindow : public QWidget {
    Q_OBJECT

public:
    CustomWindow(QWidget *parent = nullptr);
    
protected:
    //bool nativeEvent(const QByteArray &eventType, void *message, qintptr *result) override;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    void updateCursorShape(const QPointF &pos);
    
    const int MARGIN = 8;
    const int BORDER_WIDTH = 8; // The "hit area" for resizing
    
    bool m_isResizing = false;
    
    // Tracks which edges are being dragged
    bool m_onLeft = false;
    bool m_onRight = false;
    bool m_onTop = false;
    bool m_onBottom = false;

    QPoint m_dragPosition;
};