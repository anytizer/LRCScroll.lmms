#ifndef LMMS_PLUGINS_LRCSCROLL_TIMESTAMPEDITOR_H
#define LMMS_PLUGINS_LRCSCROLL_TIMESTAMPEDITOR_H

#include <QWidget>
#include <QPushButton>
#include <QElapsedTimer>
#include <QPlainTextEdit>
#include <QKeyEvent>
#include <QCloseEvent>
#include <QTextCursor>

namespace lmms
{
    namespace gui
    {
        class TimestampEditor : public QWidget
        {
            public:
                TimestampEditor(QWidget *parent);
                void setLyrics(QString lyrics);
                
            protected:
                void keyPressEvent(QKeyEvent* event) override;
                void closeEvent(QCloseEvent* event) override;
                
            private slots:
                void insertElapsed();
                
            private:
                
                Q_OBJECT
                
                QPlainTextEdit *editor;
                QPushButton *btn;
                QElapsedTimer timer;
                QString getCurrentLine(QTextCursor cursor);
        };
    }
}

#endif // LMMS_PLUGINS_LRCSCROLL_TIMESTAMPEDITOR_H