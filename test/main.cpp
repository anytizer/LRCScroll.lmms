#include <QCoreApplication>
#include <QRegularExpression>
#include <QString>
#include <QDebug>

void test1()
{
    QString original = "[05:20.123] Another line.";
    qDebug() << "Original:" << original;

    // The regular expression to match the timestamp format:
    // \\[ : Matches the opening bracket '[' literally.
    // [0-9:.]+ : Matches one or more digits, colons, or periods (the time itself).
    // \\] : Matches the closing bracket ']' literally.
    // \\s* : Matches any optional whitespace after the timestamp.
    const QRegularExpression regex("^\\[[0-9:.]+\\]\\s*");

    // Replace all occurrences of the pattern with an empty string
    QString replaced = original.replace(regex, "");

    qDebug() << "Original:" << original;
    qDebug() << "Replaced:" << replaced;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test1();

    return a.exec();
}
