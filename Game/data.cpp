#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include <windows.h>
#include <string.h>
#include <fcntl.h>
#include <io.h>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QIODevice>

Data::Data()
{
    QFile file(":/res/data/Entrances.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<< "wrong";
    };
    QTextStream in(&file);
    while (!in.atEnd())
    {
        in >> E.size;
        int s;
        for (s=0;s<E.size;s++)
        {
            in >> E.Entr[s].width >> E.Entr[s].length >> E.Entr[s].Corridors >>E.Entr[s].Doors;
            int i,j;
            for (j=0;j<E.Entr[s].Corridors;j++)
            {
               in >> E.Entr[s].Cs[j].x >> E.Entr[s].Cs[j].y;
            }
            for (j=0;j<E.Entr[s].Doors;j++)
            {
                in >> E.Entr[s].Ds[j].x >> E.Entr[s].Ds[j].y;
            }
            for (i=0;i<E.Entr[s].width;i++)
            {
                for (j=0;j<E.Entr[s].length;j++)
                {
                    in >> E.Entr[s].S[i][j];
                }
            }
        }
    };
    file.close();


    QFile file1(":/res/data/Rooms.txt");
    if(!file1.open(QIODevice::ReadOnly))
    {
        qDebug()<< "wrong";
    };
    QTextStream in1(&file1);
    while (!in1.atEnd())
    {
        in1 >> R.size;
        int s;
        for (s=0;s<R.size;s++)
        {
            in1 >> R.Ro[s].width >> R.Ro[s].length >> R.Ro[s].Corridors >> R.Ro[s].Doors;
            int i,j;
            for (j=0;j<R.Ro[s].Corridors;j++)
            {
                in1 >> R.Ro[s].Cs[j].x >> R.Ro[s].Cs[j].y;
            }
            for (j=0;j<R.Ro[s].Doors;j++)
            {
                in1 >> R.Ro[s].Ds[j].x >> R.Ro[s].Ds[j].y;
            }
            for (i=0;i<R.Ro[s].width;i++)
            {
                for (j=0;j<R.Ro[s].length;j++)
                {
                    in1 >> R.Ro[s].S[i][j];
                }
            }
        };
    };
    file1.close();

    QFile file2(":/res/data/Objects.txt");
    if(!file2.open(QIODevice::ReadOnly))
    {
        qDebug()<< "wrong";
    };
    QTextStream in2(&file2);
    while (!in2.atEnd())
    {
        in2 >> O.size;
        int i;
        for (i=0;i<O.size;i++)
        {
            in2 >> O.Obj[i].name >> O.Obj[i].isPass >> O.Obj[i].isInteractive;
            O.Obj[i].name= O.Obj[i].name.replace("_"," ");
        };
    };
    file2.close();


    QFile file3(":/res/data/RoomContents.txt");
    if(!file3.open(QIODevice::ReadOnly))
    {
        qDebug()<< "wrong";
    };
    QTextStream in3(&file3);
    while (!in3.atEnd())
    {
        in3 >> RC.size;
        int i;
        for (i=0;i<RC.size;i++)
        {
            in3 >> RC.RmCont[i].CorridorResult;
            in3 >> RC.RmCont[i].DoorResult;
        };
    };
    file3.close();


    QFile file4(":/res/data/Classes.txt");
    if(!file4.open(QIODevice::ReadOnly))
    {
        qDebug()<< "wrong";
    };
    QTextStream in4(&file4);
    while (!in4.atEnd())
    {
        in4 >> Clsses.size;
        int i;
        for (i=0;i<Clsses.size;i++)
        {
            int j;
            in4 >> Clsses.Clss[i].ClassName;
            in4 >> Clsses.Clss[i].BaseLife >> Clsses.Clss[i].MaxLevel >> Clsses.Clss[i].GoldDice;

            in4 >> Clsses.Clss[i].numberofUsableEquipments;
            for (j=0;j<Clsses.Clss[i].numberofUsableEquipments;j++)
            {
                in4 >> Clsses.Clss[i].UsableEquipments[j];
                Clsses.Clss[i].UsableEquipments[j]=Clsses.Clss[i].UsableEquipments[j].replace("_"," ");
            };

            in4 >> Clsses.Clss[i].numberofTraits;
            for (j=0;j<Clsses.Clss[i].numberofTraits;j++)
            {
                in4 >> Clsses.Clss[i].Traits[j];
                Clsses.Clss[i].Traits[j]=Clsses.Clss[i].Traits[j].replace("_"," ");
            };
            in4 >> Clsses.Clss[i].numberofClassBuilds;
            for (j=0;j<Clsses.Clss[i].numberofClassBuilds;j++)
            {
                in4 >> Clsses.Clss[i].ClssBuilds[j].MainHand;
                Clsses.Clss[i].ClssBuilds[j].MainHand=Clsses.Clss[i].ClssBuilds[j].MainHand.replace("_"," ");

                in4 >> Clsses.Clss[i].ClssBuilds[j].OffHand;
                Clsses.Clss[i].ClssBuilds[j].OffHand=Clsses.Clss[i].ClssBuilds[j].OffHand.replace("_"," ");

                in4 >> Clsses.Clss[i].ClssBuilds[j].Armor;
                Clsses.Clss[i].ClssBuilds[j].Armor=Clsses.Clss[i].ClssBuilds[j].Armor.replace("_"," ");

            };
        };
    };
    file4.close();


    QFile file5(":/res/data/Items.txt");
    if(!file5.open(QIODevice::ReadOnly))
    {
        qDebug()<< "wrong";
    };
    QTextStream in5(&file5);
    while (!in5.atEnd())
    {
        in5 >> Itms.size;
        int i;
        for (i=0;i<Itms.size;i++)
        {
            in5 >> Itms.Itm[i].Name;
            Itms.Itm[i].Name = Itms.Itm[i].Name.replace("_"," ");
            in5 >> Itms.Itm[i].Value >> Itms.Itm[i].Charges;

            in5 >> Itms.Itm[i].description;
            Itms.Itm[i].description=Itms.Itm[i].description.replace("_"," ");
        };
    };
    file5.close();


    QFile file6(":/res/data/Names.txt");
    if(!file6.open(QIODevice::ReadOnly))
    {
        qDebug()<< "wrong";
    };
    QTextStream in6(&file6);
    while (!in6.atEnd())
    {
        in6 >> Nms.size;
        int i;
        for (i=0;i<Nms.size;i++)
        {
            in6 >> Nms.name[i];
        };
    };
    file6.close();


    QFile file7(":/res/data/Monsters.txt");
    if(!file7.open(QIODevice::ReadOnly))
    {
        qDebug()<< "wrong";
    };
    QTextStream in7(&file7);
    while (!in7.atEnd())
    {
        in7 >> Mns.verminSize >> Mns.minionSize >> Mns.weirdMonsterSize >> Mns.bossSize >> Mns.specialMonsterSize;
        int i;
        for (i=0;i<Mns.verminSize;i++)
        {
            in7 >> Mns.vermins[i].name;
            Mns.vermins[i].name = Mns.vermins[i].name.replace("_"," ");

            in7 >> Mns.vermins[i].amountDice >> Mns.vermins[i].amountModifier;
            in7 >> Mns.vermins[i].level >> Mns.vermins[i].treasureAmount >> Mns.vermins[i].treasureModifier;
            in7 >> Mns.vermins[i].weakness;
            in7 >> Mns.vermins[i].ability;
            Mns.vermins[i].ability = Mns.vermins[i].ability.replace("_"," ");

            int j;
            for (j=0;j<6;j++)
            {
                in7 >> Mns.vermins[j].reactions[j];
            };
        };
        for (i=0;i<Mns.minionSize;i++)
        {
            in7 >> Mns.minions[i].name;
            Mns.minions[i].name = Mns.minions[i].name.replace("_"," ");

            in7 >> Mns.minions[i].amountDice >> Mns.minions[i].amountModifier;
            in7 >> Mns.minions[i].level >> Mns.minions[i].treasureAmount >> Mns.minions[i].treasureModifier;
            in7 >> Mns.minions[i].weakness;
            in7 >> Mns.minions[i].ability;
            Mns.minions[i].ability = Mns.minions[i].ability.replace("_"," ");

            int j;
            for (j=0;j<6;j++)
            {
                in7 >> Mns.minions[j].reactions[j];
            };
        };
        for (i=0;i<Mns.weirdMonsterSize;i++)
        {
            in7 >> Mns.weirdMonsters[i].name;
            Mns.weirdMonsters[i].name = Mns.weirdMonsters[i].name.replace("_"," ");

            in7 >> Mns.weirdMonsters[i].amountDice >> Mns.weirdMonsters[i].amountModifier;
            in7 >> Mns.weirdMonsters[i].level >> Mns.weirdMonsters[i].treasureAmount >> Mns.weirdMonsters[i].treasureModifier;
            in7 >> Mns.weirdMonsters[i].weakness;
            in7 >> Mns.weirdMonsters[i].ability;
            Mns.weirdMonsters[i].ability = Mns.weirdMonsters[i].ability.replace("_"," ");

            int j;
            for (j=0;j<6;j++)
            {
                in7 >> Mns.weirdMonsters[j].reactions[j];
            };
        };
        for (i=0;i<Mns.bossSize;i++)
        {
            in7 >> Mns.bosses[i].name;
            Mns.bosses[i].name = Mns.bosses[i].name.replace("_"," ");

            in7 >> Mns.bosses[i].amountDice >> Mns.bosses[i].amountModifier;
            in7 >> Mns.bosses[i].level >> Mns.bosses[i].treasureAmount >> Mns.bosses[i].treasureModifier;
            in7 >> Mns.bosses[i].weakness;
            in7 >> Mns.bosses[i].ability;
            Mns.bosses[i].ability = Mns.bosses[i].ability.replace("_"," ");

            int j;
            for (j=0;j<6;j++)
            {
                in7 >> Mns.bosses[j].reactions[j];
            };
        };
        for (i=0;i<Mns.specialMonsterSize;i++)
        {
            in7 >> Mns.specialMonsters[i].name;
            Mns.specialMonsters[i].name = Mns.specialMonsters[i].name.replace("_"," ");

            in7 >> Mns.specialMonsters[i].amountDice >> Mns.specialMonsters[i].amountModifier;
            in7 >> Mns.specialMonsters[i].level >> Mns.specialMonsters[i].treasureAmount >> Mns.specialMonsters[i].treasureModifier;
            in7 >> Mns.specialMonsters[i].weakness;
            in7 >> Mns.specialMonsters[i].ability;
            Mns.specialMonsters[i].ability = Mns.specialMonsters[i].ability.replace("_"," ");

            int j;
            for (j=0;j<6;j++)
            {
                in7 >> Mns.specialMonsters[j].reactions[j];
            };
        };
    }
    file7.close();

    M.width=32;//20
    M.length=32;//28
    M.room_counter=0;
    M.EventTile.x=-1;
    M.EventTile.y=-1;
    M.EventTileKey=-1;
    M.screen_size=7;
    M.PL.x=M.width-1;
    M.PL.y=(M.length/2)-1;

    int i,j;
    P.totalGold=0;
    P.xpRolls=0;
    P.monstersKilled=0;
    P.partysize=4;
    for (i=0;i<4;i++)
    {
        P.Chars[i].Name="";
        P.Chars[i].ClassId=-1;
        P.Chars[i].Life=-1;
        P.Chars[i].Level=-1;
        P.Chars[i].Clues=-1;
        P.Chars[i].isFlee=0;
        P.Chars[i].MainHand="";
        P.Chars[i].OffHand="";
        P.Chars[i].Armor="";
        P.Chars[i].ItemsSize=0;
        for (j=0;j<50;j++)
        {
            P.Chars[i].Items[j]="";
        };
        P.Chars[i].StatusSize=0;
        for (j=0;j<20;j++)
        {
            P.Chars[i].Status[j]="";
        }
    };
    hasEvent=0;
}

