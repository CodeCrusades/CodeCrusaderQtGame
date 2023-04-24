//Lauryn C. Hansen
#ifndef GAME1SCENE_H
#define GAME1SCENE_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "bucket.h"
#include "waterDroplet.h"
#include <QObject>

// game levels.
typedef enum {
    Easy,
    Medium,
    Hard
}gameLevels;

//Game scene class
class game1scene : public QGraphicsScene
{
    Q_OBJECT
private:
  bucket *bucketItem;
  waterDroplet *waterDropletItem;
  QTimer *spawnDropletsTimer;
  int missedDropletCount;
  bool win;
  bool missedFiveDroplet;
  bool flagToMoveCloudHorizontal;
  QGraphicsPixmapItem *cloud;
public:
    game1scene();
    int waterDropletCounter;
    int points;
    int collectedWaterDroplets;


public slots:
    void generateDropletAndCount();
    void handleCollision();
    bool displayWinMessage();
    void createLevelSelectionMenu();
    void setGameLevel(gameLevels level); // set the level of the game
    void moveTheCloud();
};

#endif // GAME1SCENE_H
