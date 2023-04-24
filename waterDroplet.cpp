//Lauryn C. Hansen
#include "waterDroplet.h"
#include <QTimer>
#include<QGraphicsItem>

//Other Constructor lol
waterDroplet::waterDroplet(int *points, int *collectedWaterDroplets, int *missedWaterDroplets) {
  missedFiveDroplet = false;
  this->setPixmap((QPixmap(":/images/water.gif")).scaled(30, 30));
  timer_drop = new QTimer(this);
  connect(timer_drop, &QTimer::timeout, this, &waterDroplet::makeItRain);
  timer_drop->start(200);
  player = new QMediaPlayer();
  output = new QAudioOutput();
  player->setAudioOutput(output);
  player->setSource(QUrl("qrc:/sounds/029_Decline_09.wav"));
  this->points = points;
  this->collectedWaterDroplets = collectedWaterDroplets;
  this->missedWaterDroplets = missedWaterDroplets;
}

//Method for producing many raindrops and deleting raindrops when they are out of the scene view or if they collide
void waterDroplet::makeItRain(){
    this->setPos(this->x(), this->y() + 10);
    if(this->y() > 510){
       scene()->removeItem(this);
        *missedWaterDroplets += 1;
       delete this;

    }else if(!collidingItems().isEmpty()){
        player->play();
        scene()->removeItem(this);
        *points = *points + 5;
        *collectedWaterDroplets += 1;
        delete this;
   }
}
