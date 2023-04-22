#ifndef USER_H
#define USER_H
#include <QWidget>
#include <QImage>
#include "parser.hpp"

class user : public QObject{
//    Q_OBJECT
public:
    //int *birthDay;
    QString password;
    QString firstName;
    QString lastName;
    QString username;
    int dateOfBirth;
    QImage profilePicture;

    user(QString passwordIn, QString firstNameIn, QString lastNameIn,  QString usernameIn, int dateOfBirthIn);
    bool login();
    bool verifyPassword();
    bool hasBirthdayToday();
    bool signup(int birthDay, QString username, QString password, QString firstName, QString lastName, parser parser);
    bool validPassword(QString password);
    QDate getTodayDate();

};

#endif // USER_H
