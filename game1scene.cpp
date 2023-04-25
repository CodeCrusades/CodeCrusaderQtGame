//Lauryn C. Hansen
#include "game1scene.h"
#include "waterDroplet.h"
#include "bucket.h"
#include <QTimer>
#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QMenu>
#include <QActionGroup>
#include <QAudioOutput>
#include <QGraphicsItem>
#include <QImage>
#include <QFont>
#include <QDate>
#include <QMediaPlayer>
#include "parser.hpp"

//Contructor
game1scene::game1scene(int level, parser *parserObject)
    : QGraphicsScene()
{
    this->parserObject = parserObject;
    this->level = level;
    bucketItem = new bucket();
    addItem(bucketItem);
    bucketItem->setFlag(QGraphicsItem::ItemIsFocusable);
    bucketItem->setFocus();
    bucketItem->setPos(400, 400);

    // add background
    setBackgroundBrush(QBrush(QImage(":/images/8bit.jpg").scaledToHeight(512) .scaledToWidth(910)));
    setSceneRect(0, 0, 908, 510);

    // add the cloud
    cloud = new QGraphicsPixmapItem(QPixmap("://images/cloud.png").scaled(380,90));
    cloud->setPos(250, 0);
    addItem(cloud);

    //waterDropletCounter = 0;
    points = new int(0);
    collectedWaterDroplets = new int(0);
    missedWaterDroplets = new int(0);
    missedFiveDroplet = false;

    win = false;

    // add multiple droplets to game scence
    spawnDropletsTimer = new QTimer(this);
    connect(spawnDropletsTimer, &QTimer::timeout, this, &game1scene::generateDropletAndCount);
    // Create the level
    setGameLevel(level);

    // slot to move the cloud
    flagToMoveCloudHorizontal = false;
    QTimer *cloudTimer = new QTimer(this);
    connect (cloudTimer, &QTimer::timeout, this, &game1scene::moveTheCloud);
    cloudTimer->start(100);

    //Add background music
    player = new QMediaPlayer();
    output = new QAudioOutput();
    player->setAudioOutput(output);
    player->setSource(QUrl("qrc:/sounds/8Bit Platformer Loop.wav"));
    output->setVolume(50);
    player->play();

}


//Method to generate a water droplet
void game1scene::generateDropletAndCount() {
    if (*points >= 150) {
        win = true;
        spawnDropletsTimer->stop();
        removeItem(bucketItem);
        parserObject->updateUserScores(parserObject->user.value("UserName").toString(), *points);
        parserObject->storeIntoFile();
    }
    if (*missedWaterDroplets >= 5) {
        missedFiveDroplet = true;
        spawnDropletsTimer->stop();
        removeItem(bucketItem);
        parserObject->updateUserScores(parserObject->user.value("UserName").toString(), *points);
        parserObject->storeIntoFile();
    }

    waterDroplet *dropleeeet = new waterDroplet(points, collectedWaterDroplets, missedWaterDroplets);

    int random_number = arc4random() % 700;
    dropleeeet->setPos(random_number, 80); // x is set to 80 to make sure that droplets are generated beneath the cloud
    this->addItem(dropleeeet);

    if(missedFiveDroplet){
        displayLoseMessage();
    }
    if(win) {
        displayWinMessage();
    }
}

//Method for displaying win message
bool game1scene::displayWinMessage() {

     //Adding a winner picture
     QImage image(":/images/755t.gif");
     int newWidth = 908;
     int newHeight = 510;
     QImage resizedImage = image.scaled(newWidth,newHeight, Qt::KeepAspectRatio); // scaling the image while maintaining aspect ratio
     QGraphicsPixmapItem *imageWrapper = new QGraphicsPixmapItem(QPixmap::fromImage(resizedImage));
     imageWrapper->setPos(120,0);
     addItem(imageWrapper);
     player->setSource(QUrl("qrc:/sounds/win.wav"));
     player->play();
     removeItem(bucketItem);

     return true;
}

//Method for displaying lose message
bool game1scene::displayLoseMessage() {
     QImage image(":/images/Up8y.gif");
     int newWidth = 908;
     int newHeight = 510;
     QImage resizedImage = image.scaled(newWidth,newHeight, Qt::KeepAspectRatio); // scaling the image while maintaining aspect ratio
     QGraphicsPixmapItem *imageWrapper = new QGraphicsPixmapItem(QPixmap::fromImage(resizedImage));
     imageWrapper->setPos(30,0);
     addItem(imageWrapper);
      player->setSource(QUrl("qrc:/sounds/endgame.wav"));
     player->play();
     removeItem(bucketItem);
     return true;
}

// Method to select game level => we may adjust the timer accordingly
void game1scene::setGameLevel(int level) {
     switch (level) {
        case 0:
      spawnDropletsTimer->start(1500);
      break;
        case 1:
      spawnDropletsTimer->start(1000);
      break;
        case 2:
      spawnDropletsTimer->start(500);
      break;
     }
}

//Method to move the cloud
void game1scene:: game1scene::moveTheCloud() {
     // Move the cloud horizontally
     int cloudSpeed = 1;
     if(cloud->x() >= 600) flagToMoveCloudHorizontal = false;
     if(cloud->x() < 0 ) flagToMoveCloudHorizontal = true;

     if (!flagToMoveCloudHorizontal) {
      //left
      cloud->setPos(cloud->x() - cloudSpeed, cloud->y());
     } else {
      //right
      cloud->setPos(cloud->x() + cloudSpeed, cloud->y());
     }
}
