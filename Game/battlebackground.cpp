#include "battlebackground.h"

BattleBackground::BattleBackground(int x, int y)
{
    setGeometry(QRect(x,y,460,450));
    setAttribute(Qt::WA_TranslucentBackground);
    this->x=x;
    this->y=y;
    background1= new QMovie(":/res/images/BattleBackground.gif");
    flash = new QMovie(":/res/images/hit.gif");
}

void BattleBackground::changePic(QString use)
{
    if (use=="flash") {
        move(x,y);
        setMovie(flash);
        flash->start();
    }
    else {
        move(x,y);
        setMovie(background1);
        background1->start();
    }
}
