#include "TextScrollerWidget.h"
#include <QDebug>

TextScrollerWidget::TextScrollerWidget(QWidget *parent) :
    QWidget(parent)
{
    // 1. Set window flags to make it always on top
    // The 'Qt::Window' flag is required for the hint to work correctly as it tells
    // the OS to treat this QWidget as a separate window.
    setWindowFlags(windowFlags() | Qt::Window | Qt::WindowStaysOnTopHint);
    
    // 2. Create the scrolling text area
    textEdit = new QTextEdit(this);
    textEdit->setReadOnly(true); // Make it a log display, not editable by the user
    
    // Optional: set some text interaction flags if you want users to be able to select/copy text
    textEdit->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);

    // 3. Set up the layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(textEdit);
    setLayout(layout);

    // Set a reasonable default size
    resize(400, 300);
}

void TextScrollerWidget::appendLogMessage(const QString &message)
{
    textEdit->append(message);
    // Automatically scrolls to the bottom when new text is added
}