void Data::createCharacter(int characterid, int classid, int classbuildid)
{
    P.Chars[characterid].Name=randomName();
    P.Chars[characterid].ClassId=classid;
    P.Chars[characterid].Life=Clsses.Clss[classid].BaseLife+1;
    P.Chars[characterid].Level=1;
    P.Chars[characterid].Clues=0;
    P.Chars[characterid].ItemsSize=0;

    P.Chars[characterid].MainHand=Clsses.Clss[classid].ClssBuilds[classbuildid].MainHand;
    P.Chars[characterid].OffHand=Clsses.Clss[classid].ClssBuilds[classbuildid].OffHand;
    P.Chars[characterid].Armor=Clsses.Clss[classid].ClssBuilds[classbuildid].Armor;

    int gold=0;
    int i;
    for (i=0;i<Clsses.Clss[classid].GoldDice;i++)
    {
        gold+=intrand(1,6);
    };
    P.totalGold+=gold;

    for (i=0;i<Clsses.Clss[classid].numberofTraits;i++)
    {
        if (getItemKey(Clsses.Clss[classid].Traits[i])!=-1)
        {
            addItem(Clsses.Clss[classid].Traits[i],characterid);
        };
    };

    if (Clsses.Clss[classid].ClassName=="Elf") addItem(spellEvent(),characterid);
    if (Clsses.Clss[classid].ClassName=="Wizard")
    {
        for (i=0;i<3;i++)
        {
            addItem(spellEvent(),characterid);
        };
    };
    addItem("Bandage",characterid);
}

void Data::createEntrance()
{
    int num = intrand(0,E.size-1);
    int startx=M.PL.x-(E.Entr[num].width-1);
    int starty=M.PL.y-(E.Entr[num].length-1)/2;
    M.room_counter++;
    int i,j;
    for (i=startx;i<startx+E.Entr[num].width;i++)
    {
        for (j=starty;j<starty+E.Entr[num].length;j++)
        {
            if (E.Entr[num].S[i-startx][j-starty] == getObjectKey("Void"))
                M.Open[i][j] = -1;
            else M.Open[i][j] = M.room_counter;

            M.Map[i][j] = E.Entr[num].S[i-startx][j-starty];
        }
    }
    M.room_counter++;
}

int Data::buyItem(int characterid, QString item)
{
    int itemkey = getItemKey(item);
    if (P.totalGold >= Itms.Itm[itemkey].Value)
    {
        P.totalGold-=Itms.Itm[itemkey].Value;
        addItem(item,characterid);
        return 1;
    }
    else
    {
        return 0;
    };
}

void Data::swapCharacter(int characterid1, int characterid2)
{
    Character temp=P.Chars[characterid1];
    P.Chars[characterid1]=P.Chars[characterid2];
    P.Chars[characterid2]=temp;
}

void Data::transferItem(int itemindex, int characterid1, int characterid2)
{
    QString item=P.Chars[characterid1].Items[itemindex];
    removeItem(itemindex,characterid1);
    addItem(item,characterid2);
}

void Data::drawRoom(int findx,int findy, int beginx,int beginy,int randomroom,int opendoor)
{
    if (findx<0 || findx>=R.Ro[randomroom].width || findy<0 || findy>=R.Ro[randomroom].length) return;
    if (beginx+findx<0 || +beginx+findx>=M.width || beginy+findy<0 || beginy+findy>=M.length) return;
    if (M.Open[beginx+findx][beginy+findy] != 0 && opendoor == 0) return;
    if (R.Ro[randomroom].S[findx][findy] == getObjectKey("Void")) return;

    if (beginx+findx != M.PL.x && beginy+findy != M.PL.y)
    {
        int fourSideIsVoid = 0;
        if (M.Open[beginx+findx-1][beginy+findy] <=0|| beginx+findx-1<0 || beginx+findx-1>=M.width
            || beginy+findy<0 || beginy+findy>=M.length ) fourSideIsVoid++;

        if (M.Open[beginx+findx][beginy+findy-1] <=0|| beginx+findx<0 || beginx+findx>=M.width
            || beginy+findy-1<0 || beginy+findy-1>=M.length ) fourSideIsVoid++;

        if (M.Open[beginx+findx][beginy+findy+1] <=0|| beginx+findx<0 || beginx+findx>=M.width
            || beginy+findy+1<0 || beginy+findy+1>=M.length ) fourSideIsVoid++;

        if (M.Open[beginx+findx+1][beginy+findy] <=0 || beginx+findx+1<0 || beginx+findx+1>=M.width
            || beginy+findy<0 || beginy+findy>=M.length ) fourSideIsVoid++;

        if (fourSideIsVoid==4) return;

        if (M.Open[beginx+findx-1][beginy+findy] != M.room_counter && M.Open[beginx+findx-1][beginy+findy]>0) return;
        if (M.Open[beginx+findx][beginy+findy-1] != M.room_counter && M.Open[beginx+findx][beginy+findy-1]>0) return;
        if (M.Open[beginx+findx][beginy+findy+1] != M.room_counter && M.Open[beginx+findx][beginy+findy+1]>0) return;
        if (M.Open[beginx+findx+1][beginy+findy] != M.room_counter && M.Open[beginx+findx+1][beginy+findy]>0) return;


    };
    if (beginx+findx == M.PL.x && beginy+findy == M.PL.y) M.Map[beginx+findx][beginy+findy]=getObjectKey("Floor");
    else if (beginx+findx == M.EventTile.x && beginy+findy == M.EventTile.y)
    {
        hasEvent=1;
        M.Map[beginx+findx][beginy+findy]=M.EventTileKey;
    }
    else M.Map[beginx+findx][beginy+findy]=R.Ro[randomroom].S[findx][findy];


    M.Open[beginx+findx][beginy+findy] = M.room_counter;


    drawRoom(findx-1,findy-1,beginx,beginy,randomroom,0);
    drawRoom(findx-1,findy,beginx,beginy,randomroom,0);
    drawRoom(findx-1,findy+1,beginx,beginy,randomroom,0);
    drawRoom(findx,findy-1,beginx,beginy,randomroom,0);
    drawRoom(findx,findy+1,beginx,beginy,randomroom,0);
    drawRoom(findx+1,findy-1,beginx,beginy,randomroom,0);
    drawRoom(findx+1,findy,beginx,beginy,randomroom,0);
    drawRoom(findx+1,findy+1,beginx,beginy,randomroom,0);
}

