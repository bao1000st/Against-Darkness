#ifndef ITEMPIC_H
#define ITEMPIC_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>



class ItemPic: public QGraphicsPixmapItem {
public:
    ItemPic(int x,int y);
    void ShieldPic();
    void SlingPic();
    void BowPic();
    void LightWeaponPic();
    void CrushingHandWeaponPic();
    void SlashingHandWeaponPic();
    void CrushingTwohandedWeaponPic();
    void SlashingTwohandedWeaponPic();
    void PoisonSlashingHandWeaponPic();
    void PoisonSlashingTwohandedWeaponPic();
    void LightArmorPic();
    void HeavyArmorPic();
    void BandagePic();
    void RopePic();
    void HolyWaterVialPic();
    void GemPic();
    void JewelryPic();
    void ResurrectionRitualPic();
    void BlessingSpellPic();
    void FireballSpellPic();
    void LightningBoltSpellPic();
    void SleepingSpellPic();
    void EscapingSpellPic();
    void ProtectingSpellPic();
    void PotionofHealingPic();
    void WandofSleepPic();
    void RingofTeleportationPic();
    void FoolsGoldPic();
    void MagicWeaponPic();
    void FireballStaffPic();
    void BlessingGlovesPic();
    void HealingStaffPic();
    void changePic(int id);
    void EmptyPic();
};

#endif // ITEMPIC_H
