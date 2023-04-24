//Lauryn C. Hansen
#include "waterDroplet.h"
#include <QTimer>
#include<QGraphicsItem>


//Constructor
waterDroplet::waterDroplet(QObject *parent): QObject{parent}
{
     // missed counter
    missedFiveDroplet = false;
    this->setPixmap((QPixmap(":/images/water.gif")).scaled(30,30));

    QTimer *timer_drop = new QTimer(this);
    connect(timer_drop, &QTimer::timeout, this, &waterDroplet::makeItRain);
    timer_drop->start(200);
     missedDropletCount = 0;
}


//Method for producing many raindrops and deleting raindrops when they are out of the scene view or if they collide
void waterDroplet::makeItRain() {
     setPos(x(), y() + 10);
     if (this->y() > 510) {
       //         missedDropletCount++;
       scene()->removeItem(this);
       delete this;
     }
}

