#include "welcomescene.h"
#include <QImage>

welcomeScene::welcomeScene()
{
    //add background
    setBackgroundBrush(QBrush(QColor(220, 240, 255), Qt::SolidPattern));
    setSceneRect(0,0,908,510);

    //common font
    QFont font("Times New Roman", 50);


    welcomeText = new QGraphicsTextItem();
    welcomeText->setPlainText("Welcome!");
    welcomeText->setPos(350, 150);
    welcomeText->setDefaultTextColor(Qt::black);
    welcomeText->setFont(font);
    addItem(welcomeText);

    //QImage image("");
    //imageHolder = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    //imageHolder->setPos(350, 200);
    //addItem(imageHolder);

}
