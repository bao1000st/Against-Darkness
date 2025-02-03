#include "monsterpic.h"

MonsterPic::MonsterPic(int x, int y)
{
    setGeometry(QRect(x,y,552,516));
    setAttribute(Qt::WA_TranslucentBackground);
    this->x=x;
    this->y=y;
    scorpions = new QMovie(":/res/images/Scorpions.gif");

    vampirebats = new QMovie(":/res/images/VampireBats.gif");
    goblinswarmlings = new QMovie(":/res/images/GoblinSwarmlings.gif");
    giantcentipedes = new QMovie(":/res/images/GiantCentipedes.gif");
    vampirefrogs = new QMovie(":/res/images/VampireFrogs.gif");
    ghouls = new QMovie(":/res/images/Ghouls.gif");
    statue = new QMovie(":/res/images/Statue.gif");
    skeletons = new QMovie(":/res/images/Skeletons.gif");
    zombies = new QMovie(":/res/images/Zombies.gif");
    goblins = new QMovie(":/res/images/Goblins.gif");
    hobgoblins = new QMovie(":/res/images/Hobgoblins.gif");
    orcs = new QMovie(":/res/images/Orcs.gif");
    trolls = new QMovie(":/res/images/Trolls.gif");
    fungifolk = new QMovie(":/res/images/FungiFolk.gif");
    minotaur = new QMovie(":/res/images/Minotaur.gif");
    ironeater = new QMovie(":/res/images/IronEater.gif");
    chimera = new QMovie(":/res/images/Chimera.gif");
    catoblepas = new QMovie(":/res/images/Catoblepas.gif");
    insectking = new QMovie(":/res/images/InsectKing.gif");
}

void MonsterPic::scorpionsPic(QString action)
{
    if (action=="move")
    {
        scorpions->setScaledSize(QSize(371,89));
        move(x+(276-185),y);
    }
    else
    {
        scorpions->setScaledSize(QSize(247,59));
        move(x+(276-123),y);
    }
    setMovie(scorpions);
    scorpions->start();
}

void MonsterPic::vampirebatsPic(QString action)
{
    if (action=="move")
    {
        vampirebats->setScaledSize(QSize(323,123));
        move(x+(276-161),y);
    }
    else
    {
        vampirebats->setScaledSize(QSize(215,82));
        move(x+(276-107),y);
    }
    setMovie(vampirebats);
    vampirebats->start();
}

void MonsterPic::goblinswarmlingsPic(QString action)
{
    if (action=="move")
    {
        goblinswarmlings->setScaledSize(QSize(169,73));
        move(x+(276-84),y);
    }
    else
    {
        goblinswarmlings->setScaledSize(QSize(113,49));
        move(x+(276-56),y);
    }
    setMovie(goblinswarmlings);
    goblinswarmlings->start();
}

void MonsterPic::giantcentipedesPic(QString action)
{
    if (action=="move")
    {
        giantcentipedes->setScaledSize(QSize(386,128));
        move(x+(276-192),y);
    }
    else
    {
        giantcentipedes->setScaledSize(QSize(257,85));
        move(x+(276-128),y);
    }
    setMovie(giantcentipedes);
    giantcentipedes->start();
}

void MonsterPic::vampirefrogsPic(QString action)
{
    if (action=="move")
    {
        vampirefrogs->setScaledSize(QSize(169,48));
        move(x+(276-84),y);
    }
    else
    {
        vampirefrogs->setScaledSize(QSize(113,32));
        move(x+(276-56),y+10);
    }
    setMovie(vampirefrogs);
    vampirefrogs->start();
}

void MonsterPic::ghoulsPic(QString action)
{
    if (action=="move")
    {
        ghouls->setScaledSize(QSize(161,92));
        move(x+(276-80),y);
    }
    else
    {
        ghouls->setScaledSize(QSize(107,61));
        move(x+(276-53),y);
    }
    setMovie(ghouls);
    ghouls->start();
}

void MonsterPic::statuePic(QString action)
{
    if (action=="move")
    {
        statue->setScaledSize(QSize(117,128));
        move(x+(276-58),y);
    }
    else
    {
        statue->setScaledSize(QSize(78,85));
        move(x+(276-39),y);
    }
    setMovie(statue);
    statue->start();
}

void MonsterPic::skeletonsPic(QString action)
{
    if (action=="move")
    {
        skeletons->setScaledSize(QSize(314,123));
        move(x+(276-157),y);
    }
    else
    {
        skeletons->setScaledSize(QSize(209,82));
        move(x+(276-104),y);
    }
    setMovie(skeletons);
    skeletons->start();
}

void MonsterPic::zombiesPic(QString action)
{
    if (action=="move")
    {
        zombies->setScaledSize(QSize(152,102));
        move(x+(276-76),y);
    }
    else
    {
        zombies->setScaledSize(QSize(101,68));
        move(x+(276-50),y);
    }
    setMovie(zombies);
    zombies->start();
}

