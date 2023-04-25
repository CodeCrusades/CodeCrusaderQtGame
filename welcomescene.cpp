#include "welcomescene.h"
#include "game1scene.h"
#include "parser.hpp"
#include <QImage>
#include <QFont>
#include <QDate>
#include <QString>

welcomeScene::welcomeScene(QGraphicsView *view, QJsonObject user) : QGraphicsScene(), mainView(view) {
    //Add background
    setBackgroundBrush(QBrush(QColor(220, 240, 255), Qt::SolidPattern));
    setSceneRect(0,0,908,510);
    qInfo("Entered welcomeScene");
//    this->parserObject = parserObject;

    //Avatar selection
    this->avatarSelection = avatarSelection;

    //Fonts
    QFont welcomeFont("Georgia", 50);
    QFont birthdayFont("Garamond", 30);
    birthdayFont.setStyle(QFont::StyleItalic);
    QFont scoreFont("Courier New", 20);
    QFont playFont("Courier New", 30);
    playFont.setBold(true);
    QFont buttonFont("Futura", 20);

    //Set welcome scene text
    welcomeText = new QGraphicsTextItem();
    welcomeText->setPlainText("Welcome!");
    welcomeText->setPos(310, 40);
    welcomeText->setDefaultTextColor(Qt::black);
    welcomeText->setFont(welcomeFont);
    addItem(welcomeText);

    //Adding a profile picture
    QImage image;
    switch (avatarSelection) {
    case 0:
        image = QImage(":/profilePictures/orange.png");
        break;
    case 1:
        image = QImage(":/profilePictures/correctdeathstar.png");
        break;
    case 2:
        image = QImage(":/profilePictures/unicorn.png");
        break;
    case 3:
        image = QImage(":/profilePictures/trinity.png");
        break;
    }
    int newWidth = 100;
    int newHeight = 100;
    QImage resized_image = image.scaled(newWidth,newHeight, Qt::KeepAspectRatio); // scaling the image while maintaining aspect ratio
    imageHolder = new QGraphicsPixmapItem(QPixmap::fromImage(resized_image));
    imageHolder->setPos(375, 100);
    addItem(imageHolder);

    //Optional birthday greeting
    birthdayGreeting = new QGraphicsTextItem();
    birthdayGreeting->setPlainText("Happy Birthday!");
    birthdayGreeting->setPos(320, 210);
    birthdayGreeting->setDefaultTextColor(Qt::red);
    birthdayGreeting->setFont(birthdayFont);
    if(hasBirthdayToday(user.value("Birthday").toString())){
        addItem(birthdayGreeting);
    }

    //Displaying the best scores
    int sceneHeight = 510;
    int scoreRectWidth = 200;
    int scoreRectHeight = 150;
    int scoreRectX = 5;
    int scoreRectY = sceneHeight - scoreRectHeight - 5;
    scoreRect = new QGraphicsRectItem(scoreRectX, scoreRectY, scoreRectWidth, scoreRectHeight);
    QBrush rectBrush(Qt::white);
    scoreRect->setBrush(rectBrush);
    addItem(scoreRect);

    bestScoreLabel = new QGraphicsTextItem();
    qDebug() << "\tUSER FIRST NAME: " << user.value("FirstName");
    qDebug() << "\tUSER BEST GAME: " << user.value("BestGame");

    bestScoreLabel->setPlainText("High Score: " + QString::number(user.value("BestGame").toInt()));
    bestScoreLabel->setPos(scoreRect->boundingRect().topLeft() + QPointF (10,10));
    bestScoreLabel->setDefaultTextColor(Qt::black);
    bestScoreLabel->setFont(scoreFont);
    addItem(bestScoreLabel);

    QString qstringTest = user.value("lastGame").toString();
    qInfo() << "bestScore1: " << "qstringTest: " << qstringTest;
    bestScore1 = new QGraphicsTextItem();
    bestScore1->setPlainText("Game1: " + QString::number(user.value("lastGame").toInt()));
    bestScore1->setPos(scoreRect->boundingRect().topLeft() + QPointF (40,50));
    bestScore1->setDefaultTextColor(Qt::black);
    bestScore1->setFont(scoreFont);
    addItem(bestScore1);

    bestScore2 = new QGraphicsTextItem();
    bestScore2->setPlainText("Game2: " + QString::number(user.value("2GamesAgo").toInt()));
    bestScore2->setPos(scoreRect->boundingRect().topLeft() + QPointF (40,80));
    bestScore2->setDefaultTextColor(Qt::black);
    bestScore2->setFont(scoreFont);
    addItem(bestScore2);

    bestScore3 = new QGraphicsTextItem();
    bestScore3->setPlainText("Game3: " + QString::number(user.value("3GamesAgo").toInt()));
    bestScore3->setPos(scoreRect->boundingRect().topLeft() + QPointF (40,110));
    bestScore3->setDefaultTextColor(Qt::black);
    bestScore3->setFont(scoreFont);
    addItem(bestScore3);

    //Displaying levels
    int levelRectWidth = 250;
    int levelRectHeight = 220;
    int sceneWidth = 908;
    int levelRectX = sceneWidth - levelRectWidth - 5;
    int levelRectY = sceneHeight - levelRectHeight - 5;
    levelRect = new QGraphicsRectItem(levelRectX, levelRectY, levelRectWidth, levelRectHeight);
    QBrush levelRectBrush(Qt::darkCyan);
    levelRect->setBrush(levelRectBrush);
    addItem(levelRect);
    play = new QGraphicsTextItem();
    play->setPlainText("PLAY");
    play->setPos(levelRect->boundingRect().topLeft() + QPointF (80,10));
    play->setDefaultTextColor(Qt::yellow);
    play->setFont(playFont);
    addItem(play);

    easy = new QPushButton();
    easyWidget = new QGraphicsProxyWidget();
    easyWidget->setWidget(easy);

    easy->setText("Easy");
    easy->setFont(buttonFont);
    easyWidget->setPos(levelRect->boundingRect().topLeft() + QPointF (80,70));
    easy->setStyleSheet("background-color: grey;");
    easyWidget->setAutoFillBackground(false);

    addItem(easyWidget);

    medium = new QPushButton();
    mediumWidget = new QGraphicsProxyWidget();
    mediumWidget->setWidget(medium);

    medium->setText("Medium");
    medium->setFont(buttonFont);
    mediumWidget->setPos(levelRect->boundingRect().topLeft() + QPointF (77,120));
    medium->setStyleSheet("background-color: grey;");
    mediumWidget->setAutoFillBackground(false);

    addItem(mediumWidget);

    hard = new QPushButton();
    hardWidget = new QGraphicsProxyWidget();
    hardWidget->setWidget(hard);

    hard->setText("Hard");
    hard->setFont(buttonFont);
    hardWidget->setPos(levelRect->boundingRect().topLeft() + QPointF (80,170));
    hard->setStyleSheet("background-color: grey;");
    hardWidget->setAutoFillBackground(false);

    addItem(hardWidget);

    //button taking us to sign in page
    connect(easy, &QPushButton::clicked, this, &welcomeScene::onEasyButtonClicked);

    //button taking us to sign up page
    connect(medium, &QPushButton::clicked, this, &welcomeScene::onMediumButtonClicked);

    //button taking us to guest page
    connect(hard, &QPushButton::clicked, this, &welcomeScene::onHardButtonClicked);
}

void welcomeScene::onEasyButtonClicked(){
    playGame = new game1scene(Easy, parserObject);
    mainView->setScene(playGame);
}

void welcomeScene::onMediumButtonClicked(){
    playGame = new game1scene(Medium, parserObject);
    mainView->setScene(playGame);
}

void welcomeScene::onHardButtonClicked(){
    playGame = new game1scene(Hard, parserObject);
    mainView->setScene(playGame);
}

bool::welcomeScene::hasBirthdayToday(QString userBirthdateString) {
    // find today's date
    QDate date = getTodayDate(); // get the current day,month,year
    QString todayDate = date.toString("MMdd");

    if(todayDate == userBirthdateString) { // TODO verify that the userBirthdateString is in the format of MMdd (without the year plz)
        qInfo("today is their birthday");
        return true;// if it matches then happy birthday
    }
    return false;
}

QDate welcomeScene::getTodayDate() {
    QDate date = QDateTime::currentDateTime().date();
    return date;
}
