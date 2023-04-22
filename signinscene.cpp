#include "signinscene.h"

signInScene::signInScene()
{

    //add background
    setBackgroundBrush(QBrush(QImage(":/images/homeScreen.jpg").scaledToHeight(512) .scaledToWidth(910)));
    setSceneRect(0,0,908,510);

    //add text edit space for user to type in name
    username = new QGraphicsTextItem();
    usernameEdit = new QTextEdit();
    usernameWidget = new QGraphicsProxyWidget();
    usernameWidget->setWidget(usernameEdit);

    username->setPlainText("username: ");
    username->setPos(300, 245);
    username->setDefaultTextColor(Qt::black);
    QFont font("Times New Roman", 20);
    username->setFont(font);

    usernameWidget->setPos(200, 25);
    usernameWidget->setPreferredSize(200, 25);
    QRect textEditSpace(400,250,200,25);
    usernameEdit->setGeometry(textEditSpace);
    usernameEdit->setStyleSheet("background-color: white; color: black;");


//    username->setTextInteractionFlags(Qt::TextEditorInteraction);
//    username->setFlag(QGraphicsItem::ItemIsSelectable);
//    username->setFlag(QGraphicsItem::ItemIsFocusable);
//    username->setWidget(usernameEdit);

//    username->setPlainText("username");
//    username->setPos(400, 300);
//    username->setDefaultTextColor(Qt::black);
//    QFont font("Times New Roman", 20);
//    username->setFont(font);
//    username->setTextInteractionFlags(Qt::TextEditorInteraction);
    addItem(username);
    addItem(usernameWidget);

//    password = new QGraphicsTextItem();
//    addItem(password);
}
