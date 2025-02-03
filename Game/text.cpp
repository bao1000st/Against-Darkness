#include "text.h"

#include <QFont>
#include <QFontDatabase>


Text::Text(int x,int y)
{
    setFont(QFont("times"));
    setDefaultTextColor(Qt::white);
    setScale(0.8);
    setPos(x,y);
}

void Text::infomanFont()
{
    setScale(1.2);
    int id = QFontDatabase::addApplicationFont(":/res/fonts/INFROMAN.TTF");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont infoman(family);
    setFont(QFont(infoman));
}

void Text::normalFont()
{
    setScale(0.8);
    setFont(QFont("times"));
}

