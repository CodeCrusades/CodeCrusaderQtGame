#ifndef SIGNINSCENE_H
#define SIGNINSCENE_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTextEdit>
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include <QLineEdit>

class welcomeScene;
class parser;

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
    //QTextEdit* passwordEdit;
    QLineEdit *passwordEdit;
    QGraphicsProxyWidget* passwordWidget;

    QPushButton* login;
    QGraphicsProxyWidget* loginWidget;
    QGraphicsTextItem* errorMessage;

public:
    parser *parserObject;
    signInScene(QGraphicsView* view, parser *parserObject); //Also add user object (or QJson if we go that way)



public slots:
    void onLoginButtonClicked();

};

#endif // SIGNINSCENE_H
