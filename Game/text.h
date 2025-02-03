#ifndef TEXT_H
#define TEXT_H
#include <QGraphicsTextItem>

class Text : public QGraphicsTextItem {
public:
    Text(int x,int y);
    void infomanFont();
    void normalFont();
};

#endif // TEXT_H
