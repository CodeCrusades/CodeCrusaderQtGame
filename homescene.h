#ifndef HOMESCENE_H
#define HOMESCENE_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QGraphicsView>

class welcomeScene;
class signInScene;
class signUpScene;
class parser;


class homescene: public QGraphicsScene
{
    Q_OBJECT

private:
    QGraphicsView *mainView;
    welcomeScene *welcomeScene1;
    signInScene *signInPage;
    signUpScene *signUpPage;
    parser *parserObject;

public:
    homescene(QGraphicsView* view, parser *parserObject);
public slots:
    void onSignInButtonClicked();
    void onSignUpButtonClicked();
    void onGuestButtonClicked();
};

#endif // HOMESCENE_H