void Data::createEvent(QString event)
{
    if (event=="Treasure")
    {
        M.EventTileKey=getObjectKey("Treasure");
    }
    else if (event=="Trap")
    {
        M.EventTileKey=getObjectKey("Trap Treasure");
    }
    else if (event=="SpecialEvent")
    {
        int rand = intrand(1,6);
        if (rand == 1)
        {
            M.EventTileKey=getObjectKey("Terrifiyng Ghost");
        }
        else M.EventTileKey=getObjectKey("Floor");
    }
    else if (event=="SpecialFeature")
    {
        int rand = intrand(1,6);
        if (rand == 1)
        {
            M.EventTileKey=getObjectKey("Fountain");
        }
        else if (rand == 2)
        {
            M.EventTileKey=getObjectKey("Holy Relic");
        }
        else if (rand == 3)
        {
            M.EventTileKey=getObjectKey("Armory");
        }
        else if (rand == 4)
        {
            M.EventTileKey=getObjectKey("Cursed Altar");
        }
        else if (rand == 5)
        {
            M.EventTileKey=getObjectKey("Statue");
        }
        else
        {
            M.EventTileKey=getObjectKey("Puzzle");
        };
    }
    else if (event=="Vermin")
    {
        int rand = intrand(1,6);
        if (rand == 1)
        {
            M.EventTileKey=getObjectKey("Scorpions");
        }
        else if (rand == 2)
        {
            M.EventTileKey=getObjectKey("Vampire Bats");
        }
        else if (rand == 3)
        {
            M.EventTileKey=getObjectKey("Goblin Swarmlings");
        }
        else if (rand == 4)
        {
            M.EventTileKey=getObjectKey("Giant Centipedes");
        }
        else if (rand == 5)
        {
            M.EventTileKey=getObjectKey("Vampire Frogs");
        }
        else
        {
            M.EventTileKey=getObjectKey("Ghouls");
        };
    }
    else if (event=="Minion")
    {
        int rand = intrand(1,6);
        if (rand == 1)
        {
            int rand1= intrand(1,2);
            if (rand1==1) M.EventTileKey=getObjectKey("Skeletons");
            else M.EventTileKey=getObjectKey("Zombies");
        }
        else if (rand == 2)
        {
            M.EventTileKey=getObjectKey("Goblins");
        }
        else if (rand == 3)
        {
            M.EventTileKey=getObjectKey("Hobgoblins");
        }
        else if (rand == 4)
        {
            M.EventTileKey=getObjectKey("Orcs");
        }
        else if (rand == 5)
        {
            M.EventTileKey=getObjectKey("Trolls");
        }
        else
        {
            M.EventTileKey=getObjectKey("Fungi Folk");
        };
    }
    else if (event=="WeirdMonster")
    {
        int rand = intrand(1,5);
        if (rand == 1)
        {
            M.EventTileKey=getObjectKey("Minotaur");
        }
        else if (rand == 2)
        {
            M.EventTileKey=getObjectKey("Iron Eater");
        }
        else if (rand == 3)
        {
            M.EventTileKey=getObjectKey("Chimera");
        }
        else if (rand == 4)
        {
            M.EventTileKey=getObjectKey("Catoblepas");
        }
        else if (rand == 5)
        {
            M.EventTileKey=getObjectKey("Insect King");
        }
    }
    else M.EventTileKey=getObjectKey("Floor");
}

void Data::trapDefense(QString trap, int trapLevel, int damage, int characterid)
{
    int rand=intrand(1,6);
    int modifier = 0;

    // update modifier
    if (trap=="Dart" || trap=="Spears")
    {
        if (isCharacterEquip("Heavy Armor",characterid)) modifier+=2;
        if (isCharacterEquip("Light Armor",characterid)) modifier+=1;
        if (isCharacterEquip("Shield",characterid)) modifier+=1;
    }
    else if (trap=="Trapdoor")
    {
        if (isCharacterTrait("Def + lvl",characterid)) modifier+=P.Chars[characterid].Level;
        if (Clsses.Clss[ P.Chars[characterid].ClassId ].ClassName=="Elf") modifier+=1;
        if (isCharacterEquip("Heavy Armor",characterid)) modifier-=2;
        if (isCharacterEquip("Light Armor",characterid)) modifier-=1;
        if (isCharacterStatus("Limping",characterid)) modifier-=2;
    }
    else if (trap=="Bear Trap")
    {
        if (isCharacterTrait("Def + lvl",characterid)) modifier+=P.Chars[characterid].Level;
        if (Clsses.Clss[ P.Chars[characterid].ClassId ].ClassName=="Elf") modifier+=1;
        if (isCharacterStatus("Limping",characterid)) modifier-=2;
    }
    else if (trap=="Giant Stone")
    {
        if (isCharacterEquip("Heavy Armor",characterid)) modifier+=2;
        if (isCharacterEquip("Light Armor",characterid)) modifier+=1;
    };

    // check auto successful
    if (rand==6) return;//successful

    // check auto fail and normal fail
    if (rand==1 || rand+modifier<=trapLevel)
    {
        P.Chars[characterid].Life-=damage;

        if (trap=="Bear Trap")
        {
            addStatus("Limping",characterid);
        };
        if (trap=="Trapdoor" && P.partysize==1)
        {
            P.Chars[characterid].Life=0;
        }
    };
}

QString Data::trapDisarm(int trapLevel)
{
    if (Clsses.Clss[P.Chars[0].ClassId].ClassName=="Rogue")
    {
        int rand=intrand(1,6);
        if (isCharacterTrait("Disarm Traps + lvl",0)) rand+=P.Chars[0].Level;
        if (rand==1) return "miss";
        if (rand==6 || rand>=trapLevel) return "hit";
        return "miss";
    }
    return "miss";
}

QString Data::puzzleSolving(int characterid)
{
    int rand=intrand(1,6);
    int modifier=0;

    if (isCharacterTrait("Disarm Traps + lvl",characterid)) modifier+=P.Chars[characterid].Level;
    if (isCharacterTrait("Solve + lvl",characterid)) modifier+=P.Chars[characterid].Level;

    int level=intrand(1,6);

    if (rand==6) return "success";
    if (rand==1 || rand+modifier<level)
    {
        P.Chars[characterid].Life-=1;
        removeDeadCharacters();
        return "fail";
    };
    return "success";
}

QString Data::spellCasting(QString type, int itemindex, int characterid)
{
    if (!isCharacterTrait("Atk + lvl with spells",characterid))
    {
        return "THIS CHARACTER CAN'T CAST THIS SPELL.\n";
    };
    if (isCharacterTrait("cannot cast whenShieldorHeavyArmor",characterid) &&
            (isCharacterEquip("Heavy Armor",characterid) || isCharacterEquip("Shield",characterid)))
    {
        return "THIS CHARACTER CAN'T CAST SPELLS WHEN USING SHIELD OR HEAVY ARMOR.\n";
    };

    P.Chars[characterid].ItemCharges[itemindex]-=1;
    if (P.Chars[characterid].ItemCharges[itemindex]==0) removeItem(itemindex,characterid);

    if (battleMonster.name=="Statue" && type!="escaping") return "miss";


    int rand=intrand(1,6);
    int modifier=P.Chars[characterid].Level;
    if (battleMonster.name=="Vampire Bats") modifier-=1;
    if (battleMonster.name=="Orcs") modifier+=1;

    if (rand==1) return "miss";

    if (rand==6 || rand+modifier>=battleMonster.level)
    {
        if (type=="fireball")
        {
            battleMonster.amount-=max(1,rand+modifier-battleMonster.level);
        };
        if (type=="lightning")
        {
            if (battleMonster.amountDice<0) battleMonster.amount-=2;
            else battleMonster.amount-=1;
        };
        if (type=="sleeping")
        {
            if (battleMonster.name=="Ghouls (Undead)"
                    || battleMonster.name=="Skeletons (Undead)"
                    || battleMonster.name=="Zombies (Undead)") return "miss";

            if (battleMonster.amountDice<0) battleMonster.amount=0;
            else battleMonster.amount-=max(1,rand+modifier);
        };
        if (type=="protecting")
        {
            int i;
            for (i=0;i<P.partysize;i++)
            {
                addStatus("Protected",i);
            };
        };
        if (type=="escaping")
        {
            P.Chars[characterid].isFlee=1;
        };
        return "hit";
    };
    return "miss";
}

