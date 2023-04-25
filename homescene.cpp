#include "homescene.h"
#include "signinscene.h"
#include "signupscene.h"
#include "welcomescene.h"

homescene::homescene(QGraphicsView *view) : QGraphicsScene(), mainView(view) {
    //Add background
    setBackgroundBrush(QBrush(QImage(":/images/homeScreen.jpg").scaledToHeight(512) .scaledToWidth(910)));
    setSceneRect(0,0,908,510);

    //Other scenes
    signInPage = new signInScene(mainView);
    signUpPage = new signUpScene(mainView);
    welcomeScene1 = new welcomeScene(mainView);

    //Add sign in button
    QPushButton* signInButton;
    QGraphicsProxyWidget* signInWidget;

    signInButton = new QPushButton();
    signInWidget = new QGraphicsProxyWidget();
    signInWidget->setWidget(signInButton);

    signInButton->setText("Sign In");
    signInWidget->setPos(425, 250);
    signInWidget->setAutoFillBackground(false);

    signInButton->setStyleSheet("background-color: blue");

    addItem(signInWidget);

    //Use button to go from one scene to the next
    QObject::connect(signInButton, &QPushButton::clicked, [=]() {
        mainView->setScene(signInPage);
    });

    //Add sign up button
    QPushButton* signUpButton;
    QGraphicsProxyWidget* signUpWidget;

    signUpButton = new QPushButton();
    signUpWidget = new QGraphicsProxyWidget();
    signUpWidget->setWidget(signUpButton);

    signUpButton->setText("Sign Up");
    signUpWidget->setPos(425, 300);
    signUpButton->setStyleSheet("background-color: green;");
    signUpWidget->setAutoFillBackground(false);

    addItem(signUpWidget);

    QObject::connect(signUpButton, &QPushButton::clicked, [=]() {
        mainView->setScene(signUpPage);
    });

    //Add continue as guest button
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

    addItem(guestWidget);

    //Button taking us to sign in page
    connect(signInButton, &QPushButton::clicked, this, &homescene::onSignInButtonClicked);

    //Button taking us to sign up page
    connect(signUpButton, &QPushButton::clicked, this, &homescene::onSignUpButtonClicked);

    //Button taking us to guest page
    connect(guestButton, &QPushButton::clicked, this, &homescene::onGuestButtonClicked);

}

void homescene::onSignInButtonClicked() {
    mainView->setScene(signInPage);
}

void homescene::onSignUpButtonClicked(){
    mainView->setScene(signUpPage);
}
void homescene::onGuestButtonClicked(){
    mainView->setScene(welcomeScene1);
}
