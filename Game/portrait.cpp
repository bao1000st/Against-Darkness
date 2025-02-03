#include "portrait.h"


Portrait::Portrait(int x,int y)
{
    setPos(x,y);
    setPixmap(QPixmap(":/res/images/emptyPortrait.png"));
}

void Portrait::StartPortrait()
{
    setPixmap(QPixmap(":/res/images/startPortrait.png"));
}

void Portrait::EmptyPortrait()
{
    setPixmap(QPixmap(":/res/images/emptyPortrait.png"));
}

void Portrait::WarriorPortrait()
{
    setPixmap(QPixmap(":/res/images/WarriorPortrait.png"));
}

void Portrait::ClericPortrait()
{
    setPixmap(QPixmap(":/res/images/ClericPortrait.png"));
}

void Portrait::RoguePortrait()
{
    setPixmap(QPixmap(":/res/images/RoguePortrait.png"));
}

void Portrait::WizardPortrait()
{
    setPixmap(QPixmap(":/res/images/WizardPortrait.png"));
}

void Portrait::BarbarianPortrait()
{
    setPixmap(QPixmap(":/res/images/BarbarianPortrait.png"));
}

void Portrait::ElfPortrait()
{
    setPixmap(QPixmap(":/res/images/ElfPortrait.png"));
}

void Portrait::DwarfPortrait()
{
    setPixmap(QPixmap(":/res/images/DwarfPortrait.png"));
}
