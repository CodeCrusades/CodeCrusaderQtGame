#ifndef SIGNINSCENE_H
#define SIGNINSCENE_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTextEdit>
#include <QGraphicsProxyWidget>
#include <QPushButton>

class signInScene: public QGraphicsScene
{
    Q_OBJECT

private:
    QGraphicsTextItem* username;
    QTextEdit* usernameEdit;
    QGraphicsProxyWidget* usernameWidget;
    QGraphicsTextItem* password;
    QTextEdit* passwordEdit;
    QGraphicsProxyWidget* passwordWidget;

    QPushButton* login;
    QGraphicsProxyWidget* loginWidget;

public:
    signInScene();
};

#endif // SIGNINSCENE_H
