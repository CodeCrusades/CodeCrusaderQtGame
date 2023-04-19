//Lauryn C. Hansen
#include "game1scene.h"
#include "waterDroplet.h"
#include <QTimer>
#include <QObject>

//Contructor
game1scene::game1scene(){
    qInfo("I'm in the game1scene constructor.");

    //add bucket
    bucketItem = new bucket();
    addItem(bucketItem);
    bucketItem->setPixmap(QPixmap(":/images/bucket.png").scaled(150,150));
    bucketItem->setFlag(QGraphicsItem::ItemIsFocusable);
    bucketItem->setFocus();
    bucketItem->setPos(400,365);

    //add background
    setBackgroundBrush(QBrush(QImage(":/images/background.jpg").scaledToHeight(512) .scaledToWidth(910)));
    setSceneRect(0,0,908,510);

    //add multiple droplets to game scence
    spawnDropletsTimer = new QTimer(this);
    connect(spawnDropletsTimer, &QTimer::timeout, this, &game1scene::generateDroplet);
    spawnDropletsTimer->start(800);
}
//Method to generate a water droplet
void game1scene::generateDroplet(){
     qInfo("I'm in generateDroplet method.");
    waterDroplet *dropleeeet = new waterDroplet();
    this->addItem(dropleeeet);
    int random_number = arc4random() % 700;
    dropleeeet->setPos(random_number, 0);
    this->addItem(dropleeeet);
}









