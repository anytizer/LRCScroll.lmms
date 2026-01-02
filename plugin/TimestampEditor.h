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
                QString getLyrics(bool all);
                void stopTimer();
                
                protected:
                void keyPressEvent(QKeyEvent* event) override;
                
                private slots:
                void insertElapsed();
                
            private:
                
                Q_OBJECT
                
                const QString timestampSignatureRegex = "\\[\\d{2}\\:\\d{2}\\.\\d{2,}\\][\\s]{1}";
                
                QPlainTextEdit *editor;
                QPushButton *btn;
                QElapsedTimer timer;
                
                //VerticalMarquee* marquee = new VerticalMarquee();
                QString getCurrentLine(QTextCursor cursor);
        };
    }
}

#endif // LMMS_PLUGINS_LRCSCROLL_TIMESTAMPEDITOR_H