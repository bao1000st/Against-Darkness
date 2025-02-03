#ifndef BATTLEBACKGROUND_H
#define BATTLEBACKGROUND_H
#include <QLabel>
#include <QImage>
#include <QMovie>
#include <QGraphicsItem>


class BattleBackground: public QLabel {
public:
    BattleBackground(int x,int y);
    void changePic(QString use);
private:
    QMovie * background1;
    QMovie * flash;
    int x,y;
};

#endif // BATTLEBACKGROUND_H
