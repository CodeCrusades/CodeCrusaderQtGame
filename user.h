#ifndef USER_H
#define USER_H
#include <QWidget>

class user : public QObject
{
//    Q_OBJECT
public:
    int birthDay;
    QString password;
    QString firstName;
    QString lastName;
    int dateOfBirth;

    user();
    bool login();
    bool verifyPassword();
    bool hasBirthdayToday();
    QDate getTodayDate();

};

#endif // USER_H
