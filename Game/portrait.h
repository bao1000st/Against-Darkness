#ifndef PORTRAIT_H
#define PORTRAIT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Portrait: public QGraphicsPixmapItem {
public:
    Portrait(int x, int y);
    void StartPortrait();
    void EmptyPortrait();
    void WarriorPortrait();
    void ClericPortrait();
    void RoguePortrait();
    void WizardPortrait();
    void BarbarianPortrait();
    void ElfPortrait();
    void DwarfPortrait();
};

#endif // PORTRAIT_H
