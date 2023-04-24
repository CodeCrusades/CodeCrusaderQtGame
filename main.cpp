//Lauryn C. Hansen
#include <QApplication>
#include <QGraphicsView>
#include "homescene.h"

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

    //show the view
    qInfo("About to show the view.");
    mainView->show();

    return app.exec();
}
