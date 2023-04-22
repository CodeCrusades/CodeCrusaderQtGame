#include <iostream>
#include "parser.hpp"

parser::parser(){
    //read Json objects from the Json file and construct the elements into Json Objects
    //insert the objects into the Json array
}

void parser::makeUserProfile(QString userName, QString password, QString fName, QString lName, int bDay) {

    //add the new users data to a JSonObject
    QJsonObject *user = new QJsonObject();
    user->insert("UserName", userName);
    user->insert("Password", password);
    user->insert("FirstName", fName);
    user->insert("LastName", lName);
    user->insert("Birthday", bDay);

    //append the new user to the array of users
    allUsers = new QJsonArray;
    allUsers->append(QJsonValue(*user));

}

QJsonObject parser::retrieveUserProfile(QString userName, QString password) {
    //IT IS HIGHLY LIKELY THAT THIS IMPLEMENTATION WONT WORK VERY WELL

    //iterate throught the JSonArray, looking for the userName and password
    for (int i = 0; i < allUsers->size(); i++) {
        if (allUsers->contains(QJsonValue(userName)) && allUsers->contains(QJsonValue(password))) {

            //if the user exists, return that user as a QJsonObject
            return allUsers->at(i).toObject();
        }

        //if the user does not exist, return a JsonObject with only an error message initialized
        else {
            //THIS PORTION MIGHT CAUSE ISSUES
            QJsonObject *error = new QJsonObject();
            QString errorMess = "error";
            error->insert("errorMessage",errorMess);
            return *error;
        }
    }
}

void updateUserProfile() {
    //todo make this method
}
