#ifndef MONSTERPIC_H
#define MONSTERPIC_H
#include <QLabel>
#include <QImage>
#include <QMovie>
#include <QGraphicsItem>


class MonsterPic: public QLabel {
public:
    MonsterPic(int x,int y);
    void scorpionsPic(QString action);
    void vampirebatsPic(QString action);
    void goblinswarmlingsPic(QString action);
    void giantcentipedesPic(QString action);
    void vampirefrogsPic(QString action);
    void ghoulsPic(QString action);
    void statuePic(QString action);
    void skeletonsPic(QString action);
    void zombiesPic(QString action);
    void goblinsPic(QString action);
    void hobgoblinsPic(QString action);
    void orcsPic(QString action);
    void trollsPic(QString action);
    void fungifolkPic(QString action);
    void minotaurPic(QString action);
    void ironeaterPic(QString action);
    void chimeraPic(QString action);
    void catoblepasPic(QString action);
    void insectkingPic(QString action);
    void changePic(QString monster, QString action);
    void merchantPic();
    int x,y;
private:
    QMovie * scorpions;
    QMovie * vampirebats;
    QMovie * goblinswarmlings;
    QMovie * giantcentipedes;
    QMovie * vampirefrogs;
    QMovie * ghouls;
    QMovie * statue;
    QMovie * skeletons;
    QMovie * zombies;
    QMovie * goblins;
    QMovie * hobgoblins;
    QMovie * orcs;
    QMovie * trolls;
    QMovie * fungifolk;
    QMovie * minotaur;
    QMovie * ironeater;
    QMovie * chimera;
    QMovie * catoblepas;
    QMovie * insectking;
};

#endif // MONSTERPIC_H
