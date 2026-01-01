#include <QFile>
#include <QApplication>
#include "VerticalMarquee.h"

int main(int argc, char *argv[]) {
    QString lyrics = "";
    QFile file("../lyrics.txt");
    if (file.open(QIODevice::ReadOnly)) {
        lyrics = QString::fromUtf8(file.readAll());
        file.close();
    }

    QApplication a(argc, argv);
    
    VerticalMarquee marquee;
    marquee.resize(600, 250);
    marquee.setWindowTitle("LRCScroll");
    marquee.setText(lyrics);
    //marquee.setText("This is a custom vertical scrolling message!\nMultilined text!\n\nWish somebody happy birthday!\nThis evening.");
    marquee.show();

    return a.exec();
}
