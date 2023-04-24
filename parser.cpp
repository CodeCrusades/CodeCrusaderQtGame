#include <iostream>
#include "parser.hpp"

parser::parser(){

    //initialize allUsers as an empty array
    allUsers = new QJsonArray();

    //open and read the file
    QFile file(":/users.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray data = file.readAll();
    file.close();

    //ensure the file reads into the temporary array correctly
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(data, &error);
    if (doc.isNull()) {
        throw "parse error";
    }
    if (!doc.isArray()) {
        throw "json doc not array";
    }
    QJsonArray docArray = doc.array();

    //loop through allUsers and recreate users as JsonObjects in the array
    for (const QJsonValue &v : docArray) {
        if (v.isObject()) {
            allUsers->append(v.toObject());
        }
    }
}

//USED TO MAKE A NEW USER AFTER USERNAMEAVAILABLE CHECK
void parser::makeUserProfile(QString userName, QString password, QString fName, QString lName, QString bDay) {

    //add the new users data to a JSonObject
    QJsonObject *user = new QJsonObject();
    user->insert("UserName", userName);
    user->insert("Password", password);
    user->insert("FirstName", fName);
    user->insert("LastName", lName);
    user->insert("Birthday", bDay);
    user->insert("lastGame", 0);
    user->insert("2GamesAgo", 0);
    user->insert("3GamesAgo", 0);

    //append the new user to the array of users
    allUsers->append(QJsonValue(*user));

}

//USED TO RETRIEVE ALL ELEMENTS OF A USER WHEN SIGNING IN AFTER USEREXISTS CHECK
QJsonObject parser::retrieveUserProfile(QString userName, QString password) {

    //iterate throught the JSonArray, looking for the userName and password
    for (int i = 0; i < allUsers->size(); i++) {
        QJsonObject temp = allUsers->at(i).toObject();
        if (temp.value("UserName") == userName && temp.value("Password") == password) {

            //when the user is found, return it as a JsonObject
            return allUsers->at(i).toObject();
        }
    }

    //if the user does not exist at this point, throw an exception
    throw "error retrieving user information";
}

bool parser::userPasswordMatches(QString userName, QString password) {
    for (int i = 0; i < allUsers->size(); i++) {

        //iterate through the users
        QJsonObject temp = allUsers->at(i).toObject();
        if (temp.value("UserName") == userName && temp.value("Password") == password) {

            //if any users are a match, return true
            return true;
        }
    }

    //if no users are a match, return false
    return false;
}

//USED AS A CHECK FOR SIGNING IN && SIGNING UP
bool parser::userExists(QString userName) {
    for (int i = 0; i < allUsers->size(); i++) {

        //iterate through the users
        QJsonObject temp = allUsers->at(i).toObject();
        if (temp.value("UserName") == userName) {

            //if any users are a match, return true
            return true;
        }
    }

    //if no users are a match, return false
    return false;
}

//USED AT THE END OF EACH GAME TO UPDATE THE SCORES OF THE USER
void parser::updateUserScores(QString userName, int score) {
    for (int i = 0; i < allUsers->size(); i++) {

        //iterate through the users
        QJsonObject temp = allUsers->at(i).toObject();
        if (temp.value("UserName") == userName) {

            //when the user is found remove it from the array
            allUsers->removeAt(i);

            //move each score down a recency and place the newest score in the 'lastGame' position
            temp.insert("3GamesAgo", temp.value("2GamesAgo"));
            temp.insert("2GamesAgo", temp.value("lastGame"));
            temp.insert("lastGame", score);

            //remove the previous score values
            temp.remove("lastGame");
            temp.remove("2GamesAgo");
            temp.remove("3GamesAgo");

            //place the user back into the array
            allUsers->insert(i, temp);
        }
    }
}

//USED TO WRITE THE ARRAY OF USERS TO A FILE IN JSON FORMAT
//todo NEED TO ADD RELATIVE PATH FOR FILE
void parser::storeIntoFile() {

    //generate the document and file
    QJsonDocument doc(*allUsers);
    QFile file(":/users.json");

    //write the Json user objects to the file
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        file.write(doc.toJson());
        file.close();
    }
    else {

        //if something goes wrong, throw an error
        throw "error writing to file";
    }
}

