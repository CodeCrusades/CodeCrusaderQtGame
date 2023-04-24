//Lauryn C. Hansen
#ifndef FALLINGWATER_H
#define FALLINGWATER_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>

//Water droplet class
class waterDroplet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit waterDroplet(QObject *parent = nullptr);
    int missedDropletCount;
    bool missedFiveDroplet;
    QMediaPlayer *player;
    QAudioOutput *output;

signals:

public slots:
    void makeItRain();
};

#endif // FALLINGWATER_H
