#include "user.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

user::user()
{
    birthDay = 0;
    password = nullptr;
    firstName = nullptr;
    lastName = nullptr;
}

// possible arguments are the Username and Password.
bool::user::login() {

    // create the Json object && open the Json file reading
    QFile jsonFile;
    jsonFile.setFileName("/tmp/settings.json"); // replace the path with the relative path of the json file
    jsonFile.open(QIODevice::ReadOnly | QIODevice::Text); // opens the file

    // verify that the json file is correctly opened
    if(!jsonFile.isOpen()) {
        qDebug() << "json file failed to open ";
        return false;
    } else {
        qDebug() << "json file has been succefful opened";
    }


    QString stringFromJsonFile = jsonFile.readAll(); // read in all the JSON file. @TODO can it be optimatize to read in only the fields that I want. For example reading in the username and the password and the user name only?
    jsonFile.close(); // close the file

    // get the actual JsonDocument
    QJsonDocument jsonResponse = QJsonDocument::fromJson(stringFromJsonFile.toUtf8());

    // get the username from the parser or front screen whatever  method it is provide.
    QString enteredUserName  = "UserName"; // name entered from login screen // call the parser to get the username

    //QJsonArray jsonArray = jsonResponse.array();
    QJsonObject jsonObject = jsonResponse.object();

    QJsonArray allUsers = jsonObject["Users"].toArray(); // an array of all users.

    // search for that enteredUserName from the jsonFile to retrieve other info of the user
    for(auto user : allUsers) {
        QJsonObject userObj = user.toObject();
        QString userName = userObj.value("UserName").toString();
        if(userName == enteredUserName) {
            qDebug() << "user name has found in the JsonFile";
            password = userObj.value("Password").toString();
            firstName = userObj.value("FirstName").toString();
            lastName = userObj.value("LastName").toString();
            birthDay = userObj.value("Birthday").toInt();
            break;
        }
    }

    // verify the password that is correct
    if(!verifyPassword()) {
        return false;
    }


    // get therir last three scores from the Json object

    // get their birthday and check if today is their birthday, if it is their birtday

    // create the object of birth day and dispay it to the scene

    // create the object of today's date

    // after getting the object of display it.

    // switch to the Login page and display all functionality.

    return false;
}

bool::user::verifyPassword() {
    QString enteredPassword = "msd250";
    if(enteredPassword == password) {
        return true;
    }

    //
   qInfo("password is incorrect");
    // don't call switch to the Welcome page
    return false;
}