void MonsterPic::goblinsPic(QString action)
{
    if (action=="move")
    {
        goblins->setScaledSize(QSize(216,96));
        move(x+(276-108),y);
    }
    else
    {
        goblins->setScaledSize(QSize(144,64));
        move(x+(276-72),y);
    }
    setMovie(goblins);
    goblins->start();
}

void MonsterPic::hobgoblinsPic(QString action)
{
    if (action=="move")
    {
        hobgoblins->setScaledSize(QSize(210,104));
        move(x+(276-105),y);
    }
    else
    {
        hobgoblins->setScaledSize(QSize(140,69));
        move(x+(276-70),y);
    }
    setMovie(hobgoblins);
    hobgoblins->start();
}

void MonsterPic::orcsPic(QString action)
{
    if (action=="move")
    {
        orcs->setScaledSize(QSize(206,78));
        move(x+(276-103),y);
    }
    else
    {
        orcs->setScaledSize(QSize(137,52));
        move(x+(276-68),y);
    }
    setMovie(orcs);
    orcs->start();
}

void MonsterPic::trollsPic(QString action)
{
    if (action=="move")
    {
        trolls->setScaledSize(QSize(368,117));
        move(x+(276-184),y);
    }
    else
    {
        trolls->setScaledSize(QSize(245,78));
        move(x+(276-122),y+10);
    }
    setMovie(trolls);
    trolls->start();
}

void MonsterPic::fungifolkPic(QString action)
{
    if (action=="move")
    {
        fungifolk->setScaledSize(QSize(169,51));
        move(x+(276-84),y);
    }
    else
    {
        fungifolk->setScaledSize(QSize(113,34));
        move(x+(276-56),y+10);
    }
    setMovie(fungifolk);
    fungifolk->start();
}

void MonsterPic::minotaurPic(QString action)
{
    if (action=="move")
    {
        minotaur->setScaledSize(QSize(89,121));
        move(x+(276-44),y);
    }
    else
    {
        minotaur->setScaledSize(QSize(59,80));
        move(x+(276-29),y+10);
    }
    setMovie(minotaur);
    minotaur->start();
}

void MonsterPic::ironeaterPic(QString action)
{
    if (action=="move")
    {
        ironeater->setScaledSize(QSize(122,95));
        move(x+(276-61),y);
    }
    else
    {
        ironeater->setScaledSize(QSize(81,63));
        move(x+(276-40),y+10);
    }
    setMovie(ironeater);
    ironeater->start();
}

void MonsterPic::chimeraPic(QString action)
{
    if (action=="move")
    {
        chimera->setScaledSize(QSize(120,102));
        move(x+(276-60),y);
    }
    else
    {
        chimera->setScaledSize(QSize(80,68));
        move(x+(276-40),y+5);
    }
    setMovie(chimera);
    chimera->start();
}

void MonsterPic::catoblepasPic(QString action)
{
    if (action=="move")
    {
        catoblepas->setScaledSize(QSize(89,115));
        move(x+(276-44),y);
    }
    else
    {
        catoblepas->setScaledSize(QSize(59,76));
        move(x+(276-29),y+10);
    }
    setMovie(catoblepas);
    catoblepas->start();
}

void MonsterPic::insectkingPic(QString action)
{
    if (action=="move")
    {
        insectking->setScaledSize(QSize(237,140));
        move(x+(276-118),y);
    }
    else
    {
        insectking->setScaledSize(QSize(158,93));
        move(x+(276-79),y+10);
    }
    setMovie(insectking);
    insectking->start();
}

void MonsterPic::changePic(QString monster,QString action)
{
    if (monster=="Scorpions") scorpionsPic(action);
    else if (monster=="Vampire Bats") vampirebatsPic(action);
    else if (monster=="Goblin Swarmlings") goblinswarmlingsPic(action);
    else if (monster=="Giant Centipedes") giantcentipedesPic(action);
    else if (monster=="Vampire Frogs") vampirefrogsPic(action);
    else if (monster=="Ghouls (Undead)") ghoulsPic(action);
    else if (monster=="Statue") statuePic(action);
    else if (monster=="Skeletons (Undead)") skeletonsPic(action);
    else if (monster=="Zombies (Undead)") zombiesPic(action);
    else if (monster=="Goblins") goblinsPic(action);
    else if (monster=="Hobgoblins") hobgoblinsPic(action);
    else if (monster=="Orcs") orcsPic(action);
    else if (monster=="Trolls") trollsPic(action);
    else if (monster=="Fungi Folk") fungifolkPic(action);
    else if (monster=="Minotaur") minotaurPic(action);
    else if (monster=="Iron Eater") ironeaterPic(action);
    else if (monster=="Chimera") chimeraPic(action);
    else if (monster=="Catoblepas" || monster=="Catoblepas-FirstAttack") catoblepasPic(action);
    else if (monster=="Insect King") insectkingPic(action);
}

void MonsterPic::merchantPic()
{
    move(x+(276-18),y);
    setPixmap(QPixmap(":/res/images/Merchant.png"));
}
