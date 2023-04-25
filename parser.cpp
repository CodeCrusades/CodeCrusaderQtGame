#include <iostream>
#include "parser.hpp"
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>

parser::parser(){

    //Initialize allUsers as an empty array
    allUsers = new QJsonArray[20];


    //Open and read the file
    QFile file("/Users/lauryn.c.hansen/MSD/CodeCrusaderQtGame/users.json");
    if( !file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "File not open.";
    }

    QByteArray data = file.readAll();
    file.close();

    //Ensure the file reads into the temporary array correctly
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(data, &error);
//    if (doc.isNull()) {
//        qDebug() << "parse error";
//    }
//    if (!doc.isArray()) {
//        qDebug() << "json doc not array";
//    }
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
//        qDebug() << temp.value("FirstName");
//        qDebug() << userName << " " << password;

        if (temp.value("UserName") == userName && temp.value("Password") == password) {
            //When the user is found, return it as a JsonObject
            //allUsers->at(i).toObject();
//            QJsonObject tmp = temp;
//            qDebug() << "Inside loop";
//            tmp.insert("UserName", userName);
//            tmp.insert("Password", password);
//            tmp.insert("FirstName", temp.value("FirstName").toString());
//            tmp.insert("LastName", temp.value("LirstName").toString());
//            tmp.insert("Birthday", temp.value("Birthday").toString());
//            tmp.insert("lastGame", 0);
//            tmp.insert("2GamesAgo", 0);
//            tmp.insert("3GamesAgo", 0);
//            tmp.insert("BestGame", 0);
            return temp;

//            qDebug() << "\t TEST: " << user.value("FirstName");


       }



    }

    return temp;

    //If the user does not exist at this point, qDebug() << an exception
    qDebug() << "error retrieving user information";
}

bool parser::userPasswordMatches(QString userName, QString password) {
    for (int i = 0; i < allUsers->size(); i++) {

        //Iterate through the users
        QJsonObject temp = allUsers->at(i).toObject();
        qInfo() << "Temp: " << temp.value("UserName");
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
         qInfo() << "Temp: " << temp.value("UserName");
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
    QFile file("/Users/lauryn.c.hansen/MSD/CodeCrusaderQtGame/users.json");

    //Write the Json user objects to the file
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Inside storeIntoFile if statement";
        file.write(doc.toJson());
        file.close();
    }
    else {
        //If something goes wrong, qDebug() << an error
        qDebug() << "error writing to file";
        qDebug() << "Error code:" << file.error();
        qDebug() << "Error description:" << file.errorString();
    }
}

