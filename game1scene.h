//Lauryn C. Hansen
#ifndef GAME1SCENE_H
#define GAME1SCENE_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "bucket.h"
#include "waterDroplet.h"
#include <QObject>

//Game scene class
class game1scene : public QGraphicsScene
{
    Q_OBJECT
private:
    bucket *bucketItem;
    waterDroplet *waterDropletItem;
    QTimer *spawnDropletsTimer;

public:
    game1scene();

public slots:
    void generateDroplet();

};

#endif // GAME1SCENE_H
