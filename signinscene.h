#ifndef SIGNINSCENE_H
#define SIGNINSCENE_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTextEdit>
#include <QGraphicsProxyWidget>

class signInScene: public QGraphicsScene
{
    Q_OBJECT
private:
    QGraphicsTextItem* username;
    QGraphicsTextItem* password;
    QTextEdit* usernameEdit;
    QGraphicsProxyWidget* usernameWidget;
public:
    signInScene();
};

#endif // SIGNINSCENE_H
