#ifndef CHARACTERCREATOR_H
#define CHARACTERCREATOR_H
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsProxyWidget>
#include <QTime>
#include <QCoreApplication>
#include <QEventLoop>
#include <QMediaPlayer>
#include <QFileInfo>
#include <QApplication>
#include "battlebackground.h"
#include "portrait.h"
#include "infobox.h"
#include "data.h"
#include "tile.h"
#include "partyarrow.h"
#include "text.h"
#include "characterpic.h"
#include "monsterpic.h"
#include "effect.h"
#include "itempic.h"
#include "healthbar.h"


class UI: public QGraphicsPixmapItem {
public:
    QString gamePhase;
    Data * data;

    int characterPointer;
    int swapCharacterPointer;
    int classids[5];
    int battlePointer;
    int actionPointer;
    int monsterInfoPointer;
    int managePointer;
    int itemPointer;
    int affectItemPointer;

    Portrait * characters[5];
    InfoBox * infobox;
    ItemPic * itemPics[7];

    CharacterPic * characterPics[4];
    QGraphicsProxyWidget * characterPicProxy[4];
    HealthBar * characterHealthBars[4];
    QGraphicsProxyWidget * characterHealthBarProxy[4];

    QGraphicsPixmapItem * overworldBorder;
    QGraphicsPixmapItem * mapBorder;
    QGraphicsPixmapItem * quickInfoBorder;
    QGraphicsPixmapItem * gameOver;

    Tile * tileMap[7][7];
    QGraphicsProxyWidget * tileMapProxy[7][7];

    MonsterPic * monsterPic;
    QGraphicsProxyWidget * monsterPicProxy;

    Effect * battleEffect;
    QGraphicsProxyWidget * battleEffectProxy;

    Effect * monsterEffect;
    QGraphicsProxyWidget * monsterEffectProxy;

    BattleBackground * battleBackground;
    QGraphicsProxyWidget * battleBackgroundProxy;

    BattleBackground * hitFlash;
    QGraphicsProxyWidget * hitFlashProxy;

    PartyArrow * arrow;
    Text * mapInfo;
    Text * characterInfo;
    Text * partyQuickInfo;
    Text * eventInfo;
    Text * monsterLife;

    QMediaPlayer * music;
    QMediaPlayer * navigate;
    QMediaPlayer * select;
    QMediaPlayer * step;
    QMediaPlayer * heal;
    QMediaPlayer * bless;
    QMediaPlayer * attack;
    QMediaPlayer * hit;
    QMediaPlayer * use;
    QMediaPlayer * shot;
    QMediaPlayer * escaping;
    QMediaPlayer * fireball;
    QMediaPlayer * holywater;
    QMediaPlayer * lightningbolt;
    QMediaPlayer * protecting;
    QMediaPlayer * sleeping;
    QMediaPlayer * teleportring;

    UI(int x, int y,QGraphicsScene * scene);
    void keyPressEvent(QKeyEvent * event);

private:
    void updateInfoBox(int id);
    void updatePortrait(int character,int id);
    void endCharacterCreation();
    void startShop();
    void endShop();
    void startCharacterInfo();
    void startInGame();
    void startBattle();
    void endBattle(QString outcome);
    void startManageCharacter();
    void endManageCharacter();
    void startSwapCharacter();
    void endSwapCharacter();
    void startManageItems();
    void endManageItems();
    void startAffectItem();
    void endAffectItem();
    void startTransferItem();
    void endTransferItem();
    void startBlessHealCharacter();
    void endBlessHealCharacter();
    void startUseItemInBattle();
    void endUseItemInBattle();

    void updateMap();
    void printMapInfo();
    void updateShopInfo();
    void updateCharacterInfo(int character);
    void updatePartyQuickInfo();
    void updateMonsterEventInfo();
    void updateActionInfo();
    void updateManagementInfo();
    void updateItemManagementInfo(int characterid);
    void updateAffectItemInfo();

    void buyAction();
    void nextBuyer();
    void levelupAction();
    void attackAction();
    void shotAction();
    void fleeAction();
    void useItemAction();
    void useItemInBattleAction();
    void nextBattleCharacter();
    void monsterAttackPhase();
    void delay(float second);

    void navigateSound();
    void selectSound();
    void stepSound();
    void healSound();
    void blessSound();
    void attackSound();
    void hitSound();
    void useSound();
    void shotSound();
    void escapingSound();
    void fireballSound();
    void holywaterSound();
    void lightningboltSound();
    void protectingSound();
    void sleepingSound();
    void teleportringSound();

    void dungeonMusic();
    void battleMusic();

};

#endif // CHARACTERCREATOR_H
