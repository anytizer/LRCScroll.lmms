#include "VerticalMarquee.h"
#include <QPainter>

VerticalMarquee::VerticalMarquee(QWidget *parent) : QWidget(parent) {
    text = "Hello! This is a vertical marquee scrolling upwards.";
    yOffset = height();
    scrollSpeed = 2;

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &VerticalMarquee::updateScroll);
    timer->start(30); // ~33 FPS
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

    // Draw the text centered horizontally
    QRect textRect = rect();
    textRect.moveTop(yOffset);
    
    painter.drawText(textRect, Qt::AlignHCenter, text);
}

void VerticalMarquee::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);
    yOffset = height(); // Initialize position when shown
}
