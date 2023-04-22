#ifndef USER_H
#define USER_H

#include <QWidget>

class user : public QObject
{
    Q_OBJECT
public:
    int birthDay;
    QString password;
    QString firstName;
    QString lastName;
    user();
    bool login();
    bool verifyPassword();

};

#endif // USER_H
