/**
 * VerticalMarquee.h
 * (c) 2026 Bimal Poudel <@anytizer:github>
 */

#ifndef LMMS_PLUGINS_LRCSCROLL_VERTICALMARQUEE_H
#define LMMS_PLUGINS_LRCSCROLL_VERTICALMARQUEE_H

#include <QWidget>
#include <QTimer>

namespace lmms
{
    namespace gui
    {

        class VerticalMarquee : public QWidget {
            Q_OBJECT

        public:
            explicit VerticalMarquee(QWidget *parent = nullptr);
            void setText(const QString &newText);

        protected:
            void paintEvent(QPaintEvent *event) override;
            void showEvent(QShowEvent *event) override;

        private slots:
            void updateScroll();

        private:
            QString text = "";
            int lineHeight = 0; // font size + padding + margin | font + ascent + descent
            int textHeight = 0;
            int yOffset = 0;
            int scrollSpeed = 2; // Move these pixels per frame
            int ticks = 30; // fps? 30
            QTimer *timer;
            QFont font;
        };
    }
}

#endif // LMMS_PLUGINS_LRCSCROLL_VERTICALMARQUEE_H