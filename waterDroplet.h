//Lauryn C. Hansen
#ifndef FALLINGWATER_H
#define FALLINGWATER_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>

//Water droplet class
class waterDroplet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit waterDroplet(QObject *parent = nullptr);
    int missedDropletCount;

signals:

public slots:
    void makeItRain();
};

#endif // FALLINGWATER_H
