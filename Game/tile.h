#ifndef TILE_H
#define TILE_H

#include <QLabel>
#include <QImage>
#include <QMovie>
#include <QGraphicsItem>

class Tile: public QLabel {
public:
    Tile(int x,int y);
    void VoidTile();
    void FloorTile();
    void CorridorTile();
    void DoorTile();
    void TreasureTile();
    void TrapTreasureTile();
    void FountainTile();
    void DriedFountainTile();
    void HolyRelicTile();
    void UsedHolyRelicTile();
    void ArmoryTile();
    void CursedAltarTile();
    void StatueTile();
    void PuzzleTile();
    void SolvedPuzzleTile();
    void ScorpionsTile();
    void VampireBatsTile();
    void GoblinSwarmlingsTile();
    void GiantCentipedesTile();
    void VampireFrogsTile();
    void GhoulsTile();
    void SkeletonsTile();
    void ZombiesTile();
    void GoblinsTile();
    void HobgoblinsTile();
    void OrcsTile();
    void TrollsTile();
    void FungiFolkTile();
    void MinotaurTile();
    void IronEaterTile();
    void ChimeraTile();
    void CatoblepasTile();
    void InsectKingTile();
    void changeTile(int id);
private:
    //QMovie * fountain;
};

#endif // TILE_H
