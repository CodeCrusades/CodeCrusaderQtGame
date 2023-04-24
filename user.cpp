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
user::user(QString passwordIn, QString firstNameIn, QString lastNameIn,  QString usernameIn, int dateOfBirthIn){
    password = passwordIn;
    firstName = firstNameIn;
    lastName = lastNameIn;
    dateOfBirth = dateOfBirthIn;
    username = usernameIn;
    //profilePicture.load("/profilePictures/orange.png");
}

// possible arguments are the Username and Password.
bool::user::signIn(QString enteredUserName, QString password) {
    // get the enteredUserName and the password from the window

    // create a parser object
    parser *Parser = new parser();
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




    delete Parser;




    // create the Json object && open the Json file reading


//    QString stringFromJsonFile = jsonFile->readAll(); // read in all the JSON file. Q_TODO can it be optimatize to read in only the fields that I want. For example reading in the username and the password and the user name only?
//    jsonFile->close(); // close the file

//    // get the actual JsonDocument
//    QJsonDocument jsonResponse = QJsonDocument::fromJson(stringFromJsonFile.toUtf8());


//    // get the enteredUsername from the QLineEdit widget or whatever.


//    //QJsonArray jsonArray = jsonResponse.array();
//    QJsonObject jsonObject = jsonResponse.object();

//    QJsonArray allUsers = jsonObject["Users"].toArray(); // an array of all users.

//    // search for that enteredUserName from the jsonFile to retrieve other info of the user
//    for(auto user : allUsers) {
//        QJsonObject userObj = user.toObject();
//        QString userName = userObj.value("UserName").toString();
//        if(userName == enteredUserName) {
//            qDebug() << "user name has found in the JsonFile";
//            password = userObj.value("Password").toString();
//            firstName = userObj.value("FirstName").toString();
//            lastName = userObj.value("LastName").toString();
//            dateOfBirth = userObj.value("Birthday").toInt();
//            break;
//        }
//    }

    // verify the password that is correct
//    if(!verifyPassword()) {
//        return false;
//    }

    return false;
}


// TODO check with Micheal. Since the verification is being done in the parser. I dont't need to check it here as well. Can I be done tho. But it extra 0 work redutant
//bool::user::verifyPassword() {
//    QString enteredPassword = "msd250";
//    if(enteredPassword == password) {
//        return true;
//    }

//    //
//   qInfo("password is incorrect");
//    // don't call switch to the Welcome page
//    return false;
//}


//I have commented this whole method out, since with the new structure, signing up will mostly just be creating a new
//user object and storing it in the JSON file. But I'm leaving this here in case things get crazy haha.
//bool::user::signup(int birthDay, QString username, QString password, QString firstName, QString lastName, parser parser) {
//    bool itWorked = true;
//    //Simply initialize the user fields
//    this->birthDay = birthDay;
//    this->firstName = firstName;
//    this->lastName = lastName;
//    this->username = username;
//    if (validPassword(password)) {
//        this->password = password;
//    }
//    else {
//        qDebug() << "Please input a valid password! Valid passwords contain at least 8 characters, at least one upper and lower case letter, and a number.";
//    }
//    if (itWorked) {
//        parser.makeUserProfile(this->username, this->password, this->firstName, this->lastName, this->birthDay);
//    }
//    return itWorked;
//}

//Depending on the structure of the GUI, we will either need to pass arguments for each field read in from the widgets
//OR, if the user is connected to the scene, then we could just read in the info from the widgets directly

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
    //Okay at this point, we should also print out messages to the user (maybe by editing the labels by the password text box?)
    //letting the user know which condition they did not satisfy.
    //If everything is true, then it is valid, return true
    if (hasNumber && hasUpper && hasLower && correctSize) {
        return true;
    }
    //If even one thing is false, return false
    else {


        qDebug() << "Invalid password input, please put in";
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


    // assuming the entered DOB is in the format of MMDDYEAR ex: 04212022
    // extract the birthdate year, month, and day from the integer
//    int birthdateYear = dateOfBirth % 10000;
//    int birthdateMonth = (dateOfBirth / 10000) % 100;
//    int birthdateDay = dateOfBirth / 1000000;
//    //create a QDate object for the birthdate
//    QDate birthdate(birthdateYear, birthdateMonth, birthdateDay);

    // convert the birthdate to a string in the format "MMdd"
   //userBirthdateString = birthdate.toString("MMdd");

    // compare today's date and their birtday


    return false;
}


// get the today's date
QDate user::getTodayDate() {
    QDate date = QDateTime::currentDateTime().date();
    return date;
}




