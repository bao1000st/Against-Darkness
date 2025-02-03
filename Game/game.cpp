#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QLabel>
#include <QMovie>
#include <QRectF>
#include <QDebug>
#include <QMediaPlayer>
#include <QMediaPlaylist>

#include "game.h"
#include "ui.h"
#include "text.h"

Game::Game(QWidget *parent)
{

    // create a scene
    QGraphicsScene * characterCreatorScene = new QGraphicsScene();
    characterCreatorScene->setSceneRect(0,0,1360,768);
    characterCreatorScene->setBackgroundBrush(QBrush(QImage(":/res/images/background.png")));


    // add a view
    setScene(characterCreatorScene);
    setFixedSize(1360,768);
    int x=100,y=height()/2;
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    UI * creator = new UI(x-8,y+10,characterCreatorScene);
    creator->setFlag(QGraphicsItem::ItemIsFocusable);
    creator->setFocus();
    characterCreatorScene->addItem(creator);

    scale(1.1,1.1);


//    QLabel *gif_anim = new QLabel();
//    gif_anim->setAttribute(Qt::WA_TranslucentBackground);
//    QMovie *movie = new QMovie(":/res/images/Fountain.gif");
//    gif_anim->setMovie(movie);
//    movie->start();
//    QGraphicsProxyWidget * z = characterCreatorScene->addWidget(gif_anim);

    //show();
    showFullScreen();
}