QString Data::stealGold()
{
    int i;
    int flag=0;
    for (i=0;i<P.partysize;i++)
    {
        if (Clsses.Clss[P.Chars[i].ClassId].ClassName=="Dwarf")
        {
            P.totalGold-=max(P.totalGold*(1/12),1);
            flag=1;
        };
    };
    if (flag==1) return "\nBut each mercenary stole some golds.";
    else return "";
}



QString Data::characterAttack(int characterid)
{
    int rand=intrand(1,6);
    int modifier = 0;

    if (isCharacterEquip("Bare Hand",characterid)) modifier-=2;
    if (isCharacterEquip("Light Weapon",characterid)) modifier-=1;
    if (isCharacterEquip("Crushing Two-handed Weapon",characterid) || isCharacterEquip("Slashing Two-handed Weapon",characterid)) modifier+=1;
    if (isCharacterEquip("Poison Slashing Hand Weapon",characterid)) modifier+=1;
    if (isCharacterEquip("Poison Slashing Two-handed Weapon",characterid)) modifier+=2;
    if (isCharacterEquip("Magic Weapon",characterid)) modifier+=3;

    if ((isCharacterEquip("Crushing Two-handed Weapon",characterid) || isCharacterEquip("Crushing Hand Weapon",characterid)) &&
            battleMonster.weakness=="Crushing") modifier+=1;

    if ((isCharacterEquip("Slashing Two-handed Weapon",characterid) || isCharacterEquip("Slashing Hand Weapon",characterid)) &&
            battleMonster.weakness=="Slashing") modifier+=1;


    if (isCharacterTrait("Atk + lvl",characterid) || isCharacterTrait("Atk + lvl except Range",characterid)) modifier+=P.Chars[characterid].Level;
    if (isCharacterTrait("Atk + half-lvl",characterid)) modifier+=int(P.Chars[characterid].Level/2);
    if (isCharacterTrait("Atk + lvl if fighting Outnumbered Enemy",characterid) && P.partysize > battleMonster.amount) modifier+=P.Chars[characterid].Level;
    if (isCharacterTrait("Atk + lvl vs. Undead",characterid) && (battleMonster.name=="Ghouls (Undead)"
                                                                || battleMonster.name=="Skeletons (Undead)"
                                                                || battleMonster.name=="Zombies (Undead)")) modifier+=P.Chars[characterid].Level;

    if (isCharacterTrait("Atk + lvl vs. Goblin",characterid) && (battleMonster.name=="Goblin Swarmlings"
                                                                 || battleMonster.name=="Goblins"
                                                                 || battleMonster.name=="Hobgoblins")) modifier+=1;
    if (isCharacterTrait("Atk +1 vs. Orc",characterid) && battleMonster.name=="Orcs" ) modifier+=1;

    if (isCharacterStatus("Holy-Blessed",characterid)) modifier+=1;

    if (rand==1) return "miss";
    if (rand==6 || rand+modifier>=battleMonster.level)
    {
        if (battleMonster.amountDice<0)
        {
            if (Clsses.Clss[ P.Chars[characterid].ClassId ].ClassName == "Barbarian") battleMonster.amount-=2;
            else battleMonster.amount-=1;
        }
        else battleMonster.amount-=int((rand+modifier)/battleMonster.level);
        return "hit";
    };
    return "miss";
}

QString Data::characterShot(int characterid)
{
    int rand=intrand(1,6);
    int modifier = 0;

    if (isCharacterEquip("Bow",characterid)) modifier+=1;
    if (isCharacterEquip("Bow",characterid) && battleMonster.weakness=="Slashing" ) modifier+=1;
    if (isCharacterEquip("Sling",characterid) && battleMonster.weakness=="Crushing" ) modifier+=1;

    if (isCharacterTrait("Atk + lvl",characterid)) modifier+=P.Chars[characterid].Level;
    if (isCharacterTrait("Atk + half-lvl",characterid)) modifier+=int(P.Chars[characterid].Level/2);
    if (isCharacterTrait("Atk + lvl if fighting Outnumbered Enemy",characterid) && P.partysize > battleMonster.amount) modifier+=P.Chars[characterid].Level;
    if (isCharacterTrait("Atk + lvl vs. Undead",characterid) && (battleMonster.name=="Ghouls (Undead)"
                                                                || battleMonster.name=="Skeletons (Undead)"
                                                                || battleMonster.name=="Zombies (Undead)")) modifier+=P.Chars[characterid].Level;
    if (isCharacterTrait("Atk + lvl vs. Goblin",characterid) && (battleMonster.name=="Goblin Swarmlings"
                                                                 || battleMonster.name=="Goblins"
                                                                 || battleMonster.name=="Hobgoblins")) modifier+=1;
    if (isCharacterTrait("Atk +1 vs. Orc",characterid) && battleMonster.name=="Orcs" ) modifier+=1;

    if (isCharacterStatus("Holy-Blessed",characterid)) modifier+=1;

    if (rand==1) return "miss";
    if (rand==6 || rand+modifier>=battleMonster.level)
    {
        battleMonster.amount-=1;
        return "hit";
    };
    return "miss";

}

QString Data::characterFlee(int characterid)
{
    if (battleMonster.name=="Insect King") return "THE CHARACTER HAS FAIL TO ESCAPED.";
    int rand=intrand(1,6);
    if (rand > battleMonster.level || rand==6)
    {
        P.Chars[characterid].isFlee=1;
        return "THE CHARACTER HAS ESCAPED SUCCESSFULLY.";
    };
    return "THE CHARACTER HAS FAIL TO ESCAPED.";
}

QString Data::characterLevelUp(int characterid)
{
    if (P.xpRolls==0) return "YOU DON'T HAVE ANY XP ROLL.\n   CANNOT LEVEL UP.\n";
    if (P.Chars[characterid].Level == Clsses.Clss[P.Chars[characterid].ClassId].MaxLevel)
    {
        return "ALREADY AT MAX LEVEL.\nCANNOT LEVEL UP ANYMORE.\n";
    };

    P.xpRolls-=1;
    int rand=intrand(1,6);
    if (rand > P.Chars[characterid].Level)
    {
        P.Chars[characterid].Level+=1;
        P.Chars[characterid].Life = Clsses.Clss[P.Chars[characterid].ClassId].BaseLife+P.Chars[characterid].Level;
        int classid=P.Chars[characterid].ClassId;
        if (Clsses.Clss[classid].ClassName=="Elf" || Clsses.Clss[classid].ClassName=="Wizard") addItem(spellEvent(),characterid);
        return "SUCCESSED TO LEVEL UP THE CHARACTER.";
    };
    return "FAILED TO LEVEL UP THE CHARACTER.";
}

