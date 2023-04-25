#include <QJsonObject>
#include <QJsonArray>
#include <QObject>
#include <QErrorMessage>
#include <QJsonDocument>
#include <QFile>
#include <QDebug>
#include <vector>

class parser{
public:
    QJsonArray *allUsers;
    //std::vector<QJsonObject*> *allUsers;
    QJsonObject user;
    parser();
    void makeUserProfile(QString userName, QString password, QString fName, QString lName, QString bDay);
    void retrieveUserProfile(QString userName, QString password);
    void updateUserScores(QString userName, int score);
    bool userExists(QString userName);
    void storeIntoFile();
    bool userPasswordMatches(QString userName, QString password);
};
