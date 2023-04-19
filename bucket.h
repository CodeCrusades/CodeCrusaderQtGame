//Lauryn C. Hansen
#ifndef BUCKET_H
#define BUCKET_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QObject>

//Bucket class
class bucket : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    explicit bucket(QObject *parent = nullptr);
    void keyPressEvent(QKeyEvent *event);
signals:
};

#endif // BUCKET_H
