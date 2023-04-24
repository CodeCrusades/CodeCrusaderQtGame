#ifndef USER_H
#define USER_H
#include <QWidget>
#include <QImage>
#include "parser.hpp"

class user : public QObject{
//    Q_OBJECT
public:
    // member fields
    QString birthDay;
    QString password;
    QString username;
    QString firstName;
    QString lastName;
    int highScore;
    int *lastThreeScores;

    // constructors
    user();
    user(QString birthDay, QString username, QString password, QString firstName, QString lastName);
    user(QString birthDay, QString username, QString password, QString firstName, QString lastName, int highScore, int *lastThreeGames);
    user(QString passwordIn, QString firstNameIn, QString lastNameIn,  QString usernameIn, int dateOfBirthIn);


    //methods
    bool signIn(QString enteredUserName, QString password);
    bool verifyPassword();
    bool hasBirthdayToday();
    //QString username;
    int dateOfBirth;

    user(QString passwordIn, QString firstNameIn, QString lastNameIn,  QString usernameIn, int dateOfBirthIn);
    //bool login();
    //bool verifyPassword();
   // bool hasBirthdayToday();
    bool signup(int birthDay, QString username, QString password, QString firstName, QString lastName, parser parser);
//    user(QString passwordIn, QString firstNameIn, QString lastNameIn,  QString usernameIn, int dateOfBirthIn);
//    bool login();
//    bool verifyPassword();
//    bool hasBirthdayToday();
//    bool signup(int birthDay, QString username, QString password, QString firstName, QString lastName, parser parser);
    bool validPassword(QString password);
    bool hasBirthdayToday(QString userBirthdate);
    bool signup(int birthDay, QString username, QString password, QString firstName, QString lastName, parser parser);
    QDate getTodayDate();
    QImage profilePicture;

};

#endif // USER_H
