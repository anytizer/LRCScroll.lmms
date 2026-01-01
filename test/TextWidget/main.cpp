#include "TextScrollerWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TextScrollerWidget scroller;
    scroller.show(); // Display the widget

    // Example usage: adding text
    scroller.appendLogMessage("Application started...");
    scroller.appendLogMessage("Loading configuration...");
    scroller.appendLogMessage("Ready for use.");

    return a.exec();
}

