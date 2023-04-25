#include "signupscene.h"
//#include "homescene.h"
#include <QGraphicsView>
#include "QtWidgets/qboxlayout.h"
#include "QtWidgets/qgroupbox.h"
#include "welcomescene.h"
#include "parser.hpp"
#include <QLineEdit>

signUpScene::signUpScene(QGraphicsView *view, parser *parserObject) : QGraphicsScene(), mainView(view)
{
    //Add background
    setBackgroundBrush(QBrush(QColor(220, 240, 255), Qt::SolidPattern));
    setSceneRect(0,0,908,510);
    this->parserObject = parserObject;

    //Avatar selection
    avatarSelection = 0;

    //Welcome page
    welcomeScene2 = new welcomeScene(mainView, parserObject->user, avatarSelection);

    //Common font
    QFont font("Times New Roman", 20);

    //Add avatar selection
    QGroupBox *avatar = new QGroupBox();
    QHBoxLayout *avatarLayout = new QHBoxLayout();
    avatar->setStyleSheet("background-color: rgb(220, 240, 255);");
    avatar->move(300, 225);
    QPushButton *image1 = new QPushButton();
    image1->setIcon(QPixmap::fromImage(QImage(":/profilePictures/orange.png")));
    image1->setIconSize(QSize(30, 30));
    avatarLayout->addWidget(image1);
    QPushButton *image2 = new QPushButton();
    image2->setIcon(QPixmap::fromImage(QImage(":/profilePictures/correctdeathstar.png")));
    image2->setIconSize(QSize(30, 30));
    avatarLayout->addWidget(image2);
    QPushButton *image3 = new QPushButton();
    image3->setIcon(QPixmap::fromImage(QImage(":/profilePictures/unicorn.png")));
    image3->setIconSize(QSize(30, 30));
    avatarLayout->addWidget(image3);
    QPushButton *image4 = new QPushButton();
    image4->setIcon(QPixmap::fromImage(QImage(":/profilePictures/trinity.png")));
    image4->setIconSize(QSize(30, 30));
    avatarLayout->addWidget(image4);
    avatar->setLayout(avatarLayout);
    addWidget(avatar);

    //First name
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

    //Last name
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

    //Date of birth
    newDOB  = new QGraphicsTextItem();
    newDOBEdit = new QTextEdit();
    newDOBWidget = new QGraphicsProxyWidget();
    newDOBWidget->setWidget(newDOBEdit);

    newDOB->setPlainText("DOB(MMDD): ");
    newDOB->setPos(265, 200);
    newDOB->setDefaultTextColor(Qt::black);
    newDOB->setFont(font);

    newDOBWidget->setPos(200, 25);
    newDOBWidget->setPreferredSize(200, 25);
    QRect newDOBEditSpace(400,200,200,25);
    newDOBEdit->setGeometry(newDOBEditSpace);
    newDOBEdit->setStyleSheet("background-color: white; color: black;");

    addItem(newDOB);
    addItem(newDOBWidget);

    //Add text edit space for user to type in their username
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

    //Add text edit space for user to type in their password
    newPassword = new QGraphicsTextItem();
   //newPasswordEdit = new QTextEdit();
    newPasswordEdit = new QLineEdit();
    newPasswordWidget = new QGraphicsProxyWidget();
    newPasswordWidget->setWidget(newPasswordEdit);
    //newPasswordEdit->setEchoMode(QTextEdit::Password);
    newPasswordEdit->setEchoMode(QLineEdit::Password);
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

    //Continue to finish signing up button
    moveForwardButton = new QPushButton();
    moveForwardWidget = new QGraphicsProxyWidget();
    moveForwardWidget->setWidget(moveForwardButton);

    moveForwardButton->setText("Sign Up!");
    moveForwardWidget->setPos(700, 425);
    moveForwardButton->setStyleSheet("background-color: grey;");
    moveForwardWidget->setAutoFillBackground(false);

    addItem(moveForwardWidget);

    //Check for avatarSelection
    connect(image1, &QPushButton::clicked, this, &signUpScene::onImageOne);
    connect(image2, &QPushButton::clicked, this, &signUpScene::onImageTwo);
    connect(image3, &QPushButton::clicked, this, &signUpScene::onImageThree);
    connect(image4, &QPushButton::clicked, this, &signUpScene::onImageFour);

    //button taking us to welcome page
    connect(moveForwardButton, &QPushButton::clicked, this, &signUpScene::onSignUpButtonClicked);

    //spawning error message if a wrong password is entered
    errorMessage = new QGraphicsTextItem();
    addItem(errorMessage);
}

void signUpScene::onSignUpButtonClicked() {
    if(validPassword(newUsernameEdit->toPlainText()) && !parserObject->userExists(newUsernameEdit->toPlainText())){
        qDebug() << "Inside the onSignUpButtonClicked method";
        parserObject->makeUserProfile(newUsernameEdit->toPlainText(), newPasswordEdit->text(), newFirstNameEdit->toPlainText(), newLastNameEdit->toPlainText(), newDOBEdit->toPlainText());
        parserObject->storeIntoFile(); //writes to JSON file
        parserObject->retrieveUserProfile(newUsernameEdit->toPlainText(), newPasswordEdit->toPlainText());
        welcomeScene2 = new welcomeScene(mainView, parserObject, avatarSelection);
        parserObject->retrieveUserProfile(newUsernameEdit->toPlainText(), newPasswordEdit->text());
        welcomeScene2 = new welcomeScene(mainView, parserObject->user);
        mainView->setScene(welcomeScene2);
    }
    else{
        addItem(errorMessage);
    }
    mainView->setScene(welcomeScene2);
}

bool::signUpScene::validPassword(QString password) {
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
