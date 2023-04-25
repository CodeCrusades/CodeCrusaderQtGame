//Lauryn C. Hansen
#include "bucket.h"

//Constructor
bucket::bucket(QObject *parent) : QObject{parent}{
    setPixmap(QPixmap(":/images/marioRight.png").scaled(100,100));
}

//Method for moving person with bucket left and right using arrows
void bucket::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt :: Key_Right){
        //Change the image to face right, then update position
        setPixmap(QPixmap(":/images/marioRight.png").scaled(100,100));
        setPos((x() + 15), y());
    }
    else if (event->key() == Qt :: Key_Left){
        //Change the image to face left, then update position
        setPixmap(QPixmap(":/images/marioLeft.png").scaled(100,100));
        setPos((x() - 15), y());
    }
}
