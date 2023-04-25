//Lauryn C. Hansen
#include <QApplication>
#include <QGraphicsView>
#include "homescene.h"
#include "parser.hpp"

int main(int argc, char **argv){
    QApplication app (argc,argv);

    //Create a parser object
    parser *parserObject = new parser();

    //Create a view
     qInfo("About to create a view.");
     QGraphicsView* mainView = new QGraphicsView();

     //Create a scene
     qInfo("About to create a scene.");
     homescene *mainScene = new homescene(mainView, parserObject);

    //Add the scene to the view
    mainView->setScene(mainScene);

    //Show the view
    qInfo("About to show the view.");
    mainView->show();

    return app.exec();
}
