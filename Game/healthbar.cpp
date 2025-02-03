#include "healthbar.h"

HealthBar::HealthBar(int x,int y)
{
    setGeometry(QRect(x,y,106,26));
    setAttribute(Qt::WA_TranslucentBackground);
    this->x=x;
    this->y=y;
    setPixmap(QPixmap(":/res/images/HealthBar.png"));
    health = new QGraphicsRectItem();
    health->setBrush(QBrush(Qt::darkRed));
}

void HealthBar::setHealth(int hp, int maxHp)
{
    float value = (hp*1.0/maxHp*1.0)*100;
    health->setRect(this->x+3,this->y+3,value,20);
}
