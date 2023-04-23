#ifndef USER_H
#define USER_H
#include <QWidget>

class user : public QObject
{
//    Q_OBJECT
public:
    QString birthDay;
    QString password;
    QString username;
    QString firstName;
    QString lastName;
    int highScore;
    int *lastThreeScores;

    user();
    user(QString birthDay, QString username, QString password, QString firstName, QString lastName);
    user(QString birthDay, QString username, QString password, QString firstName, QString lastName, int highScore, int *lastThreeGames);
    bool login();
    bool verifyPassword();
    bool hasBirthdayToday();
    bool validPassword(QString password);
    QDate getTodayDate();

};

#endif // USER_H
