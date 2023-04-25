#include "welcomescene.h"
#include "game1scene.h"
#include <QImage>
#include <QFont>
#include <QDate>

welcomeScene::welcomeScene(QGraphicsView *view) : QGraphicsScene(), mainView(view) {
    //Add background
    setBackgroundBrush(QBrush(QColor(220, 240, 255), Qt::SolidPattern));
    setSceneRect(0,0,908,510);
    qInfo("Entered welcomeScene");

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
    QImage image(":/profilePictures/orange.png");
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
    addItem(birthdayGreeting);

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
    bestScoreLabel->setPlainText("Best Scores:");
    bestScoreLabel->setPos(scoreRect->boundingRect().topLeft() + QPointF (10,10));
    bestScoreLabel->setDefaultTextColor(Qt::black);
    bestScoreLabel->setFont(scoreFont);
    addItem(bestScoreLabel);
    bestScore1 = new QGraphicsTextItem();
    bestScore1->setPlainText("* 150 points");
    bestScore1->setPos(scoreRect->boundingRect().topLeft() + QPointF (40,50));
    bestScore1->setDefaultTextColor(Qt::black);
    bestScore1->setFont(scoreFont);
    addItem(bestScore1);
    bestScore2 = new QGraphicsTextItem();
    bestScore2->setPlainText("* 120 points");
    bestScore2->setPos(scoreRect->boundingRect().topLeft() + QPointF (40,80));
    bestScore2->setDefaultTextColor(Qt::black);
    bestScore2->setFont(scoreFont);
    addItem(bestScore2);
    bestScore3 = new QGraphicsTextItem();
    bestScore3->setPlainText("* 100 points");
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
    playGame = new game1scene(Easy);
    mainView->setScene(playGame);
}

void welcomeScene::onMediumButtonClicked(){
    playGame = new game1scene(Medium);
    mainView->setScene(playGame);
}

void welcomeScene::onHardButtonClicked(){
    playGame = new game1scene(Hard);
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
