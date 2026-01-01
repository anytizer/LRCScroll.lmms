/**
 * TimestampEditor.h
 * (c) 2026 Bimal Poudel <@anytizer:github>
 */

#ifndef LMMS_PLUGINS_LRCSCROLL_TIMESTAMPEDITOR_H
#define LMMS_PLUGINS_LRCSCROLL_TIMESTAMPEDITOR_H

#include <QWidget>
#include <QPushButton>
#include <QElapsedTimer>
#include <QPlainTextEdit>
#include <QKeyEvent>
#include <QCloseEvent>
#include <QTextCursor>

#include "VerticalMarquee.h"

namespace lmms
{
    namespace gui
    {
        class TimestampEditor : public QWidget
        {
            public:
                TimestampEditor(QWidget *parent);
                void setLyrics(QString lyrics);
                void stopTimer();
                
            protected:
                void keyPressEvent(QKeyEvent* event) override;
                
            private slots:
                void insertElapsed();
                
            private:
                
                Q_OBJECT
                
                QPlainTextEdit *editor;
                QPushButton *btn;
                QElapsedTimer timer;
                QString getCurrentLine(QTextCursor cursor);
                QString getWholeLyricsOnly(); // whole text without timestamp

                VerticalMarquee* marquee = new VerticalMarquee();
        };
    }
}

#endif // LMMS_PLUGINS_LRCSCROLL_TIMESTAMPEDITOR_H