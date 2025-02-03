#ifndef BOX_H
#define BOX_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class InfoBox: public QGraphicsPixmapItem {
public:
    InfoBox(int x,int y);
    void WarriorBox();
    void ClericBox();
    void RogueBox();
    void WizardBox();
    void BarbarianBox();
    void ElfBox();
    void DwarfBox();
    void EmptyBox();
};

#endif // BOX_H
