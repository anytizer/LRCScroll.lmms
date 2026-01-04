#include "CustomWindow.h"
#include <QApplication>
#include <QCursor>

// Standard main function to launch the app
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    CustomWindow w;
    w.show();
    return a.exec();
}