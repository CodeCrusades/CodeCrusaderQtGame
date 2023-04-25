//Lauryn C. Hansen
#ifndef GAME1SCENE_H
#define GAME1SCENE_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QMediaPlayer>


class waterDroplet;
class bucket;
class parser;

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
  QMediaPlayer *player;
  QAudioOutput *output;
  int level;
  QGraphicsTextItem* livePoints;
  QString pointString;
  QGraphicsRectItem* displayScoreRect;
  QGraphicsTextItem* scoreText;


public:
    parser *parserObject;
    game1scene(int level, parser *parserObject);
    int *points;
    int *collectedWaterDroplets;
    int *missedWaterDroplets;


public slots:
    void generateDropletAndCount();
    bool displayWinMessage();
    bool displayLoseMessage();
    void setGameLevel(int level);
    void moveTheCloud();
    void updateScoreDisplay();
};

#endif // GAME1SCENE_H
