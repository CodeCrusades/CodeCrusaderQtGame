#include "homescene.h"

homescene::homescene()
{
    //add background
    setBackgroundBrush(QBrush(QImage(":/images/homeScreen.jpg").scaledToHeight(512) .scaledToWidth(910)));
    setSceneRect(0,0,908,510);

}
