#include "itempic.h"


ItemPic::ItemPic(int x, int y)
{
    setPos(x,y);
    setPixmap(QPixmap(""));
}

void ItemPic::ShieldPic()
{
    setPixmap(QPixmap(":/res/images/Shield.png"));
}

void ItemPic::SlingPic()
{
    setPixmap(QPixmap(":/res/images/Sling.png"));
}

void ItemPic::BowPic()
{
    setPixmap(QPixmap(":/res/images/Bow.png"));
}

void ItemPic::LightWeaponPic()
{

    setPixmap(QPixmap(":/res/images/LightWeapon.png"));
}

void ItemPic::CrushingHandWeaponPic()
{
    setPixmap(QPixmap(":/res/images/CrushingHandWeapon.png"));
}

void ItemPic::SlashingHandWeaponPic()
{
    setPixmap(QPixmap(":/res/images/SlashingHandWeapon.png"));
}

void ItemPic::CrushingTwohandedWeaponPic()
{
    setPixmap(QPixmap(":/res/images/CrushingTwo-handedWeapon.png"));
}

void ItemPic::SlashingTwohandedWeaponPic()
{
    setPixmap(QPixmap(":/res/images/SlashingTwo-handedWeapon.png"));
}

void ItemPic::PoisonSlashingHandWeaponPic()
{
    setPixmap(QPixmap(":/res/images/PoisonSlashingHandWeapon.png"));
}

void ItemPic::PoisonSlashingTwohandedWeaponPic()
{
    setPixmap(QPixmap(":/res/images/PoisonSlashingTwo-handedWeapon.png"));
}

void ItemPic::LightArmorPic()
{
    setPixmap(QPixmap(":/res/images/LightArmor.png"));
}

void ItemPic::HeavyArmorPic()
{
    setPixmap(QPixmap(":/res/images/HeavyArmor.png"));
}

void ItemPic::BandagePic()
{
    setPixmap(QPixmap(":/res/images/Bandage.png"));
}

void ItemPic::RopePic()
{
    setPixmap(QPixmap(":/res/images/Rope.png"));
}

void ItemPic::HolyWaterVialPic()
{
    setPixmap(QPixmap(":/res/images/HolyWaterVial.png"));
}

void ItemPic::GemPic()
{
    setPixmap(QPixmap(":/res/images/Gem.png"));
}

void ItemPic::JewelryPic()
{
    setPixmap(QPixmap(":/res/images/Jewelry.png"));
}

void ItemPic::ResurrectionRitualPic()
{
    setPixmap(QPixmap(":/res/images/ResurrectionRitual.png"));
}

void ItemPic::BlessingSpellPic()
{
    setPixmap(QPixmap(":/res/images/BlessingSpell.png"));
}

void ItemPic::FireballSpellPic()
{
    setPixmap(QPixmap(":/res/images/FireballSpell.png"));
}

void ItemPic::LightningBoltSpellPic()
{
    setPixmap(QPixmap(":/res/images/LightningBoltSpell.png"));
}

void ItemPic::SleepingSpellPic()
{
    setPixmap(QPixmap(":/res/images/SleepingSpell.png"));
}

void ItemPic::EscapingSpellPic()
{
    setPixmap(QPixmap(":/res/images/EscapingSpell.png"));
}

void ItemPic::ProtectingSpellPic()
{
    setPixmap(QPixmap(":/res/images/ProtectingSpell.png"));
}

void ItemPic::PotionofHealingPic()
{
    setPixmap(QPixmap(":/res/images/PotionofHealing.png"));
}

void ItemPic::WandofSleepPic()
{
    setPixmap(QPixmap(":/res/images/WandofSleep.png"));
}

void ItemPic::RingofTeleportationPic()
{
    setPixmap(QPixmap(":/res/images/RingofTeleportation.png"));
}

void ItemPic::FoolsGoldPic()
{
    setPixmap(QPixmap(":/res/images/FoolsGold.png"));
}

void ItemPic::MagicWeaponPic()
{
    setPixmap(QPixmap(":/res/images/MagicWeapon.png"));
}

void ItemPic::FireballStaffPic()
{
    setPixmap(QPixmap(":/res/images/FireballStaff.png"));
}

void ItemPic::BlessingGlovesPic()
{
    setPixmap(QPixmap(":/res/images/BlessingGloves.png"));
}

void ItemPic::HealingStaffPic()
{
    setPixmap(QPixmap(":/res/images/HealingStaff.png"));
}

void ItemPic::changePic(int id)
{
    if (id==0) ShieldPic();
    else if (id==1) SlingPic();
    else if (id==2) BowPic();
    else if (id==3) LightWeaponPic();
    else if (id==4) CrushingHandWeaponPic();
    else if (id==5) SlashingHandWeaponPic();
    else if (id==6) CrushingTwohandedWeaponPic();
    else if (id==7) SlashingTwohandedWeaponPic();
    else if (id==8) PoisonSlashingHandWeaponPic();
    else if (id==9) PoisonSlashingTwohandedWeaponPic();
    else if (id==10) LightArmorPic();
    else if (id==11) HeavyArmorPic();
    else if (id==12) BandagePic();
    else if (id==13) RopePic();
    else if (id==14) HolyWaterVialPic();
    else if (id==15) GemPic();
    else if (id==16) JewelryPic();
    else if (id==17) ResurrectionRitualPic();
    else if (id==18) BlessingSpellPic();
    else if (id==19) FireballSpellPic();
    else if (id==20) LightningBoltSpellPic();
    else if (id==21) SleepingSpellPic();
    else if (id==22) EscapingSpellPic();
    else if (id==23) ProtectingSpellPic();
    else if (id==24) PotionofHealingPic();
    else if (id==25) WandofSleepPic();
    else if (id==26) RingofTeleportationPic();
    else if (id==27) FoolsGoldPic();
    else if (id==28) MagicWeaponPic();
    else if (id==29) FireballStaffPic();
    else if (id==30) BlessingGlovesPic();
    else if (id==31) HealingStaffPic();
    else EmptyPic();
}

void ItemPic::EmptyPic()
{
    setPixmap(QPixmap(""));
}
