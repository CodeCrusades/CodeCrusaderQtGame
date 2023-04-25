#include "signinscene.h"
#include "QtWidgets/qboxlayout.h"
#include "welcomescene.h"
#include "parser.hpp"
#include <QGraphicsView>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

signInScene::signInScene(QGraphicsView *view, parser *parserObject) : QGraphicsScene(), mainView(view) {
    //welcome page
    this->parserObject = parserObject;

    //Initialize avatar selection (default 0)
    avatarSelection = 0;

    //Add background
    setBackgroundBrush(QBrush(QColor(220, 240, 255), Qt::SolidPattern));
    setSceneRect(0,0,908,510);

    //Add text edit space for user to type in their username
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

    //Add avatar selection
    QGroupBox *avatar = new QGroupBox();
    QHBoxLayout *avatarLayout = new QHBoxLayout();
    avatar->setStyleSheet("background-color: rgb(220, 240, 255);");
    avatar->move(300, 100);
    QPushButton *image1 = new QPushButton();
    image1->setIcon(QPixmap::fromImage(QImage(":/profilePictures/orange.png")));
    image1->setIconSize(QSize(50, 50));
    avatarLayout->addWidget(image1);
    QPushButton *image2 = new QPushButton();
    image2->setIcon(QPixmap::fromImage(QImage(":/profilePictures/correctdeathstar.png")));
    image2->setIconSize(QSize(50, 50));
    avatarLayout->addWidget(image2);
    QPushButton *image3 = new QPushButton();
    image3->setIcon(QPixmap::fromImage(QImage(":/profilePictures/unicorn.png")));
    image3->setIconSize(QSize(50, 50));
    avatarLayout->addWidget(image3);
    QPushButton *image4 = new QPushButton();
    image4->setIcon(QPixmap::fromImage(QImage(":/profilePictures/trinity.png")));
    image4->setIconSize(QSize(50, 50));
    avatarLayout->addWidget(image4);
    avatar->setLayout(avatarLayout);
    addWidget(avatar);

    //Add text edit space for user to type in their password
    password = new QGraphicsTextItem();
    passwordEdit = new QLineEdit();
    passwordEdit->setEchoMode(QLineEdit::Password);
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

    //Check for avatarSelection
    connect(image1, &QPushButton::clicked, this, &signInScene::onImageOne);
    connect(image2, &QPushButton::clicked, this, &signInScene::onImageTwo);
    connect(image3, &QPushButton::clicked, this, &signInScene::onImageThree);
    connect(image4, &QPushButton::clicked, this, &signInScene::onImageFour);

    //Button taking us to welcome page
    connect(login, &QPushButton::clicked, this, &signInScene::onLoginButtonClicked);

    //Spawning error message if a wrong password is entered
    errorMessage = new QGraphicsTextItem();
    errorMessage->setDefaultTextColor(Qt::black);
    errorMessage->setPlainText("Wrong username or password");
}

void signInScene::onLoginButtonClicked() {
   //if the username exists and their password is correct, log in player aka go to welcome screen
    if(parserObject->userExists(usernameEdit->toPlainText()) && parserObject->userPasswordMatches(usernameEdit->toPlainText(), passwordEdit->text())){
        parserObject->user = parserObject->retrieveUserProfile(usernameEdit->toPlainText(), passwordEdit->text());
        bool bday = hasBirthdayToday();
        welcomeScene1 = new welcomeScene(mainView, parserObject, avatarSelection, bday);
        mainView->setScene(welcomeScene1);
    }
    else{
        addItem(errorMessage);
    }
}

bool::signInScene::hasBirthdayToday() {
    // find today's date
    QString todayDate = QDate::currentDate().toString("MMdd"); // get the current day,month,year
    QString userBday = parserObject->user.value("Birthday").toString();
    if((QString::compare(todayDate, userBday, Qt::CaseInsensitive)) == 0) { // TODO verify that the userBirthdateString is in the format of MMdd (without the year plz)
        return true;// if it matches then happy birthday
    }
    return false;
}