QString Data::characterUseItem(int itemindex, int characterid, QString gamePhase)
{
    int itemkey=getItemKey(P.Chars[characterid].Items[itemindex]);

    // Equipment
    if (P.Chars[characterid].ItemCharges[itemindex]==-1)
    {
        if (Itms.Itm[itemkey].Name=="Magic Weapon" && isCharacterTrait("Cannot use magicItem",characterid) )
        {
            return "THE CHARACTER CANNOT EQUIP THIS ITEM.";
        }
        else if (Itms.Itm[itemkey].Name!="Magic Weapon" && isUsableEquipment(Itms.Itm[itemkey].Name,characterid)==0)
        {
            return "THE CHARACTER CANNOT EQUIP THIS ITEM.";
        }
        else if(Itms.Itm[itemkey].Name=="Shield" || Itms.Itm[itemkey].Name=="Sling" || Itms.Itm[itemkey].Name=="Bow")
        {
            if (P.Chars[characterid].MainHand=="Crushing Two-handed Weapon" || P.Chars[characterid].MainHand=="Slashing Two-handed Weapon" ||
                    P.Chars[characterid].MainHand=="Poison lashing Two-handed Weapon")
            {
                addItem(P.Chars[characterid].MainHand,characterid);
                P.Chars[characterid].MainHand="Bare Hand";
            };
            if (P.Chars[characterid].OffHand!="None")
            {
                addItem(P.Chars[characterid].OffHand,characterid);
            };
            P.Chars[characterid].OffHand=Itms.Itm[itemkey].Name;
            removeItem(itemindex,characterid);
            return "HAS EQUIPPED THIS ITEM TO OFF HAND SLOT.\n";
        }
        else if (Itms.Itm[itemkey].Name=="Light Armor" || Itms.Itm[itemkey].Name=="Heavy Armor")
        {
            if (P.Chars[characterid].Armor!="None")
            {
                addItem(P.Chars[characterid].Armor,characterid);
            };
            P.Chars[characterid].Armor=Itms.Itm[itemkey].Name;
            removeItem(itemindex,characterid);
            return "HAS EQUIPPED THIS ITEM TO ARMOR SLOT.\n";
        }
        else if (Itms.Itm[itemkey].Name=="Crushing Two-handed Weapon" || Itms.Itm[itemkey].Name=="Slashing Two-handed Weapon"
                 || Itms.Itm[itemkey].Name=="Poison lashing Two-handed Weapon")
        {
            if (P.Chars[characterid].OffHand!="None")
            {
                addItem(P.Chars[characterid].OffHand,characterid);
                P.Chars[characterid].OffHand="None";
            };
            if (P.Chars[characterid].MainHand!="None")
            {
                addItem(P.Chars[characterid].MainHand,characterid);
                P.Chars[characterid].MainHand="Bare Hand";
            };
            P.Chars[characterid].MainHand=Itms.Itm[itemkey].Name;
            removeItem(itemindex,characterid);
            return "HAS EQUIPPED THIS ITEM TO MAIN HAND SLOT.\n";
        }
        else
        {
            if (P.Chars[characterid].MainHand!="None")
            {
                addItem(P.Chars[characterid].MainHand,characterid);
                P.Chars[characterid].MainHand="Bare Hand";
            };
            P.Chars[characterid].MainHand=Itms.Itm[itemkey].Name;
            removeItem(itemindex,characterid);
            return "HAS EQUIPPED THIS ITEM TO MAIN HAND SLOT.\n";
        };
    }
    // Usable Item
    else
    {
        if (Itms.Itm[itemkey].Name=="Potion of Healing")
        {
            if (Itms.Itm[itemkey].Name=="Potion of Healing" && isCharacterTrait("Cannot use magicItem",characterid) )
            {
                return "THIS CHARACTER CAN'T USE THIS ITEM.\n";
            };
            healCharacter(itemindex,characterid,characterid,2);
            return "THE CHARACTER IS HEALED.\n";

        };
        if (Itms.Itm[itemkey].Name=="Bandage")
        {
            healCharacter(itemindex,characterid,characterid,1);
            return "THE CHARACTER IS HEALED.\n";
        };

        if (gamePhase=="UseItemInBattle")
        {
           if (Itms.Itm[itemkey].Name=="Holy Water Vial")
           {
               removeItem(itemindex,characterid);
               if (battleMonster.name=="Ghouls (Undead)" || battleMonster.name=="Vampire Frogs"
                       || battleMonster.name=="Vampire Bats" || battleMonster.name=="Skeletons (Undead)"
                       || battleMonster.name=="Zombies (Undead)")
               {
                    battleMonster.amount-=3;
                    return "hit";
               }
               else return "miss";
           };
           if (Itms.Itm[itemkey].Name=="Ring of Teleportation")
           {
               P.Chars[characterid].isFlee=1;
               removeItem(itemindex,characterid);
               return "THE CHARACTER IS ESCAPED.\n";
           };
           if (Itms.Itm[itemkey].Name=="Fireball Staff" || Itms.Itm[itemkey].Name=="Fireball Spell")
           {
               return spellCasting("fireball",itemindex,characterid);
           };
           if (Itms.Itm[itemkey].Name=="Lightning Bolt Spell")
           {
               return spellCasting("lightning",itemindex,characterid);
           }
           if (Itms.Itm[itemkey].Name=="Sleeping Spell" || Itms.Itm[itemkey].Name=="Wand of Sleep")
           {
               return spellCasting("sleeping",itemindex,characterid);
           }
           if (Itms.Itm[itemkey].Name=="Protecting Spell")
           {
                return spellCasting("protecting",itemindex,characterid);
           }
           if (Itms.Itm[itemkey].Name=="Escaping Spell")
           {
                return spellCasting("escaping",itemindex,characterid);
           }
           return "CAN'T USE THIS ITEM RIGHT NOW.\n";
        }
        else if (gamePhase=="AffectItem")
        {
            if (Itms.Itm[itemkey].Name=="Healing Staff")
            {
                if (Itms.Itm[itemkey].Name=="Healing Staff" && Clsses.Clss[ P.Chars[characterid].ClassId ].ClassName != "Cleric" )
                {
                    return "THIS CHARACTER CAN'T USE THIS ITEM.\n";
                };
                return "CHOOSE ONE CHARACTER TO HEAL.\n";
            }
            else if (Itms.Itm[itemkey].Name=="Blessing Spell" || Itms.Itm[itemkey].Name=="Blessing Gloves")
            {
                if (Itms.Itm[itemkey].Name=="Blessing Spell" && Clsses.Clss[ P.Chars[characterid].ClassId ].ClassName != "Cleric"
                                                                  && Clsses.Clss[ P.Chars[characterid].ClassId ].ClassName != "Wizard" )
                {
                    return "THIS CHARACTER CAN'T USE THIS ITEM.\n";
                };
                if (Itms.Itm[itemkey].Name=="Blessing Gloves" && Clsses.Clss[ P.Chars[characterid].ClassId ].ClassName != "Cleric" )
                {
                    return "THIS CHARACTER CAN'T USE THIS ITEM.\n";
                };
                return "CHOOSE ONE CHARACTER TO BLESS.\n";
            }
            else
            {
                return "CAN'T USE THIS ITEM RIGHT NOW.\n";
            };
        };

    };
    return "";
}

QString Data::monsterAttack(int characterid)
{
    if (isCharacterStatus("Protected",characterid)==1) return "miss";
    int rand=intrand(1,6);
    int modifier = 0;

    if (isCharacterEquip("Light Armor",characterid)) modifier+=1;
    if (isCharacterEquip("Heavy Armor",characterid)) modifier+=2;
    if (isCharacterEquip("Shield",characterid)) modifier+=1;
    if (isCharacterTrait("Def + lvl",characterid)) modifier+=P.Chars[characterid].Level;
    if (isCharacterTrait("Def +1 vs. Troll,Ogre,Giant",characterid) && (battleMonster.name=="Trolls"
                                                                        || battleMonster.name=="Ogre")) modifier+=1;

    if (isCharacterStatus("Cursed",characterid)) modifier-=1;
    if (battleMonster.name=="Minotaur") modifier-=1;

    if (rand==6) return "miss";//successful

    if (rand==1 || rand+modifier<=battleMonster.level)
    {
        if (battleMonster.name=="Scorpions")
        {
            int chance=intrand(1,6);
            if (chance==1) P.Chars[characterid].Life-=2;
            else P.Chars[characterid].Life-=1;
        }
        if (battleMonster.name=="Giant Centipedes")
        {
            int chance=intrand(1,6);
            if (Clsses.Clss[P.Chars[characterid].ClassId].ClassName=="Barbarian") chance+=1;
            if (chance<=2) P.Chars[characterid].Life-=2;
            else P.Chars[characterid].Life-=1;
        }
        if (battleMonster.name=="Fungi Folk")
        {
            int chance=intrand(1,6);
            if (Clsses.Clss[P.Chars[characterid].ClassId].ClassName=="Barbarian") chance+=1;
            if (chance<=3) P.Chars[characterid].Life-=2;
            else P.Chars[characterid].Life-=1;
        }
        if (battleMonster.name=="Iron Eater")
        {
           P.Chars[characterid].Life-=1;
           if (P.Chars[characterid].Armor!="None") P.Chars[characterid].Armor="None";
           else if (P.Chars[characterid].OffHand!="None") P.Chars[characterid].OffHand="None";
           else if (P.Chars[characterid].MainHand!="None") P.Chars[characterid].MainHand="None";
           else P.totalGold = max(0,P.totalGold-10);
        }
        else if (battleMonster.name=="Insect King")
        {
            int chance=intrand(1,6);
            if (Clsses.Clss[P.Chars[characterid].ClassId].ClassName=="Barbarian") chance+=1;
            if (chance<=3) P.Chars[characterid].Life-=2;
            else P.Chars[characterid].Life-=1;
        }
        else
        {
            P.Chars[characterid].Life-=1;
        };
        return "hit";
    };
    return "miss";
}

