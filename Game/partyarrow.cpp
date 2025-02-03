#include "partyarrow.h"

PartyArrow::PartyArrow(int x,int y)
{
    setPos(x,y);
    setPixmap(QPixmap(":/res/images/Arrow.png"));
}

void PartyArrow::UpArrow()
{
    setPixmap(QPixmap(":/res/images/Arrow.png"));
}

void PartyArrow::DownArrow()
{
    setPixmap(QPixmap(":/res/images/DownArrow.png"));
}

void PartyArrow::LeftArrow()
{
    setPixmap(QPixmap(":/res/images/LeftArrow.png"));
}

void PartyArrow::RightArrow()
{
    setPixmap(QPixmap(":/res/images/RightArrow.png"));
}


