//Lauryn C. Hansen
#include "bucket.h"

//Constructor
bucket::bucket(QObject *parent) : QObject{parent}{
    setPixmap(QPixmap(":/images/bucket.png").scaled(300,300));
}

//Method for moving person with bucket left and right using arrows
void bucket::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt :: Key_Right){
    //keep the item current y position the same and increment x position in the positive direction
        setPos((x() + 15), y());
    }
    else if (event->key() == Qt :: Key_Left){
    //keep the item current y position the same and increment x position in the negative direction
        setPos((x() - 15), y());
    }
}
