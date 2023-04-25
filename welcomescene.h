#ifndef WELCOMESCENE_H
#define WELCOMESCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTextEdit>
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QDate>

class game1scene;
class parser;

// game levels.
typedef enum {
    Easy,
    Medium,
    Hard
}gameLevels;

class welcomeScene: public QGraphicsScene
{
    Q_OBJECT

private:
    QGraphicsView* mainView;
    game1scene* playGame;

    QGraphicsTextItem* welcomeText;
    QGraphicsPixmapItem* imageHolder;
    QGraphicsTextItem* birthdayGreeting;

    QGraphicsTextItem* bestScoreLabel;
    QGraphicsTextItem* bestScore1;
    QGraphicsTextItem* bestScore2;
    QGraphicsTextItem* bestScore3;
    QGraphicsRectItem* scoreRect;

    QGraphicsRectItem* levelRect;
    QGraphicsTextItem* play;

    QPushButton* easy;
    QGraphicsProxyWidget* easyWidget;

    QPushButton* medium;
    QGraphicsProxyWidget* mediumWidget;

    QPushButton* hard;
    QGraphicsProxyWidget* hardWidget;

public:
    //welcomeScene();
    parser *parserObject;
    int avatarSelection;
    welcomeScene(QGraphicsView* view, parser *parserObject, int avatarSelection);

public slots:
    void onEasyButtonClicked();
    void onMediumButtonClicked();
    void onHardButtonClicked();
    bool hasBirthdayToday(QString userBirthdate);
    QDate getTodayDate();
};

#endif // WELCOMESCENE_H
