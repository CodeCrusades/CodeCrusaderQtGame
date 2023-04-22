#ifndef SIGNUPSCENE_H
#define SIGNUPSCENE_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTextEdit>
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include <QCalendarWidget>

class signUpScene: public QGraphicsScene
{
    Q_OBJECT

private:
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
    QTextEdit* newPasswordEdit;
    QGraphicsProxyWidget* newPasswordWidget;

    QPushButton* goBackButton;
    QGraphicsProxyWidget* goBackWidget;

    QPushButton* moveForwardButton;
    QGraphicsProxyWidget* moveForwardWidget;

    QCalendarWidget *calendar;
    QGraphicsProxyWidget* calendarWidget;

public:
    signUpScene();
};

#endif // SIGNUPSCENE_H
