//Lauryn C. Hansen
#include "game1scene.h"
#include "waterDroplet.h"
#include <QTimer>
#include <QObject>


//Contructor
game1scene::game1scene(){
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

    waterDropletCounter = 0;
    points = 0;

    //add multiple droplets to game scence
    spawnDropletsTimer = new QTimer(this);
    connect(spawnDropletsTimer, &QTimer::timeout, this, &game1scene::generateDropletAndCount);
    spawnDropletsTimer->start(800);

//    if ( points >= 150){
//        addText("You Won!!!");
//    }

}
//Method to generate a water droplet
void game1scene::generateDropletAndCount(){
    // qInfo("I'm in generateDroplet method.");
    waterDroplet *dropleeeet = new waterDroplet();
    this->addItem(dropleeeet);
    int random_number = arc4random() % 700;
    dropleeeet->setPos(random_number, 0);
    this->addItem(dropleeeet);
    waterDropletCounter ++; //Keeping track of water droplets spawned
    points = points + 5;//Keeping track of points
}










