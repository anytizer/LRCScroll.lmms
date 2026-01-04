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
            explicit VerticalMarquee(QWidget* parent = nullptr);
            void setText(const QString& newText);
            void ticksChanged(int adjust);
            void alignmentDirectionChanged(int direction);
            void recalculateDisplayHeight();

        protected:
            void paintEvent(QPaintEvent* event) override;
            void showEvent(QShowEvent* event) override;

        private slots:
            void updateScroll();

        private:
            QString text = "";
            int lineHeight = 0; // font size + padding + margin | font + ascent + descent
            int textHeight = 0;
            int yOffset = 0;
            int scrollSpeed = 2; // pixels per frame - movement
            int ticks = 100; // fps? 30

            int alignmentDirection = 1; // AlignHCenter
            std::vector<Qt::AlignmentFlag> directions = {
                Qt::AlignmentFlag::AlignLeft,
                Qt::AlignmentFlag::AlignHCenter,
                Qt::AlignmentFlag::AlignRight,
            };
            
            QTimer* timer;
            QFont font;
        };
    }
}

#endif // LMMS_PLUGINS_LRCSCROLL_VERTICALMARQUEE_H