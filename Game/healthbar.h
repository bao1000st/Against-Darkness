#ifndef HEALTHBAR_H
#define HEALTHBAR_H
#include <QLabel>
#include <QImage>
#include <QMovie>
#include <QGraphicsItem>

class HealthBar: public QLabel {
public:
    HealthBar(int x,int y);
    void setHealth(int hp,int maxHp);
    QGraphicsRectItem * health;
private:
    int x,y;

};

#endif // HEALTHBAR_H
