#include <iostream>
#include "parser.hpp"
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>

parser::parser(){

    //Initialize allUsers as an empty array
    allUsers = new QJsonArray[20];


    //Open and read the file
    QFile file("/Users/levineely/CodeCrusaderQtGame/users.json");
    if( !file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "File not open.";
    }

    QByteArray data = file.readAll();
    file.close();

    //Ensure the file reads into the temporary array correctly
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(data, &error);
    QJsonArray docArray = doc.array();

    //Loop through allUsers and recreate users as JsonObjects in the array
    for (const QJsonValue &v : docArray) {
        if (v.isObject()) {
            allUsers->append(v.toObject());
        }
    }
}

//USED TO MAKE A NEW USER AFTER USERNAMEAVAILABLE CHECK
void parser::makeUserProfile(QString userName, QString password, QString fName, QString lName, QString bDay) {

    qDebug() << "QJson object being initialized in makeUserProfile method.";
    //Add the new users data to a JSonObject
    QJsonObject *userInsert = new QJsonObject();
    userInsert->insert("UserName", userName);
    userInsert->insert("Password", password);
    userInsert->insert("FirstName", fName);
    userInsert->insert("LastName", lName);
    userInsert->insert("Birthday", bDay);
    userInsert->insert("lastGame", 0);
    userInsert->insert("2GamesAgo", 0);
    userInsert->insert("3GamesAgo", 0);
    userInsert->insert("BestGame", 0);

    //Append the new user to the array of users
    allUsers->append(QJsonValue(*userInsert));

}

//USED TO RETRIEVE ALL ELEMENTS OF A USER WHEN SIGNING IN AFTER USEREXISTS CHECK
QJsonObject parser::retrieveUserProfile(QString userName, QString password) {

    QJsonObject temp;
    //Iterate throught the JSonArray, looking for the userName and password
    for (int i = 0; i < allUsers->size(); i++) {
        temp = allUsers->at(i).toObject();
        if (temp.value("UserName") == userName && temp.value("Password") == password) {
            return temp;
       }
    }
    return temp;
    qDebug() << "error retrieving user information";
}

bool parser::userPasswordMatches(QString userName, QString password) {
    for (int i = 0; i < allUsers->size(); i++) {
        //Iterate through the users
        QJsonObject temp = allUsers->at(i).toObject();
        if (temp.value("UserName") == userName && temp.value("Password") == password) {
            //If any users are a match, return true
            return true;
        }
    }
    //If no users are a match, return false
    return false;
}

//USED AS A CHECK FOR SIGNING IN && SIGNING UP
bool parser::userExists(QString userName) {
    for (int i = 0; i < allUsers->size(); i++) {
        //Iterate through the users
        QJsonObject temp = allUsers->at(i).toObject();
        if (temp.value("UserName") == userName) {
            //If any users are a match, return true
            return true;
        }
    }
    //If no users are a match, return false
    return false;
}

//USED AT THE END OF EACH GAME TO UPDATE THE SCORES OF THE USER
void parser::updateUserScores(QString userName, int score) {
    for (int i = 0; i < allUsers->size(); i++) {
        //Iterate through the users
        QJsonObject temp = allUsers->at(i).toObject();
        if (temp.value("UserName") == userName) {
            //When the user is found remove it from the array
            allUsers->removeAt(i);
            //Update best score
            if (score > temp.value("BestGame").toInt()) {
                temp.remove("BestGame");
                temp.insert("BestGame", score);
            }
            QJsonValue lastGame = temp.value("lastGame");
            QJsonValue twoGamesAgo = temp.value("2GamesAgo");
            //Remove the previous score values
            temp.remove("lastGame");
            temp.remove("2GamesAgo");
            temp.remove("3GamesAgo");
            //Move each score down a recency and place the newest score in the 'lastGame' position
            temp.insert("3GamesAgo", twoGamesAgo);
            temp.insert("2GamesAgo", lastGame);
            temp.insert("lastGame", score);
            //Place the user back into the array
            allUsers->insert(i, temp);
        }
    }
}

//USED TO WRITE THE ARRAY OF USERS TO A FILE IN JSON FORMAT
//todo NEED TO ADD RELATIVE PATH FOR FILE
void parser::storeIntoFile() {
    //Generate the document and file
    QJsonDocument doc(*allUsers);
    QFile file("/Users/levineely/CodeCrusaderQtGame/users.json");
    //Write the Json user objects to the file
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        file.write(doc.toJson());
        file.close();
    }
    else {
        qDebug() << "error writing to file";
        qDebug() << "Error code:" << file.error();
        qDebug() << "Error description:" << file.errorString();
    }
}

