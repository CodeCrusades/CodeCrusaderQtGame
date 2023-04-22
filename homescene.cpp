#include "homescene.h"

homescene::homescene()
{
    //add background
    setBackgroundBrush(QBrush(QImage(":/images/homeScreen.jpg").scaledToHeight(512) .scaledToWidth(910)));
    setSceneRect(0,0,908,510);

    //add labels, set positions, fonts, etc.
    //sign in
    signIn = new QGraphicsTextItem();
    addItem(signIn);
    signIn->setPlainText("Sign In");
    signIn->setPos(400, 300);
    signIn->setDefaultTextColor(Qt::black);
    QFont font("Times New Roman", 20);
    signIn->setFont(font);

    //sign up
    signUp = new QGraphicsTextItem();
    addItem(signUp);
    signUp->setPlainText("Sign Up");
    signUp->setPos(397, 340);
    signUp->setDefaultTextColor(Qt::black);
    signUp->setFont(font);

    //guest
    guest = new QGraphicsTextItem();
    addItem(guest);
    guest->setPlainText("Continue as Guest");
    guest->setPos(360, 380);
    guest->setDefaultTextColor(Qt::black);
    guest->setFont(font);

}
