#include "tile.h"

Tile::Tile(int x, int y)
{
    setGeometry(QRect(x,y,60,60));
    setAttribute(Qt::WA_TranslucentBackground);
    setPixmap(QPixmap(":/res/images/Void.png"));

    //fountain = new QMovie(":/res/images/Fountain.gif");
    //fountain->start();
}

void Tile::VoidTile()
{
    setPixmap(QPixmap(":/res/images/Void.png"));
}

void Tile::FloorTile()
{
    setPixmap(QPixmap(":/res/images/Floor.png"));
}

void Tile::CorridorTile()
{
    setPixmap(QPixmap(":/res/images/Corridor.png"));
}

void Tile::DoorTile()
{
    setPixmap(QPixmap(":/res/images/Door.png"));
}

void Tile::TreasureTile()
{
    setPixmap(QPixmap(":/res/images/Treasure.png"));
}

void Tile::TrapTreasureTile()
{
    setPixmap(QPixmap(":/res/images/TrapTreasure.png"));
}

void Tile::FountainTile()
{
    setPixmap(QPixmap(":/res/images/Fountain.png"));
}

void Tile::DriedFountainTile()
{
    setPixmap(QPixmap(":/res/images/DriedFountain.png"));
}

void Tile::HolyRelicTile()
{
    setPixmap(QPixmap(":/res/images/HolyRelic.png"));
}

void Tile::UsedHolyRelicTile()
{
    setPixmap(QPixmap(":/res/images/UsedHolyRelic.png"));
}

void Tile::ArmoryTile()
{
    setPixmap(QPixmap(":/res/images/Armory.png"));
}

void Tile::CursedAltarTile()
{
    setPixmap(QPixmap(":/res/images/CursedAltar.png"));
}

void Tile::StatueTile()
{
    setPixmap(QPixmap(":/res/images/Statue.png"));
}

void Tile::PuzzleTile()
{
    setPixmap(QPixmap(":/res/images/Puzzle.png"));
}

void Tile::SolvedPuzzleTile()
{
    setPixmap(QPixmap(":/res/images/SolvedPuzzle.png"));
}


void Tile::ScorpionsTile()
{
    setPixmap(QPixmap(":/res/images/Scorpions.png"));
}

void Tile::VampireBatsTile()
{
    setPixmap(QPixmap(":/res/images/VampireBats.png"));
}

void Tile::GoblinSwarmlingsTile()
{
    setPixmap(QPixmap(":/res/images/GoblinSwarmlings.png"));
}

void Tile::GiantCentipedesTile()
{
    setPixmap(QPixmap(":/res/images/GiantCentipedes.png"));
}

void Tile::VampireFrogsTile()
{
    setPixmap(QPixmap(":/res/images/VampireFrogs.png"));
}

void Tile::GhoulsTile()
{
    setPixmap(QPixmap(":/res/images/Ghouls.png"));
}

void Tile::SkeletonsTile()
{
    setPixmap(QPixmap(":/res/images/Skeletons.png"));
}

void Tile::ZombiesTile()
{
    setPixmap(QPixmap(":/res/images/Zombies.png"));
}

void Tile::GoblinsTile()
{
    setPixmap(QPixmap(":/res/images/Goblins.png"));
}

void Tile::HobgoblinsTile()
{
    setPixmap(QPixmap(":/res/images/Hobgoblins.png"));
}

void Tile::OrcsTile()
{
    setPixmap(QPixmap(":/res/images/Orcs.png"));
}

void Tile::TrollsTile()
{
    setPixmap(QPixmap(":/res/images/Trolls.png"));
}

void Tile::FungiFolkTile()
{
    setPixmap(QPixmap(":/res/images/FungiFolk.png"));
}

void Tile::MinotaurTile()
{
    setPixmap(QPixmap(":/res/images/Minotaur.png"));
}

void Tile::IronEaterTile()
{
    setPixmap(QPixmap(":/res/images/IronEater.png"));
}

void Tile::ChimeraTile()
{
    setPixmap(QPixmap(":/res/images/Chimera.png"));
}

void Tile::CatoblepasTile()
{
    setPixmap(QPixmap(":/res/images/Catoblepas.png"));
}

void Tile::InsectKingTile()
{
   setPixmap(QPixmap(":/res/images/InsectKing.png"));
}


void Tile::changeTile(int id)
{
    if (id==0) VoidTile();
    else if (id==1) FloorTile();
    else if (id==2) DoorTile();
    else if (id==3) CorridorTile();
    else if (id==4) TreasureTile();
    else if (id==5) TrapTreasureTile();
    else if (id==6) FountainTile();
    else if (id==7) DriedFountainTile();
    else if (id==8) HolyRelicTile();
    else if (id==9) UsedHolyRelicTile();
    else if (id==10) ArmoryTile();
    else if (id==11) CursedAltarTile();
    else if (id==12) StatueTile();
    else if (id==13) PuzzleTile();
    else if (id==14) SolvedPuzzleTile();
    else if (id==16) ScorpionsTile();
    else if (id==17) VampireBatsTile();
    else if (id==18) GoblinSwarmlingsTile();
    else if (id==19) GiantCentipedesTile();
    else if (id==20) VampireFrogsTile();
    else if (id==21) GhoulsTile();
    else if (id==22) SkeletonsTile();
    else if (id==23) ZombiesTile();
    else if (id==24) GoblinsTile();
    else if (id==25) HobgoblinsTile();
    else if (id==26) OrcsTile();
    else if (id==27) TrollsTile();
    else if (id==28) FungiFolkTile();
    else if (id==29) MinotaurTile();
    else if (id==30) IronEaterTile();
    else if (id==31) ChimeraTile();
    else if (id==32) CatoblepasTile();
    else if (id==33) InsectKingTile();
    else VoidTile();
}
