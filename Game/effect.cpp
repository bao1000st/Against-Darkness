#include "effect.h"

Effect::Effect(int x, int y)
{
    setGeometry(QRect(x,y,552,516));
    setAttribute(Qt::WA_TranslucentBackground);
    attack = new QMovie(":/res/images/attack.gif");
    shot = new QMovie(":/res/images/shot.gif");
    holywater = new QMovie(":/res/images/holywater.gif");
    fireball = new QMovie(":/res/images/fireball.gif");
    lightningbolt = new QMovie(":/res/images/lightningbolt.gif");
    sleeping = new QMovie(":/res/images/sleeping.gif");
    protecting = new QMovie(":/res/images/protecting.gif");
    escaping = new QMovie(":/res/images/escaping.gif");
    teleportring = new QMovie(":/res/images/teleportring.gif");

    monsterAttack = new QMovie(":/res/images/claw.gif");
    warriorattack = new QMovie(":/res/images/warriorattack.gif");
    clericattack = new QMovie(":/res/images/clericattack.gif");
    rogueattack = new QMovie(":/res/images/rogueattack.gif");
    wizardattack = new QMovie(":/res/images/wizardattack.gif");
    barbarianattack = new QMovie(":/res/images/barbarianattack.gif");
    elfattack = new QMovie(":/res/images/elfattack.gif");
    dwarfattack = new QMovie(":/res/images/dwarfattack.gif");
    miss = new QMovie(":/res/images/miss.gif");

    this->x=x;
    this->y=y;

}

void Effect::warriorattackEffect()
{
    move(x+(276-30),y+30);
    setMovie(warriorattack);
    warriorattack->start();

}

void Effect::clericattackEffect()
{
    move(x+(276-20),y+30);
    setMovie(clericattack);
    clericattack->start();

}

void Effect::rogueattackEffect()
{
    move(x+(276-27),y+30);
    setMovie(rogueattack);
    rogueattack->start();

}

void Effect::wizardattackEffect()
{
    move(x+(276-20),y+30);
    setMovie(wizardattack);
    wizardattack->start();

}

void Effect::barbarianattackEffect()
{
    move(x+(276-30),y+30);
    setMovie(barbarianattack);
    barbarianattack->start();

}

void Effect::elfattackEffect()
{
    move(x+(276-30),y+30);
    setMovie(elfattack);
    elfattack->start();
}

void Effect::dwarfattackEffect()
{
    move(x+(276-30),y+30);
    setMovie(dwarfattack);
    dwarfattack->start();
}

void Effect::shotEffect()
{
    move(x+(276-70),y);
    setMovie(shot);
    shot->start();
}

void Effect::holywaterEffect()
{
    move(x+(276-120),y);
    setMovie(holywater);
    holywater->start();
}

void Effect::fireballEffect()
{
    move(x+(276-120),y-35);
    setMovie(fireball);
    fireball->start();
}

void Effect::lightningboltEffect()
{
    move(x+(276-120),y-35);
    setMovie(lightningbolt);
    lightningbolt->start();
}

void Effect::sleepingEffect()
{
    move(x+(276-80),y-35);
    setMovie(sleeping);
    sleeping->start();
}

void Effect::protectingEffect()
{
    move(x+(276-90),y-35);
    setMovie(protecting);
    protecting->start();
}

void Effect::escapingEffect(int place)
{
    move(x+(276-100)+(75)*place,y-30);
    setMovie(escaping);
    escaping->start();
}

void Effect::teleportringEffect(int place)
{
    move(x+(276-80)+(75)*place,y-50);
    setMovie(teleportring);
    teleportring->start();
}

void Effect::monsterAttackEffect(int place)
{
    move(x+(276-89)+(80)*place,y);
    setMovie(monsterAttack);
    monsterAttack->start();
}

void Effect::monsterFireAttackEffect(int place)
{
    move(x+(276-145)+(80)*place,y-40);
    setMovie(fireball);
    fireball->start();
}

void Effect::monsterLightningAttackEffect(int place)
{
    move(x+(276-160)+(80)*place,y-30);
    setMovie(lightningbolt);
    lightningbolt->start();
}

void Effect::attackEffect(int characterid)
{
    if (characterid==0) warriorattackEffect();
    else if (characterid==1) clericattackEffect();
    else if (characterid==2) rogueattackEffect();
    else if (characterid==3) wizardattackEffect();
    else if (characterid==4) barbarianattackEffect();
    else if (characterid==5) elfattackEffect();
    else if (characterid==6) dwarfattackEffect();
    else
    {
        move(x+(276-70),y);
        attack->start();
        setMovie(attack);
    };
}

void Effect::missEffect()
{
    move(x+(276-48),y-35);
    setMovie(miss);
    miss->start();
}

void Effect::missMonsterEffect(int place)
{
    move(x+(276-65)+(75)*place,y-35);
    setMovie(miss);
    miss->start();
}


