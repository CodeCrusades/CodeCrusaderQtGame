#include "signinscene.h"

signInScene::signInScene()
{
    //add background
    setBackgroundBrush(QBrush(QColor(220, 240, 255), Qt::SolidPattern));
    setSceneRect(0,0,908,510);

    //add text edit space for user to type in their username
    username = new QGraphicsTextItem();
    usernameEdit = new QTextEdit();
    usernameWidget = new QGraphicsProxyWidget();
    usernameWidget->setWidget(usernameEdit);

    username->setPlainText("username: ");
    username->setPos(300, 245);
    username->setDefaultTextColor(Qt::black);
    QFont font("Times New Roman", 20);
    username->setFont(font);

    usernameWidget->setPos(200, 25);
    usernameWidget->setPreferredSize(200, 25);
    QRect usernameEditSpace(400,250,200,25);
    usernameEdit->setGeometry(usernameEditSpace);
    usernameEdit->setStyleSheet("background-color: white; color: black;");

    addItem(username);
    addItem(usernameWidget);

    //add text edit space for user to type in their password
    password = new QGraphicsTextItem();
    passwordEdit = new QTextEdit();
    passwordWidget = new QGraphicsProxyWidget();
    passwordWidget->setWidget(passwordEdit);

    password->setPlainText("password: ");
    password->setPos(300, 295);
    password->setDefaultTextColor(Qt::black);
    password->setFont(font);

    passwordWidget->setPos(300, 25);
    passwordWidget->setPreferredSize(200, 25);
    QRect passwordEditSpace(400,300,200,25);
    passwordEdit->setGeometry(passwordEditSpace);
    passwordEdit->setStyleSheet("background-color: white; color: black;");

    addItem(password);
    addItem(passwordWidget);

    login = new QPushButton();
    loginWidget = new QGraphicsProxyWidget();
    loginWidget->setWidget(login);

    login->setText("Login");
    loginWidget->setPos(425, 375);
    login->setStyleSheet("background-color: grey;");
    loginWidget->setAutoFillBackground(false);

    addItem(loginWidget);

}