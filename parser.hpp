#include <QJsonObject>
#include <QJsonArray>
#include <QObject>
#include <QErrorMessage>
#include <QJsonDocument>
#include <QFile>

class parser{
public:
    QJsonArray *allUsers;
    
    parser();
    //todo add profile picture
    void makeUserProfile(QString userName, QString password, QString fName, QString lName, QString bDay);
    QJsonObject retrieveUserProfile(QString userName, QString password);
    void updateUserScores(QString userName, int score);
    bool userNameAvailable(QString userName);
    bool userExists(QString userName, QString password);
    void storeIntoFile();
};
