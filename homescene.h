#ifndef HOMESCENE_H
#define HOMESCENE_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QGraphicsView>
#include "signinscene.h"
#include "signupscene.h"
#include "welcomescene.h"


class homescene: public QGraphicsScene
{
    Q_OBJECT

private:
    QGraphicsView *mainView;
    welcomeScene *welcomeScene1;
    signInScene *signInPage;
    signUpScene *signUpPage;

public:
    //homescene();
    homescene(QGraphicsView* view);
public slots:
    void onSignInButtonClicked();
    void onSignUpButtonClicked();
    void onGuestButtonClicked();
};

#endif // HOMESCENE_H
