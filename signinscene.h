#ifndef SIGNINSCENE_H
#define SIGNINSCENE_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTextEdit>
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include <QGroupBox>
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
    int avatarSelection;
    signInScene(QGraphicsView* view, parser *parserObject);

public slots:
    void onLoginButtonClicked();
    void onImageOne() {
        avatarSelection = 0;
    }
    void onImageTwo() {
        avatarSelection = 1;
    }
    void onImageThree() {
        avatarSelection = 2;
    }
    void onImageFour() {
        avatarSelection = 3;
    }
};

#endif // SIGNINSCENE_H
