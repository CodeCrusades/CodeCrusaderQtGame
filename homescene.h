#ifndef HOMESCENE_H
#define HOMESCENE_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

class homescene: public QGraphicsScene
{
    Q_OBJECT

private:
    QGraphicsTextItem* signIn;
    QGraphicsTextItem* signUp;
    QGraphicsTextItem* guest;

public:
    homescene();
};

#endif // HOMESCENE_H
