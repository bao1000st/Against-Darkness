#include "characterpic.h"

CharacterPic::CharacterPic(int x,int y)
{
    setGeometry(QRect(x,y,460,150));
    setAttribute(Qt::WA_TranslucentBackground);
    this->x=x;
    this->y=y;
    warrior = new QMovie(":/res/images/Warrior.gif");
    cleric = new QMovie(":/res/images/Cleric.gif");
    rogue = new QMovie(":/res/images/Rogue.gif");
    wizard = new QMovie(":/res/images/Wizard.gif");
    barbarian = new QMovie(":/res/images/Barbarian.gif");
    dwarf = new QMovie(":/res/images/Dwarf.gif");
    elf = new QMovie(":/res/images/Elf.gif");
}

void CharacterPic::WarriorPic(QString hit)
{
    if (hit!="hit")
    {
        setMovie(warrior);
        warrior->jumpToFrame(0);
    }
    else
    {
        setMovie(warrior);
        warrior->start();
    }
}

void CharacterPic::ClericPic(QString hit)
{
    if (hit!="hit")
    {
        setMovie(cleric);
        cleric->jumpToFrame(0);
    }
    else
    {
        setMovie(cleric);
        cleric->start();
    }
}

void CharacterPic::RoguePic(QString hit)
{
    if (hit!="hit")
    {
        setMovie(rogue);
        rogue->jumpToFrame(0);
    }
    else
    {
        setMovie(rogue);
        rogue->start();
    }
}

void CharacterPic::WizardPic(QString hit)
{
    if (hit!="hit")
    {
        setMovie(wizard);
        wizard->jumpToFrame(0);
    }
    else
    {
        setMovie(wizard);
        wizard->start();
    }
}

void CharacterPic::BarbarianPic(QString hit)
{
    if (hit!="hit")
    {
        setMovie(barbarian);
        barbarian->jumpToFrame(0);
    }
    else
    {
        setMovie(barbarian);
        barbarian->start();
    }
}

void CharacterPic::ElfPic(QString hit)
{
    if (hit!="hit")
    {
        setMovie(elf);
        elf->jumpToFrame(0);
    }
    else
    {
        setMovie(elf);
        elf->start();
    }
}

void CharacterPic::DwarfPic(QString hit)
{
    if (hit!="hit")
    {
        setMovie(dwarf);
        dwarf->jumpToFrame(0);
    }
    else
    {
        setMovie(dwarf);
        dwarf->start();
    }
}

void CharacterPic::changePic(int id,QString hit)
{
    if (id==0) WarriorPic(hit);
    else if (id==1) ClericPic(hit);
    else if (id==2) RoguePic(hit);
    else if (id==3) WizardPic(hit);
    else if (id==4) BarbarianPic(hit);
    else if (id==5) ElfPic(hit);
    else if (id==6) DwarfPic(hit);
}



