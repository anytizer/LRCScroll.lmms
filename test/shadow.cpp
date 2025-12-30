#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QGraphicsDropShadowEffect>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QLabel *label = new QLabel("Shadow Text");
    
    // Create the shadow effect
    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect();
    effect->setColor(QColor(0, 0, 0, 150)); // Shadow color (black with some transparency)
    effect->setOffset(2, 2);                // Shadow offset (X, Y)
    effect->setBlurRadius(4);               // Shadow blur radius
    
    // Apply the effect to the label
    label->setGraphicsEffect(effect);
    
    // Set the main text color (must contrast with shadow for visibility)
    label->setStyleSheet("QLabel { color: white; }"); 
    
    // Set the font
    QFont font("Helvetica", 24, QFont::Bold);
    label->setFont(font);

    label->resize(200, 100);
    label->show();

    return a.exec();
}