QString Data::monsterSpecialAttack(int effectlvl, int characterid)
{
    if (isCharacterStatus("Protected",characterid)==1) return "miss";
    int rand=intrand(1,6);
    if (rand<=effectlvl)
    {
        P.Chars[characterid].Life-=1;
        return "hit";
    }
    return "miss";
}


QString Data::lootAfterBattle()
{
    int i;
    for (i=0;i<P.partysize;i++)
    {
        removeStatus("Holy-Blessed",i);
        removeStatus("Protected",i);
    };
    QString result="YOU WON THE BATTLE.\n";
    int havegold=0;
    if (battleMonster.treasureAmount!=0)
    {
        result+="YOUR PARTY GOT: ";
        QString item="";
        for (i=0;i<battleMonster.treasureAmount;i++)
        {
            item=treasureEvent(battleMonster.treasureModifier);
            if (item!="gold")
            {
                addItem(item,0);
            }
            else havegold=1;
            result+=item;
            if (i==battleMonster.treasureAmount-1) result+=".";
            else result+=", ";
        };
    };
    if (havegold==1) result+=stealGold();
    return result;
}

QString Data::gainXpRoll()
{
    if (battleMonster.amountDice<0)
    {
      P.xpRolls+=1;
      return "YOU PARTY HAS GAINED 1 XP ROLL.";
    }
    else
    {
       P.monstersKilled+=1;
       if (P.monstersKilled%5==0)
       {
          P.xpRolls+=1;
          return "YOU PARTY HAS GAINED 1 XP ROLL.";
       };
    };
    return "";
}

void Data::healCharacter(int itemindex, int characterid1, int characterid2,int lifeAmount)
{
    P.Chars[characterid1].Life=min(P.Chars[characterid1].Life+lifeAmount,Clsses.Clss[ P.Chars[characterid1].ClassId ].BaseLife + P.Chars[characterid1].Level);
    P.Chars[characterid2].ItemCharges[itemindex]-=1;
    if (P.Chars[characterid2].ItemCharges[itemindex]==0) removeItem(itemindex,characterid2);
}

void Data::blessCharacter(int itemindex, int characterid1, int characterid2)
{
    addStatus("Holy-Blessed",characterid1);
    removeStatus("Cursed",characterid1);
    P.Chars[characterid2].ItemCharges[itemindex]-=1;
    if (P.Chars[characterid2].ItemCharges[itemindex]==0) removeItem(itemindex,characterid2);
}

int Data::isAllFled()
{
    int i;
    for (i=0;i<P.partysize;i++)
    {
        if (P.Chars[i].isFlee!=1) return 0;
    };
    return 1;
}

int Data::monsterAttackFirst()
{
    if (battleMonster.name=="Catoblepas")
    {
        battleMonster.name="Catoblepas-FirstAttack";
        return 1;
    }

    if (battleMonster.name=="Goblins")
    {
        int rand=intrand(1,6);
        if (rand==1) return 1;
    };
    return 0;
}

int Data::monsterRegenerate()
{
    int flag=0;
    if (battleMonster.name=="Trolls")
    {
        int i;
        for (i=0;i<(battleMonster.originalAmount-battleMonster.amount);i++)
        {
            int rand=intrand(1,6);
            if (rand==6)
            {
                battleMonster.amount+=1;
                flag=1;
            };
        };
    };
    return flag;
}

int Data::monsterBreathFire()
{
    if (battleMonster.name=="Chimera")
    {
        int rand=intrand(1,6);
        if (rand<=3) return 1;
        return 0;
    };
    return 0;
}

void Data::createBattleMonster(QString monster, QString type)
{
    Monster monsterInfo;
    if (type=="Vermin")
    {
        monsterInfo=Mns.vermins[getMonsterKey(monster)];
    };
    if (type=="Minion")
    {
        monsterInfo=Mns.minions[getMonsterKey(monster)];
    };
    if (type=="WeirdMonster")
    {
        monsterInfo=Mns.weirdMonsters[getMonsterKey(monster)];
    };
    if (type=="Special")
    {
        monsterInfo=Mns.specialMonsters[getMonsterKey(monster)];
    };

    battleMonster.name=monsterInfo.name;
    battleMonster.type=type;
    battleMonster.amountDice=monsterInfo.amountDice;
    battleMonster.amountModifier=monsterInfo.amountModifier;
    battleMonster.level=monsterInfo.level;
    battleMonster.weakness=monsterInfo.weakness;
    battleMonster.ability=monsterInfo.ability;
    battleMonster.treasureAmount=monsterInfo.treasureAmount;
    battleMonster.treasureModifier=monsterInfo.treasureModifier;
    battleMonster.amount=monsterInfo.amountModifier;

    if (monsterInfo.amountDice<0)
    {
        battleMonster.amount=-monsterInfo.amountDice;
    }
    else
    {
        int i;
        for (i=0;i<monsterInfo.amountDice;i++)
        {
            battleMonster.amount+=intrand(1,6);
        };
    }
    battleMonster.originalAmount = battleMonster.amount;
    battleMonster.reaction=monsterInfo.reactions[intrand(0,6-1)];

}

QString Data::spellEvent()
{
    int rand=intrand(1,6);
    if (rand==1) return "Blessing Spell";
    else if (rand==2) return "Fireball Spell";
    else if (rand==3) return "Lightning Bolt Spell";
    else if (rand==4) return "Sleeping Spell";
    else if (rand==5) return "Escaping Spell";
    else if (rand==6) return "Protecting Spell";
    return "";
}

QString Data::magicTreasureEvent()
{
    int rand=intrand(1,6);
    if (rand==1) return "Wand of Sleep";
    else if (rand==2) return "Ring of Teleportation";
    else if (rand==3) return "Fools Gold";
    else if (rand==4) return "Magic Weapon";
    else if (rand==5) return "Escaping Spell";
    else if (rand==6) return "Protecting Spell";
    return "";
}

QString Data::treasureEvent(int modifier)
{
    int rand=intrand(1,6)+modifier;
    if (rand<=1)
    {
        P.totalGold+=intrand(1,6);
        return "gold";
    }
    else if (rand==2)
    {
        P.totalGold+=intrand(1,6)+intrand(1,6);
        return "gold";
    }
    else if (rand==3)
    {
        return "Gem";
    }
    else if (rand==4)
    {
        return "Jewelry";
    }
    else if (rand==5)
    {
        return spellEvent();
    }
    else if (rand>=6)
    {
        return magicTreasureEvent();
    };
    return "";
}

QString Data::trapEvent()
{   
    int rand=intrand(1,6);
    if (rand==1)
    {
        if (trapDisarm(2)=="hit") return "The rogue disarmed the trap successfully.";
        int characterid=intrand(0,P.partysize-1);
        trapDefense("Dart",2,1,characterid);
        removeDeadCharacters();
        return "Dart trap has activated. It attacks one random character.";
    }
    if (rand==2)
    {
        if (trapDisarm(3)=="hit") return "The rogue disarmed the trap successfully.";
        int i;
        for (i=0;i<P.partysize;i++)
        {
            trapDefense("Poison Gas",3,2,i);
            removeDeadCharacters();
            return "Poison Gas trap has activated. It attacks all characters.";
        };
    }
    else if (rand==3)
    {
        if (trapDisarm(4)=="hit") return "The rogue disarmed the trap successfully.";
        trapDefense("Trapdoor",4,2,0);
        removeDeadCharacters();
        return "Trapdoor has activated. It attacks the leader.";
    }
    else if (rand==4)
    {
        if (trapDisarm(4)=="hit") return "The rogue disarmed the trap successfully.";
        trapDefense("Bear Trap",4,2,0);
        removeDeadCharacters();
        return "Bear trap has activated. It attacks the leader.";
    }
    else if (rand==5)
    {
        if (trapDisarm(5)=="hit") return "The rogue disarmed the trap successfully.";
        int characterid=intrand(0,P.partysize-1);
        trapDefense("Spears",5,2,characterid);
        int secondcharacterid= intrand(0,P.partysize-1);
        if (P.partysize != 1)
        {
            while (secondcharacterid==characterid)
            {
                secondcharacterid= intrand(0,P.partysize-1);
            };
            trapDefense("Spears",5,2,secondcharacterid);
        };
        removeDeadCharacters();
        return "Spears trap has activated. It attacks two random characters.";
    }
    else if (rand==6)
    {
        if (trapDisarm(5)=="hit") return "The rogue disarmed the trap successfully.";
        trapDefense("Giant Stone",5,2,P.partysize-1);
        removeDeadCharacters();
        return "Giant stone trap has activated. It attacks the last character.";
    };
    return "";

}

