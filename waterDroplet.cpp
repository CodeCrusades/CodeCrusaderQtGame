//Lauryn C. Hansen
#include "waterDroplet.h"
#include <QTimer>
#include<QGraphicsItem>


//Constructor
waterDroplet::waterDroplet(QObject *parent): QObject{parent}
{
    qInfo("I'm in waterDroplet method.");
    this->setPixmap((QPixmap(":/images/water.gif")).scaled(30,30));
    QTimer *timer_drop = new QTimer(this);
    connect(timer_drop, &QTimer::timeout, this, &waterDroplet::makeItRain);
    timer_drop->start(200);
}

//Method for producing many raindrops and deleting raindrops when they are out of the scene view
void waterDroplet::makeItRain(){
    qInfo("I'm in makeItRain method.");
    this->setPos(this->x(), this->y() + 10);
    if(this->y() > 510){
        qInfo("I'm in makeItRain if statement.");
        scene()->removeItem(this);
        qInfo("I'm in makeItRain, just removed item.");
        delete this;
    }else if(!collidingItems().isEmpty()){
        scene()->removeItem(this);
        delete this;
    }
}

