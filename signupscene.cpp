#include "signupscene.h"

signUpScene::signUpScene()
{
    //add background
    setBackgroundBrush(QBrush(QColor(220, 240, 255), Qt::SolidPattern));
    setSceneRect(0,0,908,510);

    //common font
    QFont font("Times New Roman", 20);

    //first name
    newFirstName = new QGraphicsTextItem();
    newFirstNameEdit = new QTextEdit();
    newFirstNameWidget = new QGraphicsProxyWidget();
    newFirstNameWidget->setWidget(newFirstNameEdit);

    newFirstName->setPlainText("First Name: ");
    newFirstName->setPos(295, 100);
    newFirstName->setDefaultTextColor(Qt::black);
    newFirstName->setFont(font);

    newFirstNameWidget->setPos(200, 25);
    newFirstNameWidget->setPreferredSize(200, 25);
    QRect newFirstNameEditSpace(400,100,200,25);
    newFirstNameEdit->setGeometry(newFirstNameEditSpace);
    newFirstNameEdit->setStyleSheet("background-color: white; color: black;");

    addItem(newFirstName);
    addItem(newFirstNameWidget);

    // last name
    newLastName = new QGraphicsTextItem();
    newLastNameEdit = new QTextEdit();
    newLastNameWidget = new QGraphicsProxyWidget();
    newLastNameWidget->setWidget(newLastNameEdit);

    newLastName->setPlainText("Last Name: ");
    newLastName->setPos(295, 150);
    newLastName->setDefaultTextColor(Qt::black);
    newLastName->setFont(font);

    newLastNameWidget->setPos(200, 25);
    newLastNameWidget->setPreferredSize(200, 25);
    QRect newLastNameEditSpace(400,150,200,25);
    newLastNameEdit->setGeometry(newLastNameEditSpace);
    newLastNameEdit->setStyleSheet("background-color: white; color: black;");

    addItem(newLastName);
    addItem(newLastNameWidget);

    // date of birth
    newDOB  = new QGraphicsTextItem();
    newDOBEdit = new QTextEdit();
    newDOBWidget = new QGraphicsProxyWidget();
    newDOBWidget->setWidget(newDOBEdit);

    newDOB->setPlainText("DOB: ");
    newDOB->setPos(340, 200);
    newDOB->setDefaultTextColor(Qt::black);
    newDOB->setFont(font);

    newDOBWidget->setPos(200, 25);
    newDOBWidget->setPreferredSize(200, 25);
    QRect newDOBEditSpace(400,200,200,25);
    newDOBEdit->setGeometry(newDOBEditSpace);
    newDOBEdit->setStyleSheet("background-color: white; color: black;");

    addItem(newDOB);
    addItem(newDOBWidget);

    // profile pic
    newProfilePic  = new QGraphicsTextItem();
    newProfilePicChoose = new QPushButton();
    newProfilePicWidget = new QGraphicsProxyWidget();
    newProfilePicWidget->setWidget(newProfilePicChoose);

    newProfilePic->setPlainText("Profile Picture: ");
    newProfilePic->setPos(266, 250);
    newProfilePic->setDefaultTextColor(Qt::black);
    newProfilePic->setFont(font);

    newProfilePicChoose->setText("Choose");
    newProfilePicWidget->setPos(450, 250);
    newProfilePicChoose->setStyleSheet("background-color: grey;");
    newProfilePicWidget->setAutoFillBackground(false);

    addItem(newProfilePic);
    addItem(newProfilePicWidget);

    //add text edit space for user to type in their username
    newUsername = new QGraphicsTextItem();
    newUsernameEdit = new QTextEdit();
    newUsernameWidget = new QGraphicsProxyWidget();
    newUsernameWidget->setWidget(newUsernameEdit);

    newUsername->setPlainText("username: ");
    newUsername->setPos(305, 295);
    newUsername->setDefaultTextColor(Qt::black);
    newUsername->setFont(font);

    newUsernameWidget->setPos(200, 25);
    newUsernameWidget->setPreferredSize(200, 25);
    QRect newUsernameEditSpace(400,300,200,25);
    newUsernameEdit->setGeometry(newUsernameEditSpace);
    newUsernameEdit->setStyleSheet("background-color: white; color: black;");

    addItem(newUsername);
    addItem(newUsernameWidget);

    //add text edit space for user to type in their password
    newPassword = new QGraphicsTextItem();
    newPasswordEdit = new QTextEdit();
    newPasswordWidget = new QGraphicsProxyWidget();
    newPasswordWidget->setWidget(newPasswordEdit);

    newPassword->setPlainText("password: ");
    newPassword->setPos(306, 345);
    newPassword->setDefaultTextColor(Qt::black);
    newPassword->setFont(font);

    newPasswordWidget->setPos(300, 25);
    newPasswordWidget->setPreferredSize(200, 25);
    QRect newPasswordEditSpace(400,350,200,25);
    newPasswordEdit->setGeometry(newPasswordEditSpace);
    newPasswordEdit->setStyleSheet("background-color: white; color: black;");

    addItem(newPassword);
    addItem(newPasswordWidget);

    // go back button
    goBackButton = new QPushButton();
    goBackWidget = new QGraphicsProxyWidget();
    goBackWidget->setWidget(goBackButton);

    goBackButton->setText("Go back");
    goBackWidget->setPos(150, 425);
    goBackButton->setStyleSheet("background-color: grey;");
    goBackWidget->setAutoFillBackground(false);

    addItem(goBackWidget);

    // continue to finish signing up button
    moveForwardButton = new QPushButton();
    moveForwardWidget = new QGraphicsProxyWidget();
    moveForwardWidget->setWidget(moveForwardButton);

    moveForwardButton->setText("Sign Up!");
    moveForwardWidget->setPos(700, 425);
    moveForwardButton->setStyleSheet("background-color: grey;");
    moveForwardWidget->setAutoFillBackground(false);

    addItem(moveForwardWidget);

    //
    calendar = new QCalendarWidget();
    calendarWidget = new QGraphicsProxyWidget();
    //calendarWidget->setWidget(calendarWidget);
    addWidget(calendar);
}
