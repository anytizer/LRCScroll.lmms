#include "VerticalMarquee.h"
#include <QPainter>

VerticalMarquee::VerticalMarquee(QWidget *parent) : QWidget(parent) {
    // 1. Enable transparency at the window level
    setAttribute(Qt::WA_TranslucentBackground);
    //setWindowFlags(Qt::FramelessWindowHint); // Optional: removes the title bar

    text = "Translucent Background & Opaque Colorful Text";
    yOffset = height();
    scrollSpeed = 2;

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &VerticalMarquee::updateScroll);
    timer->start(50);
}

void VerticalMarquee::setText(const QString &newText) {
    text = newText;
    update();
}

void VerticalMarquee::updateScroll() {
    yOffset -= scrollSpeed;

    // Reset position if the text has completely scrolled off the top
    // We use fontMetrics to calculate the height of the text block
    int textHeight = fontMetrics().height();
    if (yOffset < -textHeight) {
        yOffset = height();
    }
    update(); // Triggers paintEvent
}

void VerticalMarquee::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // 2. Draw Translucent Background
    // QColor(R, G, B, Alpha) -> Alpha 128 is 50% transparency
    painter.setBrush(QColor(0, 0, 0, 150)); 
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(rect(), 10, 10); // Rounded corners look better

    // 3. Draw Opaque Colorful Text
    // Use a bright color like Cyan or Magenta to contrast the dark background
    painter.setPen(QColor(0, 255, 255, 255)); // Full opaque Cyan
    
    QFont font = painter.font();
    font.setBold(true);
    font.setPointSize(14);
    painter.setFont(font);

    QRect textRect = rect();
    textRect.moveTop(yOffset);
    
    // Using WordWrap allows for longer text blocks
    painter.drawText(textRect, Qt::AlignHCenter | Qt::TextWordWrap, text);
}

void VerticalMarquee::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);
    yOffset = height(); // Initialize position when shown
}
