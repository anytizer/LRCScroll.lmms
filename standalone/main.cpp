#include <QApplication>
#include <QStyleFactory>
#include <QPalette>
#include <QColor>
#include <QFile>
#include <QFileInfo>
#include <QIODevice>

#include "../plugin/TimestampEditor.h"

using lmms::gui::TimestampEditor;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString lyrics_filename = "../lyrics.lrc";
    QString lyrics_content = "";
    QFileInfo finfo(lyrics_filename);
    if(finfo.exists() && finfo.isFile())
    {
        QFile file(lyrics_filename);
        if(finfo.size()<=102400) // 100kb
        {
            if(file.open(QIODevice::ReadOnly|QIODevice::Text))
            {
                QTextStream in(&file);
                lyrics_content = in.readAll();
                file.close();
            }
        }
    }

    TimestampEditor* window = new TimestampEditor(nullptr);
    window->setLyrics(lyrics_content);
    window->resize(500, 400);
    window->show();

    return app.exec();
}