#ifndef WELCOMESCENE_H
#define WELCOMESCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTextEdit>
#include <QGraphicsProxyWidget>
#include <QPushButton>


class welcomeScene: public QGraphicsScene
{
    Q_OBJECT

private:
    QGraphicsTextItem* welcomeText;
    QGraphicsPixmapItem* imageHolder;

public:
    welcomeScene();

};

#endif // WELCOMESCENE_H
