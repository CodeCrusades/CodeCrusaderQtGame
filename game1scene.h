//Lauryn C. Hansen
#ifndef GAME1SCENE_H
#define GAME1SCENE_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>

class waterDroplet;
class bucket;

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
  int level;
  //QVector<waterDroplet*> *allDrops;

public:
    game1scene(int level);
    //int waterDropletCounter;
    int *points;
    int *collectedWaterDroplets;
    int *missedWaterDroplets;


public slots:
    void generateDropletAndCount();
//    void handleCollision();
    bool displayWinMessage();
    bool displayLoseMessage();
    void setGameLevel(int level); // set the level of the game
    void moveTheCloud();
};

#endif // GAME1SCENE_H
