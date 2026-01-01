#include <QApplication>
#include "VerticalMarquee.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    
    VerticalMarquee marquee;
    marquee.setWindowTitle("Qt Vertical Marquee");
    marquee.resize(300, 200);
    marquee.setText("This is a custom vertical scrolling message!");
    marquee.show();

    return a.exec();
}
