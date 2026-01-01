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
            QString text;
            int yOffset;
            QTimer *timer;
            int scrollSpeed; // Pixels per frame
        };
    }
}

#endif // LMMS_PLUGINS_LRCSCROLL_VERTICALMARQUEE_H