//Lauryn C. Hansen
#include <QApplication>
#include <QGraphicsView>
#include "homescene.h"
#include "waterDroplet.h"

int main(int argc, char **argv){
    QApplication app (argc,argv);

    //create a view
     qInfo("About to create a view.");
     QGraphicsView* mainView = new QGraphicsView();

     //create a scene
     qInfo("About to create a scene.");
     homescene *mainScene = new homescene(mainView);

    //add the scene to the view
    mainView->setScene(mainScene);

    //main_view->setFixedSize(910, 512);
    //main_view->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));//to prevent scroll bars
    //main_view->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));//to prevent scroll bars

    //show the view
    qInfo("About to show the view.");
    mainView->show();

//    if (gameScene->points >= 150){
//        gameScene->addText("You Won!!!");
//    }

    return app.exec();
}






//add image items
//    QGraphicsPixmapItem *backgroundImage = new QGraphicsPixmapItem();
//    backgroundImage->setPixmap(QPixmap(":/images/background.jpg").scaled(300,300));
//    QGraphicsPixmapItem *personImage = new QGraphicsPixmapItem();
//    personImage->setPixmap(QPixmap(":/images/bucket.png").scaled(300,300));
//    QGraphicsPixmapItem *cloudImage = new QGraphicsPixmapItem();
//    cloudImage->setPixmap(QPixmap(":/images/cloud.png").scaled(300,300));
//    QGraphicsPixmapItem *waterImage = new QGraphicsPixmapItem();
//    waterImage->setPixmap(QPixmap(":/images/water.gif").scaled(300,300));
