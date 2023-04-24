#ifndef SIGNINSCENE_H
#define SIGNINSCENE_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTextEdit>
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include "welcomescene.h"

class signInScene: public QGraphicsScene
{
    Q_OBJECT

private:
    QGraphicsView* mainView;
    welcomeScene *welcomeScene1;

    QGraphicsTextItem* username;
    QTextEdit* usernameEdit;
    QGraphicsProxyWidget* usernameWidget;
    QGraphicsTextItem* password;
    QTextEdit* passwordEdit;
    QGraphicsProxyWidget* passwordWidget;

    QPushButton* login;
    QGraphicsProxyWidget* loginWidget;

public:
    //signInScene();
    signInScene(QGraphicsView* view);


public slots:
    void onLoginButtonClicked();

};

#endif // SIGNINSCENE_H
