#include <QJsonObject>
#include <QJsonArray>
#include <QObject>

class parser{

    QJsonArray *allUsers;
    
    parser();
    //todo add profile picture
    void makeUserProfile(QString userName, QString password, QString fName, QString lName, int bDay);
    QJsonObject retrieveUserProfile(QString userName, QString password);
    void updateUserProfile();
};
