//Lauryn C. Hansen
#include "game1scene.h"
#include "waterDroplet.h"
#include <QTimer>
#include <QObject>
#include<QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QMenu>
#include <QActionGroup>



//Contructor
game1scene::game1scene() {
  // add bucket
  bucketItem = new bucket();
  addItem(bucketItem);
  bucketItem->setPixmap(QPixmap(":/images/bucket.png").scaled(150, 150));
  bucketItem->setFlag(QGraphicsItem::ItemIsFocusable);
  bucketItem->setFocus();
  bucketItem->setPos(400, 365);

  // add background
  setBackgroundBrush(QBrush(QImage(":/images/background.jpg").scaledToHeight(512) .scaledToWidth(910)));
  setSceneRect(0, 0, 908, 510);

  // add the cloud
  cloud = new QGraphicsPixmapItem(QPixmap("://images/cloud.png").scaled(380,90));
  cloud->setPos(250, 0);
  addItem(cloud);

  waterDropletCounter = 0;
  points = 0;

  missedDropletCount = 0;
  missedFiveDroplet = false;

  // based on how code is set up, we might not need this waterDropletItem in the gamescene constructor (droplets were created in the generateDropletAndCount()
  waterDropletItem = new waterDroplet();
  int random_number = arc4random() % 700;
  waterDropletItem->setPos(random_number, 80);

  addItem(waterDropletItem);

  win = false;

  QTimer *timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &game1scene::handleCollision);
  timer->start(100);

  // add multiple droplets to game scence
  spawnDropletsTimer = new QTimer(this);
  connect(spawnDropletsTimer, &QTimer::timeout, this, &game1scene::generateDropletAndCount);
  // Create the level selection menu
  createLevelSelectionMenu();

  // slot to move the cloud
  flagToMoveCloudHorizontal = false;
  QTimer *cloudTimer = new QTimer(this);
  connect (cloudTimer, &QTimer::timeout, this, &game1scene::moveTheCloud);
  cloudTimer->start(1000);
}


//Method to generate a water droplet
void game1scene::generateDropletAndCount() {
    if (missedDropletCount >= 5) {
        missedFiveDroplet = true;
    }

    waterDroplet *dropleeeet = new waterDroplet();
    int random_number = arc4random() % 700;
    dropleeeet->setPos(random_number, 80); // x is set to 80 to make sure that droplets are generated beneath the cloud
    this->addItem(dropleeeet);
}

// on drop collision remove the droplet from the scene and get extra points
void game1scene::handleCollision() {

    if (points >= 150) {
        win = true;
    }
    qDebug() << "Points incremented to: " << points;
    // check for collision of droplets with bucket
    QList<QGraphicsItem *> collisions = collidingItems(bucketItem);
    for (int i = 0; i < collisions.size(); i++) {
        QGraphicsItem *item = collisions.at(i);

        if (item->type() == waterDroplet::Type) { // if the item collided with a bucket is a type waterDroplet, increment the points and remove droplet from scence
          waterDroplet *droplet = qgraphicsitem_cast<waterDroplet *>(item);
          removeItem(droplet);
          points = points + 5;
          qDebug() << "Points incremented to: " << points; // add debug output
          delete droplet;
        }
    }

    // if points >= 150 display the winning message
    if (win) {
        displayWinMessage();
    }
}

bool game1scene::displayWinMessage() {
     QWidget *winWidget = new QWidget();
     winWidget->move(200, 200);
     QVBoxLayout *layout = new QVBoxLayout;
     QLabel *label = new QLabel("Congratulations, you won!");
     QPushButton *closeButton = new QPushButton("Close");
     QPushButton *PlayAgain = new QPushButton("Play Again");

     connect(closeButton, &QPushButton::clicked, winWidget, &QWidget::close);
     connect(closeButton, &QPushButton::clicked, winWidget, &QWidget::close);

     layout->addWidget(label);
     layout->addWidget(closeButton);
     layout->addWidget(PlayAgain);

     winWidget->setLayout(layout);
     this->addWidget(winWidget);

     removeItem(bucketItem);
//     removeItem(waterDropletItem);

     // TODO figure out how to remove the water droplets from scene after winning. Since droplets are not part of gameScence constructor is bit trickier to remove them.
     return true;
}

// method to select game level => we may adjust the timer accordingly
void game1scene::setGameLevel(gameLevels level) {
     switch (level) {
     case Easy:
      spawnDropletsTimer->start(1500);
      break;
     case Medium:
      spawnDropletsTimer->start(1000);
      break;
     case Hard:
      spawnDropletsTimer->start(500);
      break;
     }
}

//method to create the level menu. This method will be likely moved to Welcoming Scene and be adjusted accordingly. Notes to from Gloria to Reshma
void game1scene::createLevelSelectionMenu() {
     // Add a menu to select the level
     QMenu *levelMenu = new QMenu;
     QActionGroup *levelGroup = new QActionGroup(levelMenu);
     QAction *easyAction = levelMenu->addAction("Easy");
     easyAction->setCheckable(true);
     easyAction->setActionGroup(levelGroup);
     QAction *mediumAction = levelMenu->addAction("Medium");
     mediumAction->setCheckable(true);
     mediumAction->setActionGroup(levelGroup);
     QAction *hardAction = levelMenu->addAction("Hard");
     hardAction->setCheckable(true);
     hardAction->setActionGroup(levelGroup);

     // Set the default level to Easy
     easyAction->setChecked(true);
     setGameLevel(Easy);

     // Connect the level actions to the setLevel() slot
     connect(easyAction, &QAction::triggered, this, [this]() { setGameLevel(Easy); });
     connect(mediumAction, &QAction::triggered, this, [this]() { setGameLevel(Medium); });
     connect(hardAction, &QAction::triggered, this, [this]() { setGameLevel(Hard); });
}

void game1scene::moveTheCloud() {
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
