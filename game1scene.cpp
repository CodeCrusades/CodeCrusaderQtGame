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
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QMediaPlayer>
#include <QGraphicsItem>
#include <QImage>
#include <QFont>
#include <QDate>

//Contructor
game1scene::game1scene(int level)
    : QGraphicsScene()
{
    this->level = level;

  //Add bucket
  bucketItem = new bucket();
  addItem(bucketItem);
  bucketItem->setPixmap(QPixmap(":/images/bucket.png").scaled(150, 150));
  bucketItem->setFlag(QGraphicsItem::ItemIsFocusable);
  bucketItem->setFocus();
  bucketItem->setPos(400, 365);

  //Add background
  //Change background to be a gif??????????
  setBackgroundBrush(QBrush(QImage(":/images/background.jpg").scaledToHeight(512) .scaledToWidth(910)));
  setSceneRect(0, 0, 908, 510);

  //Add the cloud
  cloud = new QGraphicsPixmapItem(QPixmap("://images/cloud.png").scaled(380,90));
  cloud->setPos(250, 0);
  addItem(cloud);

  points = new int(0);
  collectedWaterDroplets = new int(0);
  missedWaterDroplets = new int(0);
  missedFiveDroplet = false;
  win = false;

  //Add multiple droplets to game scence
  spawnDropletsTimer = new QTimer(this);
  connect(spawnDropletsTimer, &QTimer::timeout, this, &game1scene::generateDropletAndCount);
  //Create the level selection menu
  setGameLevel(level);

  //Slot to move the cloud
  flagToMoveCloudHorizontal = false;
  QTimer *cloudTimer = new QTimer(this);
  connect (cloudTimer, &QTimer::timeout, this, &game1scene::moveTheCloud);
  cloudTimer->start(1000);

  //Add background music
  QMediaPlayer *player = new QMediaPlayer();
  QAudioOutput *output = new QAudioOutput();
  player->setAudioOutput(output);
  player->setSource(QUrl("qrc:/sounds/8Bit Platformer Loop.wav"));
  output->setVolume(50);
  player->play();

}


//Method to generate a water droplet
void game1scene::generateDropletAndCount() {
  if (*points >= 15) {
      win = true;
      spawnDropletsTimer->stop();
      removeItem(bucketItem);
  }
    if (*missedWaterDroplets >= 5) {
        missedFiveDroplet = true;
        spawnDropletsTimer->stop();
    }
    qDebug() << "Points: " << *points << "\n" << "collectedWaterDroplets: " << *collectedWaterDroplets << "\n" << "missedWaterDroplets: " << *missedWaterDroplets << "\n";
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
//     QWidget *winWidget = new QWidget();
//     winWidget->move(320, 100);
//     winWidget->setStyleSheet("background-color:purple");

//     QVBoxLayout *layout = new QVBoxLayout;
//     QLabel *label = new QLabel("You won!");
//     label->setStyleSheet("font-size: 60px; font-family: Arial;");

     //Adding a winner picture
     QImage image(":/images/755t.gif");
     int newWidth = 908;
     int newHeight = 510;
     QImage resizedImage = image.scaled(newWidth,newHeight, Qt::KeepAspectRatio); // scaling the image while maintaining aspect ratio
     QGraphicsPixmapItem *imageWrapper = new QGraphicsPixmapItem(QPixmap::fromImage(resizedImage));
     imageWrapper->setPos(120,0);
     addItem(imageWrapper);

//     QPushButton *closeButton = new QPushButton("Close");
//     connect(closeButton, &QPushButton::clicked, winWidget, &QWidget::close);

//     layout->addWidget(label);
//     layout->addWidget(closeButton);

//     winWidget->setLayout(layout);
//     this->addWidget(winWidget);
     removeItem(bucketItem);

     return true;
}

//Method for displaying lose message
bool game1scene::displayLoseMessage() {
//     QWidget *loseWidget = new QWidget();
//     loseWidget->move(320, 100);
//     loseWidget->setStyleSheet("background-color:orange");
//     QVBoxLayout *layoutL = new QVBoxLayout;
//     QLabel *labelL = new QLabel("You lost!");
//     labelL->setStyleSheet("font-size: 60px; font-family: Arial;");
//     labelL->setStyleSheet("QLabel { background-color : orange color : blue; }");
//     QPushButton *closeButtonL = new QPushButton("Close");
//     connect(closeButtonL, &QPushButton::clicked, loseWidget, &QWidget::close);
//     layoutL->addWidget(labelL);
//     layoutL->addWidget(closeButtonL);
//     loseWidget->setLayout(layoutL);
//     this->addWidget(loseWidget);

     QImage image(":/images/Up8y.gif");
     int newWidth = 908;
     int newHeight = 510;
     QImage resizedImage = image.scaled(newWidth,newHeight, Qt::KeepAspectRatio); // scaling the image while maintaining aspect ratio
     QGraphicsPixmapItem *imageWrapper = new QGraphicsPixmapItem(QPixmap::fromImage(resizedImage));
     imageWrapper->setPos(30,0);
     addItem(imageWrapper);

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
     int cloudSpeed = 40; // adjust this value to change the speed of the cloud
     if(cloud->x() >= 600) flagToMoveCloudHorizontal = false;
     if(cloud->x() < 0 ) flagToMoveCloudHorizontal = true;

     if (!flagToMoveCloudHorizontal) {
      //left
      cloud->setPos(cloud->x() - cloudSpeed, cloud->y());
      qInfo() << "cloud moving to the left";
     } else {
      //right
      cloud->setPos(cloud->x() + cloudSpeed, cloud->y()); // update the position of the cloud sprite
      qInfo() << "cloud moving to the right";

     }
}
