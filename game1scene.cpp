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

    qInfo() << "Test1";
    waterDropletCounter = 0;
    points = 0;

    waterDropletItem = new waterDroplet();
    addItem(waterDropletItem);

    //add multiple droplets to game scence
    spawnDropletsTimer = new QTimer(this);
    connect(spawnDropletsTimer, &QTimer::timeout, this, &game1scene::generateDropletAndCount);
    spawnDropletsTimer->start(800);

    win = false;

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &game1scene::handleCollision);
    timer->start(100);

}
//Method to generate a water droplet
void game1scene::generateDropletAndCount() {

    waterDroplet *dropleeeet = new waterDroplet();
    this->addItem(dropleeeet);
    int random_number = arc4random() % 700;
    dropleeeet->setPos(random_number, 0);
    waterDropletCounter++; // Keeping track of water droplets spawned
}

// on drop collision remove the droplet from the scene and get extra points
void game1scene::handleCollision(){

    if (points >= 150) {
        win = true;
    }
    qDebug() << "Points incremented to: " << points; // add debug output

    // check for collision with bucket
    QList<QGraphicsItem *> collisions = collidingItems(bucketItem);
    for (int i = 0; i < collisions.size(); i++) {
      QGraphicsItem *item = collisions.at(i);

      if (item->type() == waterDroplet::Type) { // if the item collided with a bucket is a    and incremment the points                             // waterDroplet type, remove it from the scre
        waterDroplet *droplet = qgraphicsitem_cast<waterDroplet *>(item);
        removeItem(droplet);
        points = points + 5;
        qDebug() << "Points incremented to: " << points; // add debug output
        delete droplet;
      }
    }

     if (win) {
       QGraphicsTextItem *textItem = new QGraphicsTextItem("You Won!!!");
       textItem->setPos(200, 200);
       addItem(textItem);
       return;
       // return from the program or stop the program and call other thing // TODO find a way to stop the program
     }
}


void gameLevels() {

}
