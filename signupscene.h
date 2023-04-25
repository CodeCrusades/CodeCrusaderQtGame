#ifndef SIGNUPSCENE_H
#define SIGNUPSCENE_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTextEdit>
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include <QCalendarWidget>
#include <QLineEdit>

class welcomeScene;
class parser;

class signUpScene: public QGraphicsScene
{
    Q_OBJECT

private:
    QGraphicsView* mainView;
    welcomeScene *welcomeScene2;
//    homescene *homeScene1;

    QGraphicsTextItem* newFirstName;
    QTextEdit* newFirstNameEdit;
    QGraphicsProxyWidget* newFirstNameWidget;

    QGraphicsTextItem* newLastName;
    QTextEdit* newLastNameEdit;
    QGraphicsProxyWidget* newLastNameWidget;

    QGraphicsTextItem* newDOB;
    QTextEdit* newDOBEdit;
    QGraphicsProxyWidget* newDOBWidget;

    QGraphicsTextItem* newProfilePic;
    QPushButton* newProfilePicChoose;
    QGraphicsProxyWidget* newProfilePicWidget;

    QGraphicsTextItem* newUsername;
    QTextEdit* newUsernameEdit;
    QGraphicsProxyWidget* newUsernameWidget;

    QGraphicsTextItem* newPassword;
    //QTextEdit* newPasswordEdit;
    QLineEdit *newPasswordEdit;
    QGraphicsProxyWidget* newPasswordWidget;

//    QPushButton* goBackButton;
//    QGraphicsProxyWidget* goBackWidget;

    QPushButton* moveForwardButton;
    QGraphicsProxyWidget* moveForwardWidget;

    QCalendarWidget *calendar;
    QGraphicsProxyWidget* calendarWidget;

    QGraphicsTextItem* errorMessage;


public:
    //signUpScene();
    int avatarSelection;
    parser *parserObject;
    signUpScene(QGraphicsView* view, parser *parserObject); //Add user object parameter


public slots:
    void onSignUpButtonClicked();
    bool validPassword(QString password);
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

#endif // SIGNUPSCENE_H
