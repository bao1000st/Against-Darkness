#include "infobox.h"

InfoBox::InfoBox(int x,int y)
{
    setPos(x,y);
    setPixmap(QPixmap(":/res/images/box.png"));
}

void InfoBox::WarriorBox()
{
    setPixmap(QPixmap(":/res/images/WarriorBox.png"));
}

void InfoBox::ClericBox()
{
    setPixmap(QPixmap(":/res/images/ClericBox.png"));
}


void InfoBox::WizardBox()
{
    setPixmap(QPixmap(":/res/images/WizardBox.png"));
}

void InfoBox::BarbarianBox()
{
    setPixmap(QPixmap(":/res/images/BarbarianBox.png"));
}

void InfoBox::ElfBox()
{
    setPixmap(QPixmap(":/res/images/ElfBox.png"));
}

void InfoBox::DwarfBox()
{
    setPixmap(QPixmap(":/res/images/DwarfBox.png"));
}

void InfoBox::EmptyBox()
{
    setPixmap(QPixmap(":/res/images/box.png"));
}


void InfoBox::RogueBox()
{
    setPixmap(QPixmap(":/res/images/RogueBox.png"));
}
