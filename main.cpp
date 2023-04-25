//Lauryn C. Hansen
#include <QApplication>
#include <QGraphicsView>
#include "homescene.h"

int main(int argc, char **argv){
    QApplication app (argc,argv);

    //Create a view
     qInfo("About to create a view.");
     QGraphicsView* mainView = new QGraphicsView();

     //Create a scene
     qInfo("About to create a scene.");
     homescene *mainScene = new homescene(mainView);

    //Add the scene to the view
    mainView->setScene(mainScene);

    //Show the view
    qInfo("About to show the view.");
    mainView->show();

    return app.exec();
}
