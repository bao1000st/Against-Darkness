#ifndef PARTYARROW_H
#define PARTYARROW_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class PartyArrow: public QGraphicsPixmapItem {
public:
    PartyArrow(int x, int y);
    void UpArrow();
    void DownArrow();
    void LeftArrow();
    void RightArrow();

};

#endif // PARTYARROW_H
