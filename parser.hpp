#include <QJsonObject>
#include <QJsonArray>
#include <QObject>
#include <QErrorMessage>
#include <QJsonDocument>
#include <QFile>
#include <QDebug>

class parser{
public:
    QJsonArray *allUsers;
    
    parser();
    void makeUserProfile(QString userName, QString password, QString fName, QString lName, QString bDay);
    QJsonObject retrieveUserProfile(QString userName, QString password);
    void updateUserScores(QString userName, int score);
    bool userExists(QString userName);
    void storeIntoFile();
    bool userPasswordMatches(QString userName, QString password);
};
