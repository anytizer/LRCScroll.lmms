#ifndef TEXTSCROLLERWIDGET_H
#define TEXTSCROLLERWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>

class TextScrollerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TextScrollerWidget(QWidget *parent = nullptr);
    void appendLogMessage(const QString &message);

private:
    QTextEdit *textEdit;
};

#endif // TEXTSCROLLERWIDGET_H

