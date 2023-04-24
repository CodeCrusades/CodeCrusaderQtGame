#include "user.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDateTime>
#include <QString>

user::user()
{
    birthDay = "";
    username = "";
    password = "";
    firstName = "";
    lastName = "";
    highScore = 0;
    for (int i = 0; i < 3; i++) {
        lastThreeScores[i] = 0;
    }
}

//Constructor to be used with input from signUp page
user::user(QString birthDay, QString username, QString password, QString firstName, QString lastName) {
    this->birthDay = birthDay;
    this->username = username;
    if (validPassword(password)) {
        this->password = password;
    }
    else {
        qDebug() << "Please input a valid password! Valid passwords contain at least 8 characters, at least one upper and lower case letter, and a number.";
    }
    this->firstName = firstName;
    this->lastName = lastName;
    highScore = 0;
    for (int i = 0; i < 3; i++) {
        lastThreeScores[i] = 0;
    }
}

//Constructor to be used with input from the JSON file in conjunction with the signIn page
//Side note: I don't think that the JSON file stores arrays, so it might be good to change this to handle that later?
user::user(QString birthDay, QString username, QString password, QString firstName, QString lastName, int highScore, int *lastThreeGames) {
    this->birthDay = birthDay;
    this->username = username;
    if (validPassword(password)) {
        this->password = password;
    }
    else {
        qDebug() << "Please input a valid password! Valid passwords contain at least 8 characters, at least one upper and lower case letter, and a number.";
    }
    this->firstName = firstName;
    this->lastName = lastName;
    this->highScore = highScore;
    this->lastThreeScores = lastThreeGames;

}


// possible arguments are the Username and Password.
bool::user::signIn(QString enteredUserName, QString password) {
    // get the enteredUserName and the password from the window

    // create a parser object
    parser *Parser = new parser(); // this parser can be passed in as an argument
    if (Parser->userExists(enteredUserName,password)) {
        QJsonObject userObject = Parser->retrieveUserProfile(enteredUserName, password);

        // Retrive the user Birthday,
        QString userBirthdateFromJsonFile = userObject.value("Birthday").toString();
        // get their birthday and check if today is their birthday, if it is their birtday
        if(hasBirthdayToday(userBirthdateFromJsonFile)){
            // create the object of birthday and dispay it to the Welcoming scene
        } else {
            qInfo("Keep calm, today isn't your birthday");
        }

        // get therir last three scores from the Json object
        QString lastScore1 = userObject.value("lastGame").toString();
        QString lastScore2 = userObject.value("2GamesAgo").toString();
        QString lastScore3 = userObject.value("3GamesAgo").toString();

        // TODO send lastScore1, lastScore2, lastScore3 to the welcoming scene;


        // switch to the Login page and display all functionality.

    } else {
        qInfo("User does not exist");
    }

}

bool::user::signup(int birthDay, QString username, QString password, QString firstName, QString lastName, parser parser) {
    bool itWorked = true;
    //Simply initialize the user fields
    this->dateOfBirth = birthDay;
    this->firstName = firstName;
    this->lastName = lastName;
    this->username = username;
    if (validPassword(password)) {
        this->password = password;
    }
    else {
        qDebug() << "Please input a valid password! Valid passwords contain at least 8 characters, at least one upper and lower case letter, and a number.";
    }
    //Here, we need some input from the GUI to display the profile picture options, and then select one. This will allow us to
    //then select which file needs to be attached to their profile with the profilePicture member variable.
    //Also, this portion should have a test section which makes sure the profile picture was uploaded successfully
    if (itWorked) {
        //TODO: Comment this back in once makeUserProfile method is created
        //parser.makeUserProfile(this->username, this->password, this->firstName, this->lastName, this->dateOfBirth);
    }
    return itWorked;
}

bool::user::validPassword(QString password) {
    //Initialize booleans to keep track of password validity
    bool hasNumber = false;
    bool hasUpper = false;
    bool hasLower = false;
    bool correctSize = false;
    //Check password length
    if (password.length() >= 8) {
        correctSize = true;
    }
    //Loop through the password to check if it contains appropriate values
    for (int i = 0; i < password.length(); i++) {
        if (password[i].isDigit()) {
            hasNumber = true;
        }
        else if (password[i].isUpper()) {
            hasUpper = true;
        }
        else if (password[i].isLower()) {
            hasLower = true;
        }
    }
    //If everything is true, then it is valid, return true
    if (hasNumber && hasUpper && hasLower && correctSize) {
        return true;
    }
    //If even one thing is false, return false, this will throw an error in the user constructor
    else {
        return false;
    }
}

bool::user::hasBirthdayToday(QString userBirthdateString) {
    // find today's date
    QDate date = getTodayDate(); // get the current day,month,year
    QString todayDate = date.toString("MMdd");

    if(todayDate == userBirthdateString) { // TODO verify that the userBirthdateString is in the format of MMdd (without the year plz)
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



}