QString Data::fountainEvent()
{
    int i;
    for (i=0;i<=P.partysize;i++)
    {
        P.Chars[i].Life=min(P.Chars[i].Life+1,Clsses.Clss[ P.Chars[i].ClassId ].BaseLife + P.Chars[i].Level);
    };
    return "All characters got healed one life point.\n";
}

QString Data::holyRelicEvent()
{
    int i;
    for (i=0;i<P.partysize;i++)
    {
        addStatus("Holy-Blessed",i);
        removeStatus("Cursed",i);
    };
    return "All characters got holy blessed.\n";
}

QString Data::cursedAltarEvent()
{
    int rand=intrand(0,P.partysize-1);
    addStatus("Cursed",rand);
    return P.Chars[rand].Name+" is cursed.\n";
}

QString Data::armoryEvent()
{
    int i;
    for (i=0;i<P.partysize;i++)
    {
        int rand=intrand(0,7);
        addItem(Itms.Itm[rand].Name,i);
    };
    return "All characters got a random weapon.\n";
}

QString Data::statueEvent()
{
    int rand=intrand(1,6);
    if (rand==1 || rand==3 || rand==5)
    {
        M.Map[M.PL.x][M.PL.y]=getObjectKey("Treasure");
        return "Your party have found a treasure.";
    }
    else
    {
        createBattleMonster("Statue","Special");
        return "Monster";
    };

}

int Data::min(int a, int b)
{
    if (a<b) return a;
    return b;
}

int Data::max(int a, int b)
{
    if (a>b) return a;
    return b;
}

QString Data::createRoom()
{
    char d;
    if ( M.Map[M.PL.x][M.PL.y] == getObjectKey("Door") || M.Map[M.PL.x][M.PL.y] == getObjectKey("Corridor")) // if player stand on door or corridor
    {
        if (M.Map[M.PL.x-1][M.PL.y] >0) d='D';
        else if (M.Map[M.PL.x+1][M.PL.y] >0) d='U';
        else if (M.Map[M.PL.x][M.PL.y-1] >0) d='R';
        else if (M.Map[M.PL.x][M.PL.y+1] >0) d='L';

        int random_room=intrand(0,R.size-1);
        int num; Coord *Ptr;
        if (M.Map[M.PL.x][M.PL.y] == getObjectKey("Door"))
        {
            num=R.Ro[random_room].Doors;
            Ptr=R.Ro[random_room].Ds;
        }
        else if (M.Map[M.PL.x][M.PL.y] == getObjectKey("Corridor"))
        {
            num=R.Ro[random_room].Corridors;
            Ptr=R.Ro[random_room].Cs;
        };

        Coord Find; Find.x=-1; Find.y=-1;
        while (Find.x==-1 && Find.y==-1)
        {
            int i;
            for (i=0;i<num;i++)
            {
                int x=Ptr[i].x;
                int y=Ptr[i].y;
                if (x<R.Ro[random_room].width-1 && R.Ro[random_room].S[x+1][y]>0 && d=='D')
                {
                    Find.x=x;
                    Find.y=y;
                    break;
                }
                else if (x>=1 && R.Ro[random_room].S[x-1][y]>0 && d=='U')
                {
                    Find.x=x;
                    Find.y=y;
                    break;
                }
                else if (y<R.Ro[random_room].length-1 && R.Ro[random_room].S[x][y+1]>0 && d=='R')
                {
                    Find.x=x;
                    Find.y=y;
                    break;
                }
                else if (y>=1 && R.Ro[random_room].S[x][y-1]>0 && d=='L')
                {
                    Find.x=x;
                    Find.y=y;
                    break;
                }
            }
            if (Find.x== -1 && Find.y==-1)
            {
                random_room=intrand(0,R.size-1);
                if (M.Map[M.PL.x][M.PL.y] == getObjectKey("Door"))
                {
                    num=R.Ro[random_room].Doors;
                    Ptr=R.Ro[random_room].Ds;
                }
                else if (M.Map[M.PL.x][M.PL.y] == getObjectKey("Corridor"))
                {
                    num=R.Ro[random_room].Corridors;
                    Ptr=R.Ro[random_room].Cs;
                };
            };
        };

        if (M.PL.x<=4 && M.PL.y<=4)
        {
            M.Map[M.PL.x][M.PL.y]=getObjectKey("Floor");
        }
        else
        {
            // roll for Room Cotent
            int random_content=intrand(0,RC.size-1);
            if (R.Ro[random_room].S[Find.x][Find.y] == getObjectKey("Corridor")) createEvent(RC.RmCont[random_content].CorridorResult);
            if (R.Ro[random_room].S[Find.x][Find.y] == getObjectKey("Door")) createEvent(RC.RmCont[random_content].DoorResult);
            // random tile position in room for Room Cotent
            while (R.Ro[random_room].S[M.EventTile.x][M.EventTile.y] != getObjectKey("Floor"))
            {
                M.EventTile.x = intrand(0,R.Ro[random_room].width-1);
                M.EventTile.y = intrand(0,R.Ro[random_room].length-1);
            };

            // draw Room
            int beginx=M.PL.x-Find.x, beginy=M.PL.y-Find.y;
            M.EventTile.x+=beginx;
            M.EventTile.y+=beginy;
            drawRoom(Find.x,Find.y,beginx,beginy,random_room,1);
            M.room_counter++;

            // activate immediately-type event
            if (hasEvent==1)
            {
                hasEvent=0;
                if (M.EventTileKey==getObjectKey("Cursed Altar"))
                {
                    return cursedAltarEvent();
                };
                // monster event
                //vermin monsters
                if (M.EventTileKey==getObjectKey("Scorpions"))
                {
                    createBattleMonster("Scorpions","Vermin");
                    return "Monster";
                };
                if (M.EventTileKey==getObjectKey("Vampire Bats"))
                {
                    createBattleMonster("Vampire Bats","Vermin");
                    return "Monster";
                };
                if (M.EventTileKey==getObjectKey("Goblin Swarmlings"))
                {
                    createBattleMonster("Goblin Swarmlings","Vermin");
                    return "Monster";
                };
                if (M.EventTileKey==getObjectKey("Giant Centipedes"))
                {
                    createBattleMonster("Giant Centipedes","Vermin");
                    return "Monster";
                };
                if (M.EventTileKey==getObjectKey("Vampire Frogs"))
                {
                    createBattleMonster("Vampire Frogs","Vermin");
                    return "Monster";
                };
                if (M.EventTileKey==getObjectKey("Ghouls"))
                {
                    createBattleMonster("Ghouls (Undead)","Vermin");
                    return "Monster";
                };
                if (M.EventTileKey==getObjectKey("Skeletons"))
                {
                    createBattleMonster("Skeletons (Undead)","Minion");
                    return "Monster";
                };
                if (M.EventTileKey==getObjectKey("Zombies"))
                {
                    createBattleMonster("Zombies (Undead)","Minion");
                    return "Monster";
                };
                if (M.EventTileKey==getObjectKey("Goblins"))
                {
                    createBattleMonster("Goblins","Minion");
                    return "Monster";
                };
                if (M.EventTileKey==getObjectKey("Hobgoblins"))
                {
                    createBattleMonster("Hobgoblins","Minion");
                    return "Monster";
                };
                if (M.EventTileKey==getObjectKey("Orcs"))
                {
                    createBattleMonster("Orcs","Minion");
                    return "Monster";
                };
                if (M.EventTileKey==getObjectKey("Trolls"))
                {
                    createBattleMonster("Trolls","Minion");
                    return "Monster";
                };
                if (M.EventTileKey==getObjectKey("Fungi Folk"))
                {
                    createBattleMonster("Fungi Folk","Minion");
                    return "Monster";
                };
                if (M.EventTileKey==getObjectKey("Minotaur"))
                {
                    createBattleMonster("Minotaur","WeirdMonster");
                    return "Monster";
                };
                if (M.EventTileKey==getObjectKey("Iron Eater"))
                {
                    createBattleMonster("Iron Eater","WeirdMonster");
                    return "Monster";
                };
                if (M.EventTileKey==getObjectKey("Chimera"))
                {
                    createBattleMonster("Chimera","WeirdMonster");
                    return "Monster";
                };
                if (M.EventTileKey==getObjectKey("Catoblepas"))
                {
                    createBattleMonster("Catoblepas","WeirdMonster");
                    return "Monster";
                };
                if (M.EventTileKey==getObjectKey("Insect King"))
                {
                    createBattleMonster("Insect King","WeirdMonster");
                    return "Monster";
                };
            };
        };

    };
    return "";
}

