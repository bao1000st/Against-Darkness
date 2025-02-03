#ifndef EFFECT_H
#define EFFECT_H
#include <QLabel>
#include <QImage>
#include <QMovie>
#include <QGraphicsItem>

class Effect: public QLabel {
public:
    Effect(int x,int y);
    void warriorattackEffect();
    void clericattackEffect();
    void rogueattackEffect();
    void wizardattackEffect();
    void barbarianattackEffect();
    void elfattackEffect();
    void dwarfattackEffect();
    void shotEffect();
    void holywaterEffect();
    void fireballEffect();
    void lightningboltEffect();
    void sleepingEffect();
    void protectingEffect();
    void escapingEffect(int place);
    void teleportringEffect(int place); 
    void attackEffect(int characterid);
    void missEffect();

    void monsterAttackEffect(int place);
    void monsterFireAttackEffect(int place);
    void monsterLightningAttackEffect(int place);
    void missMonsterEffect(int place);
private:
    QMovie * warriorattack;
    QMovie * clericattack;
    QMovie * rogueattack;
    QMovie * wizardattack;
    QMovie * barbarianattack;
    QMovie * elfattack;
    QMovie * dwarfattack;
    QMovie * attack;
    QMovie * shot;
    QMovie * holywater;
    QMovie * fireball;
    QMovie * lightningbolt;
    QMovie * sleeping;
    QMovie * protecting;
    QMovie * escaping;
    QMovie * teleportring;
    QMovie * monsterAttack;
    QMovie * miss;
    int x;
    int y;
};

#endif // EFFECT_H
