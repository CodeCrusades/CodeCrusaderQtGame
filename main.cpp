//Lauryn C. Hansen
#include <QApplication>
#include <QGraphicsView>
#include "game1scene.h"
#include "homescene.h"
#include "signinscene.h"
#include "signupscene.h"
#include <QMediaPlayer>


int main(int argc, char **argv){
    QApplication app (argc,argv);

    //create a scene
     qInfo("About to create a scene.");
    homescene *mainScene = new homescene();
    signInScene *signInPage = new signInScene();
    signUpScene *signUpPage = new signUpScene();
    game1scene *gameScene = new game1scene();

    //create a view
    qInfo("About to create a view.");
    QGraphicsView *main_view = new QGraphicsView();

     //add sign in button
    QPushButton* signInButton;
    QGraphicsProxyWidget* signInWidget;

    signInButton = new QPushButton();
    signInWidget = new QGraphicsProxyWidget();
    signInWidget->setWidget(signInButton);

    signInButton->setText("Sign In");
    signInWidget->setPos(425, 250);
    signInWidget->setAutoFillBackground(false);

    signInButton->setStyleSheet("background-color: blue");

    mainScene->addItem(signInWidget);

    //use button to go from one scene to the next
    QObject::connect(signInButton, &QPushButton::clicked, [=]() {
        main_view->setScene(signInPage);
    });

    //add sign up button
    QPushButton* signUpButton;
    QGraphicsProxyWidget* signUpWidget;

    signUpButton = new QPushButton();
    signUpWidget = new QGraphicsProxyWidget();
    signUpWidget->setWidget(signUpButton);

    signUpButton->setText("Sign Up");
    signUpWidget->setPos(425, 300);
    signUpButton->setStyleSheet("background-color: green;");
    signUpWidget->setAutoFillBackground(false);

    mainScene->addItem(signUpWidget);

    QObject::connect(signUpButton, &QPushButton::clicked, [=]() {
        main_view->setScene(signUpPage);
    });

    //add continue as guest button
    QPushButton* guestButton;
    QGraphicsProxyWidget* guestWidget;

    guestButton = new QPushButton();
    guestWidget = new QGraphicsProxyWidget();
    guestWidget->setWidget(guestButton);

    guestButton->setText("Continue as Guest");
    guestButton->resize(135, 35);
    guestWidget->setPos(400, 350);
    guestButton->setStyleSheet("background-color: grey;");
    guestWidget->setAutoFillBackground(false);
    guestWidget->resize(135, 35);

    mainScene->addItem(guestWidget);

    QObject::connect(guestButton, &QPushButton::clicked, [=]() {
        main_view->setScene(gameScene);
    });

    //add the scene to the view
    main_view->setScene(mainScene);

    //main_view->setFixedSize(910, 512);
    //main_view->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));//to prevent scroll bars
    //main_view->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));//to prevent scroll bars

    //show the view
    qInfo("About to show the view.");
    main_view->show();


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
