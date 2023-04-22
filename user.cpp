#include "user.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDateTime>

user::user()
{
    birthDay = 0;
    password = " ";
    firstName = " ";
    lastName = " ";
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
        qDebug() << "json file has been successfully opened";
    }


    QString stringFromJsonFile = jsonFile.readAll(); // read in all the JSON file. Q_TODO can it be optimatize to read in only the fields that I want. For example reading in the username and the password and the user name only?
    jsonFile.close(); // close the file

    // get the actual JsonDocument
    QJsonDocument jsonResponse = QJsonDocument::fromJson(stringFromJsonFile.toUtf8());

    // get the username from the parser or front screen whatever  method it is provide.
    QString enteredUserName  = "UserName"; // name entered from login screen // call the parser to get the username

    // get the enteredUsername from the QLineEdit widget or whatever.


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
            dateOfBirth = userObj.value("Birthday").toInt();
            break;
        }
    }

    // verify the password that is correct
    if(!verifyPassword()) {
        return false;
    }

    // get therir last three scores from the Json object

    // get their birthday and check if today is their birthday, if it is their birtday

    if(hasBirthdayToday()){
        // create the object of birthday and dispay it to the scene
    }

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

bool::user::hasBirthdayToday() {

    // find today's date
    QDate date = getTodayDate(); // get the current day,month,year
    QString todayDate = date.toString("MMdd");

    // assuming the entered DOB is in the format of MMDDYEAR ex: 04212022
    // extract the birthdate year, month, and day from the integer
    int birthdateYear = dateOfBirth % 10000;
    int birthdateMonth = (dateOfBirth / 10000) % 100;
    int birthdateDay = dateOfBirth / 1000000;
    //create a QDate object for the birthdate
    QDate birthdate(birthdateYear, birthdateMonth, birthdateDay);

    // convert the birthdate to a string in the format "MMdd"
    QString userBirthdateString = birthdate.toString("MMdd");

    // compare today's date and their birtday
    if(todayDate == userBirthdateString) {
        qInfo("today is their birthday");
        return true;// if it matches then happy birthday
    }

    return false;
}


// get the today's date
QDate user::getTodayDate() {
    QDate date = QDateTime::currentDateTime().date();
    return date;
}



