#ifndef CHARACTER_H
#define CHARACTER_H
#include <QLabel>
#include <QImage>
#include <QMovie>
#include <QGraphicsItem>

class CharacterPic: public QLabel {
public:
    CharacterPic(int x,int y);

    void WarriorPic(QString hit);
    void ClericPic(QString hit);
    void RoguePic(QString hit);
    void WizardPic(QString hit);
    void BarbarianPic(QString hit);
    void ElfPic(QString hit);
    void DwarfPic(QString hit);
    void changePic(int id,QString hit);
    int x,y;
private:
    QMovie * warrior;
    QMovie * cleric;
    QMovie * rogue;
    QMovie * wizard;
    QMovie * barbarian;
    QMovie * dwarf;
    QMovie * elf;
};

#endif // CHARACTER_H
