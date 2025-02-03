#ifndef DATA_H
#define DATA_H
#include <QString>

typedef struct{
    int x,y;
}Coord;

typedef struct{
    int width,length;
    int Corridors,Doors;
    Coord Cs[4],Ds[4];
    int S[10][10];
}Room;

typedef struct{
    int size;
    Room Entr[10];
}Entrances;

typedef struct{
    int size;
    Room Ro[40];
}Rooms;


typedef struct{
    int isPass;
    int isInteractive;
    QString name;
}Object;

typedef struct{
    int size;
    Object Obj[200];	 ///////////////////// truoc mat la 200 doi tuong
}Objects;



typedef struct{
    QString CorridorResult;
    QString DoorResult;
}RoomContent;

typedef struct{
    int size;
    RoomContent RmCont[15];
}RoomContents;



typedef struct{
    QString MainHand;
    QString OffHand;
    QString Armor;
}ClassBuild;


typedef struct{
    QString ClassName;
    int BaseLife;
    int MaxLevel;
    int GoldDice;
    int numberofUsableEquipments;
    QString UsableEquipments[10];
    int numberofTraits;
    QString Traits[10];
    int numberofClassBuilds;
    ClassBuild ClssBuilds[10];
}Class;

typedef struct{
    int size;
    Class Clss[10];
}Classes;



typedef struct{
    QString Name;
    int Value;
    int Charges;
    QString description;
}Item;

typedef struct{
    int size;
    // int shopsize;
    Item Itm[50];
}Items;

typedef struct{
   int size;
   QString name[100];
}Names;



typedef struct{
    QString Name;
    int ClassId;
    int Life;
    int Level;
    int Clues;
    int isFlee;
    QString MainHand;
    QString OffHand;
    QString Armor;
    int ItemsSize;
    QString Items[100];
    int ItemCharges[100];
    int StatusSize;
    QString Status[20];
}Character;

typedef struct{
    Character Chars[4];
    int partysize;
    int totalGold;
    int xpRolls;
    int monstersKilled;
}Party;

typedef struct{
    int width, length;
    int screen_size;
    int Map[1000][1000];
    int Open[1000][1000]; //0: UnOpened, 1: Room Opened
    int room_counter;
    Coord EventTile;
    int EventTileKey;
    Coord PL;
}Map;


typedef struct{
    QString name;
    int amountDice;
    int amountModifier;
    int level;
    int treasureAmount;
    int treasureModifier;
    QString weakness;
    QString ability;
    QString reactions[6];
}Monster;

typedef struct{
    int verminSize;
    Monster vermins[20];

    int minionSize;
    Monster minions[20];

    int weirdMonsterSize;
    Monster weirdMonsters[20];

    int bossSize;
    Monster bosses[20];

    int specialMonsterSize;
    Monster specialMonsters[20];

}Monsters;


typedef struct {
    QString name;
    QString type;
    int amountDice;
    int amountModifier;
    int amount;
    int originalAmount;
    int level;
    int treasureAmount;
    int treasureModifier;
    QString weakness;
    QString ability;
    QString reaction;
}BattleMonster;




class Data
{
public:
    Entrances E;
    Rooms R;
    Objects O;
    RoomContents RC;
    Classes Clsses;
    Items Itms;
    Names Nms;
    Monsters Mns;
    BattleMonster battleMonster;
    int hasEvent;

    Party P;
    Map M;


    Data();

    void createCharacter(int characterid,int classid,int classbuildid);
    void createEntrance();
    int buyItem(int characterid,QString item);
    void swapCharacter(int characterid1, int characterid2);
    void transferItem(int itemindex,int characterid1, int characterid2);
    QString createRoom();
    void printMap();
    QString interactObject();
    QString characterAttack(int characterid);
    QString characterShot(int characterid);
    QString characterFlee(int characterid);
    QString characterLevelUp(int characterid);
    QString characterUseItem(int itemindex,int characterid,QString gamePhase);
    QString monsterAttack(int characterid);
    QString monsterSpecialAttack(int effectlvl,int characterid);

    QString lootAfterBattle();
    QString gainXpRoll();
    void healCharacter(int itemindex, int characterid1, int characterid2, int lifeAmount);
    void blessCharacter(int itemindex,int characterid1,int characterid2);

    int getObjectKey(QString object);
    int getItemKey(QString str);
    int isCharacterEquip(QString item, int characterid);
    int isAllFled();
    int monsterAttackFirst();
    int monsterRegenerate();
    int monsterBreathFire();

    int intrand(int min, int max);
    int min(int a,int b);
    int max(int a,int b);

    void addItem(QString item, int characterid);
    int removeDeadCharacters();
    int isallDeadCharacters();
private:
    QString randomName();
    int getMonsterKey(QString str);
    void removeItem(int itemindex,int characterid);
    void addStatus(QString status,int characterid);
    void removeStatus(QString status,int characterid);
    int isCharacterStatus(QString status, int characterid);
    int isCharacterTrait(QString trait,int characterid);
    int isUsableEquipment(QString equipment,int characterid);

    void drawRoom(int findx,int findy, int beginx,int beginy,int randomroom,int opendoor);
    void createEvent(QString event);
    void trapDefense(QString trap, int trapLevel, int damage,int characterid);
    QString trapDisarm(int trapLevel);
    QString puzzleSolving(int characterid);
    QString spellCasting(QString type, int itemindex, int characterid);
    QString stealGold();

    void createBattleMonster(QString monster, QString type);
    QString spellEvent();
    QString magicTreasureEvent();
    QString treasureEvent(int modifier);
    QString trapEvent();
    QString fountainEvent();
    QString holyRelicEvent();
    QString cursedAltarEvent();
    QString armoryEvent();
    QString statueEvent();


};

#endif // DATA_H
