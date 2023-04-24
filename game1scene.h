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
}

gameLeves;
//Game scene class
class game1scene : public QGraphicsScene
{
    Q_OBJECT
private:
  bucket *bucketItem;
  waterDroplet *waterDropletItem;
  QTimer *spawnDropletsTimer;
  bool win;

public:
    game1scene();
    int waterDropletCounter;
    int points;
    int collectedWaterDroplets;


public slots:
    void generateDropletAndCount();
    void handleCollision();
};

#endif // GAME1SCENE_H
