#include "user.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDateTime>

user::user()
{
    birthDay = 0;
    username = "";
    profilePicture.load("/profilePictures/orange.png");
    password = "";
    firstName = "";
    lastName = "";
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

//Depending on the structure of the GUI, we will either need to pass arguments for each field read in from the widgets
//OR, if the user is connected to the scene, then we could just read in the info from the widgets directly
bool::user::signup(int birthDay, QString username, QString password, QString firstName, QString lastName, parser parser) {
    bool itWorked = true;
    //Simply initialize the user fields
    this->birthDay = birthDay;
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
        parser.makeUserProfile(this->username, this->password, this->firstName, this->lastName, this->birthDay);
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
    //Okay at this point, we should also print out messages to the user (maybe by editing the labels by the password text box?)
    //letting the user know which condition they did not satisfy.
    //If everything is true, then it is valid, return true
    if (hasNumber && hasUpper && hasLower && correctSize) {
        return true;
    }
    //If even one thing is false, return false
    else {
        qDebug() << "Invalid password input, please put in"
        return false;
    }
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



