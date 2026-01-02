/**
 * VerticalMarquee.cpp
 * (c) 2026 Bimal Poudel <@anytizer:github>
 */

#ifndef LMMS_PLUGINS_LRCSCROLL_VERTICALMARQUEE_CPP
#define LMMS_PLUGINS_LRCSCROLL_VERTICALMARQUEE_CPP

#include <QFontMetrics>
#include "VerticalMarquee.h"
#include <QPainter>

namespace lmms
{
    namespace gui
    {
        VerticalMarquee::VerticalMarquee(QWidget *parent) : QWidget(parent) {
            setAttribute(Qt::WA_TranslucentBackground);

            Qt::WindowFlags wf = parent->windowFlags();
            wf |= Qt::WindowStaysOnTopHint;
            wf |= Qt::MSWindowsFixedSizeDialogHint;
            wf |= Qt::WindowStaysOnTopHint;
            parent->setWindowFlags(wf);

            yOffset = height();
            
            // total font height
            QFontMetrics qfm = this->fontMetrics();
            this->lineHeight = qfm.ascent() + qfm.height() + qfm.descent();
            
            timer = new QTimer(this);
            connect(timer, &QTimer::timeout, this, &VerticalMarquee::updateScroll);
            timer->start(this->ticks);
        }

        void VerticalMarquee::setText(const QString &_text) {
            text = _text;
            
            // disable this line
            yOffset = this->height(); // this->lineHeight * (this->text.count('\n')+1); // default: this line not preset

            // double?? + view size's Y
            this->textHeight = this->lineHeight * (this->text.count('\n')+1); // + yOffset;
            
            update();
        }

        void VerticalMarquee::updateScroll() {
            yOffset -= scrollSpeed;
            if (yOffset < -textHeight)
            {
                yOffset = height();
            }
            
            update();
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
            // Default values: 0, 255, 255, 255
            painter.setFont(this->font);
            painter.setPen(QColor(255, 200, 0, 222));

            QRect textRect = rect();
            textRect.moveTop(yOffset);
            
            painter.drawText(textRect, Qt::AlignHCenter, text); // no wordwrap!
        }

        void VerticalMarquee::showEvent(QShowEvent *event) {
            QWidget::showEvent(event);
            yOffset = height(); // Initialize position when shown | default: height()
        }
    }
}

#endif // LMMS_PLUGINS_LRCSCROLL_VERTICALMARQUEE_CPP