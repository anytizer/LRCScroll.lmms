/**
 * TimestampEditor.cpp
 * (c) 2026 Bimal Poudel <@anytizer:github>
 */

#ifndef LMMS_PLUGINS_LRCSCROLL_TIMESTAMPEDITOR_CPP
#define LMMS_PLUGINS_LRCSCROLL_TIMESTAMPEDITOR_CPP

#include <Qt>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QElapsedTimer>
#include <QPlainTextEdit>
#include <QTextCursor>
#include <QTextBlock>
#include <QString>
#include <QKeyEvent>
#include <QRegularExpression>

#include "TimestampEditor.h"

namespace lmms
{
    namespace gui
    {
        TimestampEditor::TimestampEditor(QWidget *parent = nullptr)
        {
            QFont font("Consolas", 18);

            this->editor = new QPlainTextEdit(this);
            this->editor->setFont(font);
            this->editor->setPlainText("[00:00.00] Press F9 here...");
            this->editor->setPlaceholderText("[00:00.00] Press F9 here...");
            this->editor->setContextMenuPolicy(Qt::NoContextMenu);
            
            this->btn = new QPushButton("Start &Tagging", this);
            
            QVBoxLayout *layout = new QVBoxLayout(this);
            layout->addWidget(this->editor);
            layout->addWidget(this->btn);
            connect(this->btn, &QPushButton::clicked, this, &TimestampEditor::insertElapsed);
        }
        
        
        void TimestampEditor::setLyrics(QString lyrics)
        {
            this->editor->setPlainText(lyrics);
        }
        
        
        void TimestampEditor::keyPressEvent(QKeyEvent* event)
        {
            if(event->key() == Qt::Key_F9)
            {
                qDebug() << "F9 key pressed!";
                
                this->insertElapsed();        
                event->accept();
            }
        }
        
        
        void TimestampEditor::closeEvent(QCloseEvent* event)
        {
            qDebug() << "Application closed.";
        }
        
        QString TimestampEditor::getCurrentLine(QTextCursor cursor)
        {
            cursor.select(QTextCursor::BlockUnderCursor);
            QString line = cursor.selectedText().trimmed();
            line.replace(QRegularExpression("^\\[\\d{2}\\:\\d{2}\\.\\d{2,}\\]\\s+"), ""); // throw ts signature
            return line.trimmed();
        }
        
        void TimestampEditor::insertElapsed()
        {
            if (!this->timer.isValid())
            {
                this->timer.start();
                this->btn->setText("&Tag Current Line");
            }
        
            const qint64 ms = timer.elapsed();
            
            // Formatting: [MM:SS.mmm]
            const int minutes = static_cast<int>(ms / 60000);
            const int seconds = static_cast<int>((ms % 60000) / 1000);
            const int msecs   = static_cast<int>((ms % 1000) / 10);
        
            const QString ts = QString("[%1:%2.%3] ")
                                .arg(minutes, 2, 10, QChar('0'))
                                .arg(seconds, 2, 10, QChar('0'))
                                .arg(msecs, 2, 10, QChar('0'));
        
            QTextCursor cursor = editor->textCursor();
        
            // 1. Calculate how far the cursor is from the START of the text (excluding old timestamp)
            // We use getCurrentLine to get the "clean" text length vs current block length
            QString fullLineText = cursor.block().text();
            QString cleanLineText = this->getCurrentLine(cursor);
            int oldTsLength = fullLineText.length() - cleanLineText.length();
            
            // Calculate relative position: where is the cursor relative to the lyrics?
            int relativePosInLyrics = qMax(0, cursor.positionInBlock() - oldTsLength);
        
            cursor.beginEditBlock();
            
            // 2. Select and replace the entire current block
            cursor.movePosition(QTextCursor::StartOfBlock);
            cursor.movePosition(QTextCursor::EndOfBlock, QTextCursor::KeepAnchor);
            
            // Replace with New Timestamp + Cleaned Lyrics (no extra newlines)
            cursor.insertText(ts + cleanLineText);
            
            cursor.endEditBlock();
        
            // 3. Restore cursor position
            // Move to start of block, then move right by (timestamp length + original relative position)
            cursor.movePosition(QTextCursor::StartOfBlock);
            cursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, ts.length() + relativePosInLyrics);
            
            editor->setTextCursor(cursor);
            editor->setFocus();
        }
    }
}

#endif // LMMS_PLUGINS_LRCSCROLL_TIMESTAMPEDITOR_CPP