QString Data::randomName()
{
    return Nms.name[intrand(0,Nms.size-1)];
}


int Data::intrand(int min, int max)
{
    int n = max - min + 1;
    int remainder = RAND_MAX % n;
    int x;
    do
    {
        x = rand();
    } while (x >= RAND_MAX - remainder);
    return min + x % n;
}

int Data::getItemKey(QString str)
{
    int i;
    for (i=0;i<Itms.size;i++)
    {
        if (str == Itms.Itm[i].Name)
        {
            return i;
        };
    };
    return -1;
}

int Data::getMonsterKey(QString str)
{
    int i;
    for (i=0;i<Mns.verminSize;i++)
    {
        if (str == Mns.vermins[i].name) return i;
    };
    for (i=0;i<Mns.minionSize;i++)
    {
        if (str == Mns.minions[i].name) return i;
    };
    for (i=0;i<Mns.weirdMonsterSize;i++)
    {
        if (str == Mns.weirdMonsters[i].name) return i;
    };
    for (i=0;i<Mns.bossSize;i++)
    {
        if (str == Mns.bosses[i].name) return i;
    };
    for (i=0;i<Mns.specialMonsterSize;i++)
    {
        if (str == Mns.specialMonsters[i].name) return i;
    };
    return -1;
}

int Data::removeDeadCharacters()
{
    int flag=0;
    int i,j;
    for (i=0;i<P.partysize;i++)
    {
        if (P.Chars[i].Life<=0)
        {
            flag=1;
            P.Chars[i].Life=0;
            Character temp=P.Chars[i];
            for (j=i+1;j<P.partysize;j++)
            {
                P.Chars[j-1]=P.Chars[j];
            };
            P.Chars[P.partysize-1]=temp;
            P.partysize--;
        };
    };
    return flag;
}

int Data::isallDeadCharacters()
{
    int count=0;
    int i;
    for (i=0;i<4;i++)
    {
        if (P.Chars[i].Life<=0)
        {
          count++;
        };
    };
    if (count==4) return 1;
    return 0;
}

int Data::getObjectKey(QString object)
{
    int i;
    for (i=0;i<O.size;i++)
    {
        if (O.Obj[i].name == object)
        {
            return i;
        };
    };
    return -1;
}

void Data::addItem(QString item, int characterid)
{
    P.Chars[characterid].Items[P.Chars[characterid].ItemsSize]=item;
    P.Chars[characterid].ItemCharges[P.Chars[characterid].ItemsSize]=Itms.Itm[getItemKey(item)].Charges;
    P.Chars[characterid].ItemsSize++;
}

void Data::removeItem(int itemindex, int characterid)
{
    int i;
    for (i=itemindex+1;i<P.Chars[characterid].ItemsSize;i++)
    {
        P.Chars[characterid].Items[i-1]=P.Chars[characterid].Items[i];
        P.Chars[characterid].ItemCharges[i-1]=P.Chars[characterid].ItemCharges[i];
    };
    P.Chars[characterid].Items[P.Chars[characterid].ItemsSize-1]="";
    P.Chars[characterid].ItemCharges[P.Chars[characterid].ItemsSize-1]=-1;
    P.Chars[characterid].ItemsSize-=1;
}

void Data::addStatus(QString status, int characterid)
{
    if (isCharacterStatus(status,characterid)==0)
    {
        P.Chars[characterid].Status[P.Chars[characterid].StatusSize]=status;
        P.Chars[characterid].StatusSize++;
    };
}

void Data::removeStatus(QString status, int characterid)
{
    int i;
    for (i=0;i<P.Chars[characterid].StatusSize;i++)
    {
        if (status==P.Chars[characterid].Status[i])
        {
            int j;
            for (j=i+1;j<P.Chars[characterid].StatusSize;j++)
            {
                P.Chars[characterid].Status[j-1]=P.Chars[characterid].Status[j];
            };
            P.Chars[characterid].Status[P.Chars[characterid].StatusSize-1]="";
            P.Chars[characterid].StatusSize-=1;
            return;
        };
    };
}

int Data::isCharacterEquip(QString item, int characterid)
{
    if (item==P.Chars[characterid].MainHand) return 1;
    if (item==P.Chars[characterid].OffHand) return 1;
    if (item==P.Chars[characterid].Armor) return 1;
    return 0;
}

int Data::isCharacterStatus(QString status, int characterid)
{
    int i;
    for (i=0;i<P.Chars[characterid].StatusSize;i++)
    {
        if (status==P.Chars[characterid].Status[i]) return 1;
    };
    return 0;
}

int Data::isCharacterTrait(QString trait, int characterid)
{
    int i;
    for (i=0;i<Clsses.Clss[P.Chars[characterid].ClassId].numberofTraits;i++)
    {
        if (trait==Clsses.Clss[P.Chars[characterid].ClassId].Traits[i]) return 1;
    };
    return 0;
}

int Data::isUsableEquipment(QString equipment, int characterid)
{
    int i;

    QString type="Weapon";
    if (equipment=="Shield" || equipment=="Bow" || equipment=="Sling") type="OffHand";
    if (equipment=="Light Armor" || equipment=="Heavy Armor") type="Armor";

    for (i=0;i<Clsses.Clss[P.Chars[characterid].ClassId].numberofUsableEquipments;i++)
    {
        if (type=="Weapon" && Clsses.Clss[P.Chars[characterid].ClassId].UsableEquipments[i]=="Any Weapon") return 1;
        if (type=="Armor" && Clsses.Clss[P.Chars[characterid].ClassId].UsableEquipments[i]=="Any Armor") return 1;
        if (equipment==Clsses.Clss[P.Chars[characterid].ClassId].UsableEquipments[i]) return 1;
    };
    return 0;
}


QString Data::interactObject()
{
    if (O.Obj[M.Map[M.PL.x][M.PL.y]].isInteractive==1)
    {
        QString item;
        if (M.Map[M.PL.x][M.PL.y]==getObjectKey("Treasure"))
        {
            item=treasureEvent(0);
            if (item!="gold")
            {
                addItem(item,0);
                M.Map[M.PL.x][M.PL.y]=getObjectKey("Floor");
                return "Your leader got "+item+".\n";
            }
            else
            {
                M.Map[M.PL.x][M.PL.y]=getObjectKey("Floor");
                return "You party got some golds."+stealGold();
            };
        }
        else if (M.Map[M.PL.x][M.PL.y]==getObjectKey("Trap Treasure"))
        {
            M.Map[M.PL.x][M.PL.y]=getObjectKey("Treasure");
            return trapEvent();

        }
        else if (M.Map[M.PL.x][M.PL.y]==getObjectKey("Fountain"))
        {
            M.Map[M.PL.x][M.PL.y]=getObjectKey("Dried Fountain");
            return fountainEvent();
        }
        else if (M.Map[M.PL.x][M.PL.y]==getObjectKey("Holy Relic"))
        {
            M.Map[M.PL.x][M.PL.y]=getObjectKey("Used Holy Relic");
            return holyRelicEvent();
        }
        else if (M.Map[M.PL.x][M.PL.y]==getObjectKey("Armory"))
        {
            M.Map[M.PL.x][M.PL.y]=getObjectKey("Floor");
            return armoryEvent();
        }
        else if (M.Map[M.PL.x][M.PL.y]==getObjectKey("Statue"))
        {
            return statueEvent();
        }
        else if (M.Map[M.PL.x][M.PL.y]==getObjectKey("Puzzle"))
        {
            if (puzzleSolving(0)=="fail")
            {
               return P.Chars[0].Name+" has failed to solve the puzzle, and take some damage.\n";
            }
            else{
               M.Map[M.PL.x][M.PL.y]=getObjectKey("Solved Puzzle");
               QString item=treasureEvent(0);
               if (item!="gold") addItem(item,0);
               else item+="."+stealGold();
               return P.Chars[0].Name+" has solved the puzzle successfully.\nYour party got "+item+".";
            };
        }
    };
    return "Nothing happened.\n";
}

