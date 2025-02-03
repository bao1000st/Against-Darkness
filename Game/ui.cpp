#include "ui.h"
#include <stdio.h>
#include <conio.h>
#include <QDebug>
#include <QMediaPlaylist>

UI::UI(int x,int y,QGraphicsScene * scene)
{
    gamePhase="Creation";
    data= new Data();

    int i;
    for (i=0;i<=4;i++)
    {
        characters[i]= new Portrait(x+(90+45)*i,y-130);
        characterPics[i]= new CharacterPic(x+280+(30+45)*i,y+10);
        characterHealthBars[i]= new HealthBar(165,250+i*50);

        if (i==4) characters[i]->StartPortrait();
        scene->addItem(characters[i]);
    };
    for (i=0;i<7;i++)
    {
        itemPics[i]= new ItemPic(x+818,y-190+(i*26));
    };

    for (i=0;i<=4;i++)
    {
        classids[i]=-1;
    };

    infobox= new InfoBox(x+700,y-300);
    scene->addItem(infobox);

    setPixmap(QPixmap(":/res/images/characterPointer.png"));
    setPos(x-8,y);

    characterPointer=0;
    swapCharacterPointer=0;
    battlePointer=0;
    actionPointer=0;
    managePointer=0;
    itemPointer=0;
    affectItemPointer=0;
    monsterInfoPointer=0;

    // in-game setup--------------------
    int tempy=y-300;
    for (i=0;i<7;i++)
    {
        int j;
        tempy+=59;
        for (j=0;j<7;j++)
        {
            tileMap[i][j] = new Tile(x+220+59*j,tempy);
        };
    };
    monsterPic = new MonsterPic(x+151,y-330);
    battleEffect= new Effect(x+151,y-330);
    monsterEffect= new Effect(x+50,y-150);
    arrow = new PartyArrow(x+220+59*3+15,y-300+59*4+15);
    battleBackground = new BattleBackground(x+195,y-270);
    hitFlash = new BattleBackground(x+195,y-270);

    overworldBorder= new QGraphicsPixmapItem();
    overworldBorder->setPos(x+151,y-293);
    overworldBorder->setPixmap(QPixmap(":/res/images/OverworldBorder.png"));

    mapBorder= new QGraphicsPixmapItem();
    mapBorder->setPos(x+710,y-300);
    mapBorder->setPixmap(QPixmap(":/res/images/MapBorder.png"));

    quickInfoBorder= new QGraphicsPixmapItem();
    quickInfoBorder->setPos(x-53,y-180);
    quickInfoBorder->setPixmap(QPixmap(":/res/images/QuickInfoBorder.png"));

    gameOver = new QGraphicsPixmapItem();
    gameOver->setPos(x+195,y-270);
    gameOver->setPixmap(QPixmap(":/res/images/GameOver.png"));

    mapInfo = new Text(x+805,y-245);

    characterInfo = new Text(x+776,y-194);
    characterInfo->infomanFont();

    partyQuickInfo = new Text(x,y-150);
    partyQuickInfo->infomanFont();

    eventInfo = new Text(x+200,y+220);
    eventInfo->infomanFont();
    eventInfo->setScale(1.3);

    monsterLife = new Text(x+380,y-240);
    monsterLife->setDefaultTextColor(Qt::black);
    monsterLife->infomanFont();

    // add background music
    QMediaPlaylist *playlist = new QMediaPlaylist();
    QString a = QFileInfo("sounds/backgroundMusic.mp3").absoluteFilePath();
    playlist->addMedia(QUrl::fromLocalFile(a));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();

    // add navigate sound
    navigate = new QMediaPlayer();
    navigate->setMedia(QUrl("qrc:/res/sounds/navigate.wav"));
    // add select sound
    select = new QMediaPlayer();
    select->setMedia(QUrl("qrc:/res/sounds/select.wav"));
    // add setp sound
    step = new QMediaPlayer();
    step->setMedia(QUrl("qrc:/res/sounds/step.wav"));
    // add heal sound
    heal = new QMediaPlayer();
    heal->setMedia(QUrl("qrc:/res/sounds/heal.wav"));
    // add bless sound
    bless = new QMediaPlayer();
    bless->setMedia(QUrl("qrc:/res/sounds/bless.wav"));
    // add attack sound
    attack = new QMediaPlayer();
    attack->setMedia(QUrl("qrc:/res/sounds/attack.wav"));
    // add hit sound
    hit = new QMediaPlayer();
    hit->setMedia(QUrl("qrc:/res/sounds/hit.wav"));
    // add use sound
    use = new QMediaPlayer();
    use->setMedia(QUrl("qrc:/res/sounds/use.wav"));
    // add shot sound
    shot = new QMediaPlayer();
    shot->setMedia(QUrl("qrc:/res/sounds/shot.wav"));
    // add escaping sound
    escaping = new QMediaPlayer();
    escaping->setMedia(QUrl("qrc:/res/sounds/escaping.wav"));
    // add fireball sound
    fireball = new QMediaPlayer();
    fireball->setMedia(QUrl("qrc:/res/sounds/fireball.wav"));
    // add holywater sound
    holywater = new QMediaPlayer();
    holywater->setMedia(QUrl("qrc:/res/sounds/holywater.wav"));
    // add lightningbolt sound
    lightningbolt = new QMediaPlayer();
    lightningbolt->setMedia(QUrl("qrc:/res/sounds/lightningbolt.wav"));
    // add protecting sound
    protecting = new QMediaPlayer();
    protecting->setMedia(QUrl("qrc:/res/sounds/protecting.wav"));
    // add sleeping sound
    sleeping = new QMediaPlayer();
    sleeping->setMedia(QUrl("qrc:/res/sounds/sleeping.wav"));
    // add teleportring sound
    teleportring = new QMediaPlayer();
    teleportring->setMedia(QUrl("qrc:/res/sounds/teleportring.wav"));



}

void UI::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_Left)
    {
        if (gamePhase=="Creation")
        {
            characterPointer=characterPointer-1;
            if (characterPointer<0)
            {
                characterPointer=0;
            }
            else
            {
               setPos(x()-135,y());
               updatePortrait(characterPointer,classids[characterPointer]);
               updateInfoBox(classids[characterPointer]);
            };
            navigateSound();
        };
        if (gamePhase=="CharacterInfo")
        {
            characterPointer=characterPointer-1;
            if (characterPointer<0)
            {
                characterPointer=0;
            }
            else
            {
               infobox->EmptyBox();
               updateCharacterInfo(characterPointer);
               setPos(x()-135,y());
            };
            navigateSound();
        };
        if (gamePhase=="SwapCharacter" || gamePhase=="TransferItem" || gamePhase=="HealCharacter" || gamePhase=="BlessCharacter")
        {
            swapCharacterPointer-=1;
            if (swapCharacterPointer<0)
            {
                swapCharacterPointer=0;
            }
            else
            {
               setPos(x()-135,y());
               if (gamePhase=="HealCharacter" || gamePhase=="BlessCharacter") updateCharacterInfo(swapCharacterPointer);
            };
            navigateSound();
        };
        if (gamePhase=="In-game")
        {
            if (data->M.PL.y >=1)
            {
                if (data->O.Obj[ data->M.Map[data->M.PL.x][data->M.PL.y-1] ].isPass>0)
                {
                    data->M.PL.y--;
                    stepSound();
                    QString text=data->createRoom();
                    if (text!="")
                    {
                        if (text=="Monster")
                        {
                            updateMonsterEventInfo();
                        }
                        else eventInfo->setPlainText(text);
                    };
                    updateMap();
                    arrow->LeftArrow();
                };
            };
        };
        if (gamePhase=="Battle")
        {
            monsterInfoPointer-=1;
            if (monsterInfoPointer<0)
            {
                monsterInfoPointer=0;
            };
            navigateSound();
            updateActionInfo();
        };
    }
    else if (event->key() == Qt::Key_Right)
    {
        if (gamePhase=="Creation")
        {
            characterPointer=characterPointer+1;
            if (characterPointer>4)
            {
                characterPointer=4;
            }
            else
            {
                setPos(x()+135,y());
                updatePortrait(characterPointer,classids[characterPointer]);
                updateInfoBox(classids[characterPointer]);
            };
            navigateSound();
        };
        if (gamePhase=="CharacterInfo")
        {
            characterPointer=characterPointer+1;
            if (characterPointer>data->P.partysize-1)
            {
                characterPointer=data->P.partysize-1;
            }
            else
            {
                infobox->EmptyBox();
                updateCharacterInfo(characterPointer);
                setPos(x()+135,y());
            };
            navigateSound();
        };
        if (gamePhase=="SwapCharacter" || gamePhase=="TransferItem" || gamePhase=="HealCharacter" || gamePhase=="BlessCharacter")
        {
            swapCharacterPointer+=1;
            if (swapCharacterPointer>data->P.partysize-1)
            {
                 swapCharacterPointer=data->P.partysize-1;
            }
            else
            {
                setPos(x()+135,y());
                if (gamePhase=="HealCharacter" || gamePhase=="BlessCharacter") updateCharacterInfo(swapCharacterPointer);
            };
            navigateSound();
        };
        if (gamePhase=="In-game")
        {

            if (data->M.PL.y < data->M.length-1)
            {
                if (data->O.Obj[ data->M.Map[data->M.PL.x][data->M.PL.y+1] ].isPass>0)
                {
                    data->M.PL.y++;
                    stepSound();
                    QString text=data->createRoom();
                    if (text!="")
                    {
                        if (text=="Monster")
                        {
                            updateMonsterEventInfo();
                        }
                        else eventInfo->setPlainText(text);
                    };
                    updateMap();
                    arrow->RightArrow();
                };
            };
        };
        if (gamePhase=="Battle")
        {
            monsterInfoPointer+=1;
            if (monsterInfoPointer>1)
            {
                monsterInfoPointer=1;
            };
            updateActionInfo();
            navigateSound();
        };
    }
    else if (event->key() == Qt::Key_Up)
    {
        if (gamePhase=="Creation")
        {
            if (characterPointer!=4)
            {
                classids[characterPointer]=classids[characterPointer]+1;
                if (classids[characterPointer]>data->Clsses.size-1) // so luong class hien tai la 4
                {
                    classids[characterPointer]=0;
                };
            };
            updatePortrait(characterPointer,classids[characterPointer]);
            updateInfoBox(classids[characterPointer]);
            navigateSound();
        };
        if (gamePhase=="Shop")
        {
            itemPointer-=1;
            if (itemPointer<0)
            {
              itemPointer=0;
            }
            else
            {
              updateShopInfo();
            };
            navigateSound();
        };
        if (gamePhase=="CharacterInfo")
        {
            infobox->EmptyBox();
            updateCharacterInfo(characterPointer);
            navigateSound();
        };
        if (gamePhase=="ManageCharacter")
        {
            managePointer-=1;
            if (managePointer<0)
            {
                managePointer=0;
            };
            updateManagementInfo();
            navigateSound();
        };
        if (gamePhase=="ManageItems")
        {
            itemPointer-=1;
            if (itemPointer<0)
            {
              itemPointer=0;
            }
            else
            {
              updateItemManagementInfo(characterPointer);
            };
            navigateSound();
        };
        if (gamePhase=="AffectItem")
        {
            affectItemPointer-=1;
            if (affectItemPointer<0)
            {
              affectItemPointer=0;
            }
            else
            {
              updateAffectItemInfo();
            };
            navigateSound();
        };
        if (gamePhase=="In-game")
        {
            if (data->M.PL.x >=1)
            {
                if (data->O.Obj[ data->M.Map[data->M.PL.x-1][data->M.PL.y] ].isPass>0)
                {
                    data->M.PL.x--;
                    stepSound();
                    QString text=data->createRoom();
                    if (text!="")
                    {
                        if (text=="Monster")
                        {
                            updateMonsterEventInfo();
                        }
                        else eventInfo->setPlainText(text);
                    };
                    updateMap();
                    arrow->UpArrow();

                };
            };

        };
        if (gamePhase=="Battle")
        {
            actionPointer-=1;
            if (actionPointer<0)
            {
                actionPointer=0;
            };
            updateActionInfo();
            navigateSound();
        };
        if (gamePhase=="UseItemInBattle")
        {
            itemPointer-=1;
            if (itemPointer<0)
            {
              itemPointer=0;
            }
            else
            {
              updateItemManagementInfo(battlePointer);
            };
            navigateSound();
        };
    }
    else if (event->key() == Qt::Key_Down)
    {
        if (gamePhase=="Creation")
        {
            if (characterPointer!=4)
            {
                classids[characterPointer]=classids[characterPointer]-1;
                if (classids[characterPointer]<0)
                {
                    classids[characterPointer]=data->Clsses.size-1;
                };
            };
            updatePortrait(characterPointer,classids[characterPointer]);
            updateInfoBox(classids[characterPointer]);
            navigateSound();
        };
        if (gamePhase=="Shop")
        {
            itemPointer+=1;
            if (itemPointer>data->Itms.size-1)
            {
              itemPointer=data->Itms.size-1;
            }
            else
            {
                updateShopInfo();
            };
            navigateSound();
        };
        if (gamePhase=="CharacterInfo")
        {
            characterInfo->setPlainText("");
            updateInfoBox(data->P.Chars[characterPointer].ClassId);
            navigateSound();
        };
        if (gamePhase=="ManageCharacter")
        {
            managePointer+=1;
            if (managePointer>2)
            {
                managePointer=2;
            };
            updateManagementInfo();
            navigateSound();
        };
        if (gamePhase=="ManageItems")
        {
            itemPointer+=1;
            if (itemPointer>data->P.Chars[characterPointer].ItemsSize-1)
            {
              itemPointer=data->P.Chars[characterPointer].ItemsSize-1;
            }
            else
            {
                updateItemManagementInfo(characterPointer);
            };
            navigateSound();
        };
        if (gamePhase=="AffectItem")
        {
            affectItemPointer+=1;
            if (affectItemPointer>1)
            {
              affectItemPointer=1;
            }
            else
            {
              updateAffectItemInfo();
            };
            navigateSound();
        };
        if (gamePhase=="In-game")
        {
            if (data->M.PL.x < data->M.width-1)
            {
                if (data->O.Obj[ data->M.Map[data->M.PL.x+1][data->M.PL.y] ].isPass>0)
                {
                    data->M.PL.x++;
                    stepSound();
                    QString text=data->createRoom();
                    if (text!="")
                    {
                        if (text=="Monster")
                        {
                            updateMonsterEventInfo();
                        }
                        else eventInfo->setPlainText(text);
                    };
                    updateMap();
                    arrow->DownArrow();
                };
            };
        };
        if (gamePhase=="Battle")
        {
            actionPointer+=1;
            if (actionPointer>2)
            {
                actionPointer=2;
            };
            updateActionInfo();
            navigateSound();
        };
        if (gamePhase=="UseItemInBattle")
        {
            itemPointer+=1;
            if (itemPointer>data->P.Chars[battlePointer].ItemsSize-1)
            {
              itemPointer=data->P.Chars[battlePointer].ItemsSize-1;
            }
            else
            {
                updateItemManagementInfo(battlePointer);
            };
            navigateSound();
        };
    }
    else if (event->key() == Qt::Key_X)
    {
        if (gamePhase=="Creation"&& classids[0]!=-1 && classids[1]!=-1
                && classids[2]!=-1 && classids[3]!=-1)
        {
            if (characterPointer==4)
            {
                selectSound();
                endCharacterCreation();
                startShop();
                gamePhase="Shop";
            };
            dungeonMusic();
        }
        else if (gamePhase=="Shop")
        {
            selectSound();
            buyAction();
            updatePartyQuickInfo();
        }
        else if (gamePhase=="CharacterInfo")
        {
            startManageCharacter();
            gamePhase="ManageCharacter";
            selectSound();
        }
        else if (gamePhase=="ManageCharacter")
        {
            if (managePointer==0)
            {
                selectSound();
                startSwapCharacter();
                gamePhase="SwapCharacter";
            }
            else if (managePointer==1)
            {
                selectSound();
                startManageItems();
                updateItemManagementInfo(characterPointer);
                gamePhase="ManageItems";
            }
            else if (managePointer==2)
            {
                selectSound();
                levelupAction();
            };

        }
        else if (gamePhase=="SwapCharacter")
        {
           endSwapCharacter();
           gamePhase="CharacterInfo";
           selectSound();

        }
        else if (gamePhase=="ManageItems" && data->P.Chars[characterPointer].ItemsSize!=0)
        {
            startAffectItem();
            gamePhase="AffectItem";
            selectSound();
        }
        else if (gamePhase=="TransferItem")
        {
            endTransferItem();
            gamePhase="CharacterInfo";
            selectSound();
        }
        else if (gamePhase=="AffectItem")
        {
            if (affectItemPointer==0)
            {
                useSound();
                useItemAction();
            };
            if (affectItemPointer==1)
            {
                useSound();
                startTransferItem();
                gamePhase="TransferItem";
            };
        }
        else if (gamePhase=="HealCharacter")
        {
            healSound();
            data->healCharacter(itemPointer,swapCharacterPointer,characterPointer,1);
            gamePhase="CharacterInfo";
            endBlessHealCharacter();
        }
        else if (gamePhase=="BlessCharacter")
        {
            blessSound();
            data->blessCharacter(itemPointer,swapCharacterPointer,characterPointer);
            gamePhase="CharacterInfo";
            endBlessHealCharacter();
        }
        else if (gamePhase=="In-game")
        {
            selectSound();
            QString event=data->interactObject();
            if (event!="Nothing happened.")
            {
                if (event=="Monster")
                {
                    updateMonsterEventInfo();
                }
                else
                {
                    eventInfo->setPlainText(event);
                    updateMap();
                };
            };
        }
        else if (gamePhase=="MonsterEncounter")
        {
            selectSound();
            battleMusic();
            startBattle();
            gamePhase="Battle";
        }
        else if (gamePhase=="Battle")
        {
            if (actionPointer==0)
            {
                attackAction();
            };
            if (actionPointer==1)
            {
                selectSound();
                startUseItemInBattle();
                updateItemManagementInfo(battlePointer);
                gamePhase="UseItemInBattle";
            };
            if (actionPointer==2)
            {
                selectSound();
                fleeAction();
            };
        }
        else if (gamePhase=="UseItemInBattle")
        {
            useItemInBattleAction();
        };
    }
    else if (event->key() == Qt::Key_Z)
    {
        if (gamePhase=="In-game")
        {
            startCharacterInfo();
            gamePhase="CharacterInfo";
        }
        else if (gamePhase=="Shop")
        {
            navigateSound();
            nextBuyer();
        }
        else if (gamePhase=="CharacterInfo")
        {
            startInGame();
            gamePhase="In-game";
        }
        else if (gamePhase=="ManageCharacter")
        {
            endManageCharacter();
            gamePhase="CharacterInfo";
        }
        else if (gamePhase=="ManageItems")
        {
            endManageItems();
            gamePhase="CharacterInfo";
        }
        else if (gamePhase=="AffectItem")
        {
            endAffectItem();
            gamePhase="ManageItems";
        }
        else if (gamePhase=="HealCharacter" || gamePhase=="BlessCharacter")
        {
            endBlessHealCharacter();
            gamePhase="CharacterInfo";
        }
        else if (gamePhase=="UseItemInBattle")
        {
            endUseItemInBattle();
            gamePhase="Battle";
        }
        else if (gamePhase=="MonsterEncounter")
        {
            qDebug() << "wait";
        };
        navigateSound();
    };
    if (data->isallDeadCharacters()==1 && gamePhase!="Creation")
    {
        scene()->removeItem(arrow);
        scene()->addItem(gameOver);
        eventInfo->setPlainText(QString("You lose the game."));
        gamePhase="Game-Over";
        return;
    };
}

void UI::updateInfoBox(int id)
{
    if (id==-1)
    {
        infobox->EmptyBox();
    }
    else if (id==0)
    {
        infobox->WarriorBox();
    }
    else if (id==1)
    {
        infobox->ClericBox();
    }
    else if (id==2)
    {
        infobox->RogueBox();
    }
    else if (id==3)
    {
        infobox->WizardBox();
    }
    else if (id==4)
    {
        infobox->BarbarianBox();
    }
    else if (id==5)
    {
        infobox->ElfBox();
    }
    else if (id==6)
    {
        infobox->DwarfBox();
    }
    else
    {
        infobox->EmptyBox();
    };

}

void UI::updatePortrait(int character,int id)
{
    if (id==-1)
    {
        if (character!=4)
            characters[character]->EmptyPortrait();
    }
    else if (id==0)
    {
        characters[character]->WarriorPortrait();
    }
    else if (id==1)
    {
        characters[character]->ClericPortrait();
    }
    else if (id==2)
    {
        characters[character]->RoguePortrait();
    }
    else if (id==3)
    {
        characters[character]->WizardPortrait();
    }
    else if (id==4)
    {
        characters[character]->BarbarianPortrait();
    }
    else if (id==5)
    {
        characters[character]->ElfPortrait();
    }
    else if (id==6)
    {
        characters[character]->DwarfPortrait();
    }
    else
    {
        characters[character]->DwarfPortrait();
    }

}

void UI::endCharacterCreation()
{
    int i;
    for (i=0;i<=4;i++)
    {
        characters[i]->setPos(characters[i]->x()+135,characters[i]->y());
        scene()->removeItem(characters[i]);
    };
    scene()->removeItem(infobox);
    setPos(x()-135*3,y());
    setPixmap(QPixmap(""));
    characterPointer=0;

    for (i=0;i<4;i++)
    {
        data->createCharacter(i,classids[i],0);
        characterPicProxy[i]= scene()->addWidget(characterPics[i]);
        scene()->removeItem(characterPicProxy[i]);
    };
    data->createEntrance();
    for (i=0;i<7;i++)
    {
        int j;
        for (j=0;j<7;j++)
        {
            tileMapProxy[i][j] = scene()->addWidget(tileMap[i][j]);
            scene()->removeItem(tileMapProxy[i][j]);
        };
    };

    battleBackgroundProxy = scene()->addWidget(battleBackground);
    scene()->removeItem(battleBackgroundProxy);

    monsterPicProxy = scene()->addWidget(monsterPic);
    scene()->removeItem(monsterPicProxy);
}

void UI::startShop()
{
    gamePhase="NO";
    scene()->addItem(battleBackgroundProxy);
    battleBackground->changePic("");
    scene()->addItem(overworldBorder);
    scene()->addItem(mapBorder);
    scene()->addItem(quickInfoBorder);
    scene()->addItem(partyQuickInfo);
    scene()->addItem(eventInfo);
    scene()->addItem(mapInfo);
    mapInfo->infomanFont();
    int i;
    for (i=0;i<4;i++)
    {
        characterHealthBarProxy[i]=scene()->addWidget(characterHealthBars[i]);
        characterHealthBars[i]->setHealth(data->P.Chars[i].Life,data->P.Chars[i].Life);
        scene()->addItem(characterHealthBars[i]->health);
    };
    updatePartyQuickInfo();
    for (i=0;i<7;i++)
    {
        scene()->addItem(itemPics[i]);
    };
    battlePointer=0;
    itemPointer=0;
    eventInfo->setPlainText(QString("press Z to complete current character's purchase\nand go to the next character."));
    updateShopInfo();

    delay(1.0);
    scene()->addItem(monsterPicProxy);
    monsterPic->merchantPic();
    for (i=0;i<data->P.partysize;i++)
    {
        characterPics[i]->changePic(data->P.Chars[i].ClassId,"");
        scene()->addItem(characterPicProxy[i]);
        characterPicProxy[i]->setPos(characterPics[i]->x,characterPics[i]->y+20);
    };
    characterPicProxy[0]->setPos(characterPics[0]->x,characterPics[0]->y-20);
}

void UI::endShop()
{
    scene()->removeItem(monsterPicProxy);
    scene()->removeItem(battleBackgroundProxy);
    eventInfo->setPlainText(QString(""));
    updatePartyQuickInfo();
    battlePointer=0;
    itemPointer=0;
    int i;
    for (i=0;i<data->P.partysize;i++)
    {
        scene()->removeItem(characterPicProxy[i]);
    };
    for (i=0;i<7;i++)
    {
        scene()->removeItem(itemPics[i]);
    };

    for (i=0;i<7;i++)
    {
        int j;
        for (j=0;j<7;j++)
        {
            scene()->addItem(tileMapProxy[i][j]);
        };
    };
    updateMap();
    scene()->addItem(arrow);

    hitFlashProxy = scene()->addWidget(hitFlash);
    scene()->removeItem(hitFlashProxy);

    battleEffectProxy = scene()->addWidget(battleEffect);

    monsterEffectProxy = scene()->addWidget(monsterEffect);

    scene()->removeItem(overworldBorder);
    scene()->addItem(overworldBorder);
    scene()->removeItem(mapInfo);
    scene()->addItem(mapInfo);
    mapInfo->normalFont();
    gamePhase="In-game";

}

void UI::startCharacterInfo()
{
    setPixmap(QPixmap(":/res/images/characterPointer.png"));
    int i;
    for (i=0;i<4;i++)
    {
        scene()->removeItem(characterHealthBarProxy[i]);
        scene()->removeItem(characterHealthBars[i]->health);
    };
    for (i=0;i<4;i++)
    {
        updatePortrait(i,classids[i]);
    };
    for (i=0;i<data->P.partysize;i++)
    {
        scene()->addItem(characters[i]);
    };
    scene()->addItem(infobox);
    infobox->EmptyBox();

    updateCharacterInfo(characterPointer);
    scene()->addItem(characterInfo);

    for (i=0;i<7;i++)
    {
        int j;
        for (j=0;j<7;j++)
        {
            scene()->removeItem(tileMapProxy[i][j]);
        };
    };
    scene()->removeItem(overworldBorder);
    scene()->removeItem(mapBorder);
    scene()->removeItem(quickInfoBorder);
    scene()->removeItem(arrow);
    scene()->removeItem(mapInfo);
    scene()->removeItem(partyQuickInfo);
    scene()->removeItem(eventInfo);
}

void UI::startInGame()
{
    int i;
    for (i=0;i<data->P.partysize;i++)
    {
        scene()->removeItem(characters[i]);

    };
    scene()->removeItem(infobox);
    scene()->removeItem(characterInfo);
    for (i=0;i<7;i++)
    {
        int j;
        for (j=0;j<7;j++)
        {
            scene()->addItem(tileMapProxy[i][j]);
        };
    };
    updateMap();

    scene()->addItem(overworldBorder);
    scene()->addItem(mapBorder);
    scene()->addItem(quickInfoBorder);
    scene()->addItem(arrow);
    scene()->addItem(mapInfo);
    mapInfo->normalFont();
    scene()->addItem(partyQuickInfo);
    eventInfo->setPlainText("");
    scene()->addItem(eventInfo);

    setPos(x()-135*characterPointer,y());
    characterPointer=0;
    for (i=0;i<data->P.partysize;i++)
    {
        scene()->addItem(characterHealthBarProxy[i]);
        scene()->addItem(characterHealthBars[i]->health);
    };
}

void UI::startBattle()
{
    gamePhase="NO";
    int i;
    for (i=0;i<7;i++)
    {
        int j;
        for (j=0;j<7;j++)
        {
            scene()->removeItem(tileMapProxy[i][j]);
        };
    };
    scene()->removeItem(arrow);

    scene()->addItem(battleBackgroundProxy);
    battleBackground->changePic("");

    for (i=0;i<data->P.partysize;i++)
    {
        characterPics[i]->changePic(data->P.Chars[i].ClassId,"");
        scene()->addItem(characterPicProxy[i]);
        characterPicProxy[i]->setPos(characterPics[i]->x,characterPics[i]->y+20);
    };
    monsterPic->changePic(data->battleMonster.name,"");
    scene()->addItem(monsterPicProxy);

    scene()->addItem(monsterLife);
    QString t="";
    if (data->battleMonster.amountDice>=0) t="AMOUNT: "+QString::number(data->battleMonster.amount);
    else t="HEATH: "+QString::number(data->battleMonster.amount);
    monsterLife->setHtml("<div style='background-color:#666666;'>" + t + "</div>");

    mapInfo->infomanFont();
    updateActionInfo();

    eventInfo->setPlainText(QString(""));
    setPixmap(QPixmap(""));

    if (data->monsterAttackFirst())
    {
        battlePointer=data->P.partysize;
        monsterAttackPhase();
        if (data->isallDeadCharacters()==1)
        {
            endBattle("lose");
            return;
        }
        if (data->isAllFled()==1)
        {
            endBattle("flee");
            return;
        };
    };
    delay(1);

    shotAction();
    characterPicProxy[battlePointer]->setPos(characterPics[battlePointer]->x,characterPics[battlePointer]->y-20);
    gamePhase="Battle";
}

void UI::endBattle(QString outcome)
{
    gamePhase="NO";
    data->M.Map[data->M.EventTile.x][data->M.EventTile.y]=data->getObjectKey("Floor");
    scene()->removeItem(monsterLife);
    scene()->removeItem(monsterPicProxy);
    if (outcome=="flee")
    {
        eventInfo->setPlainText(QString("Battle is over. Your party has escaped."));
    }
    else if (outcome=="lose")
    {
        scene()->addItem(gameOver);
        eventInfo->setPlainText(QString("Battle is over. You lose the game."));
        gamePhase="Game-Over";
        return;
    }
    else
    {
        eventInfo->setPlainText(data->lootAfterBattle());
        QString xpevent=data->gainXpRoll();
        if (xpevent!="")
        {
            delay(2);
            eventInfo->setPlainText(xpevent);
        };
    };
    delay(2);
    int i;
    for (i=0;i<7;i++)
    {
        int j;
        for (j=0;j<7;j++)
        {
            scene()->addItem(tileMapProxy[i][j]);
        };
    };
    for (i=0;i<data->P.partysize;i++)
    {
        data->P.Chars[i].isFlee=0;
        scene()->removeItem(characterPicProxy[i]);
    };
    scene()->removeItem(battleBackgroundProxy);
    scene()->addItem(arrow);
    mapInfo->normalFont();
    updateMap();
    eventInfo->setPlainText(QString(""));
    setPixmap(QPixmap(""));
    battlePointer=0;
    actionPointer=0;
    monsterInfoPointer=0;
    gamePhase="In-game";
    dungeonMusic();
}

void UI::startManageCharacter()
{
    scene()->addItem(eventInfo);
    eventInfo->setPos(eventInfo->x()+150,eventInfo->y()-150);
    eventInfo->setPlainText("▶ SWAP\n  ITEMS\n  LEVEL UP ("+QString::number(data->P.xpRolls)+")\n");
}

void UI::endManageCharacter()
{
    scene()->removeItem(eventInfo);
    eventInfo->setPos(eventInfo->x()-150,eventInfo->y()+150);
    eventInfo->setPlainText(QString(""));
    managePointer=0;
}

void UI::startSwapCharacter()
{
    swapCharacterPointer=characterPointer;
    eventInfo->setPos(eventInfo->x()-170,eventInfo->y());
    eventInfo->setPlainText(QString("CHOOSE ANOTHER CHARACTER TO SWAP POSITION"));
}

void UI::endSwapCharacter()
{
    data->swapCharacter(characterPointer,swapCharacterPointer);

    int temp=classids[characterPointer];
    classids[characterPointer]=classids[swapCharacterPointer];
    classids[swapCharacterPointer]=temp;

    updatePortrait(characterPointer,classids[characterPointer]);
    updatePortrait(swapCharacterPointer,classids[swapCharacterPointer]);

    scene()->removeItem(eventInfo);
    eventInfo->setPos(eventInfo->x()+20,eventInfo->y()+150);
    eventInfo->setPlainText(QString(""));
    characterPointer=swapCharacterPointer;

}

void UI::startManageItems()
{
    managePointer=0;
    scene()->removeItem(infobox);
    scene()->removeItem(characterInfo);
    scene()->removeItem(eventInfo);
    eventInfo->setPlainText(QString(""));
    scene()->addItem(mapBorder);
    scene()->addItem(mapInfo);
    mapInfo->setPlainText(QString(""));
    mapInfo->infomanFont();
    int i;
    for (i=0;i<7;i++)
    {
        scene()->addItem(itemPics[i]);
    };
}

void UI::endManageItems()
{
    eventInfo->setPos(eventInfo->x()-150,eventInfo->y()+150);
    scene()->addItem(infobox);
    updateCharacterInfo(characterPointer);
    scene()->addItem(characterInfo);
    scene()->removeItem(mapBorder);
    scene()->removeItem(mapInfo);
    mapInfo->normalFont();
    itemPointer=0;
    managePointer=0;
    int i;
    for (i=0;i<7;i++)
    {
        scene()->removeItem(itemPics[i]);
    };

}

void UI::startAffectItem()
{
    scene()->addItem(eventInfo);
    eventInfo->setPlainText("▶ USE\n  TRANSFER\n");
}

void UI::endAffectItem()
{
    affectItemPointer=0;
    scene()->removeItem(eventInfo);
}

void UI::startTransferItem()
{
    swapCharacterPointer=characterPointer;
    eventInfo->setPos(eventInfo->x()-170,eventInfo->y());
    eventInfo->setPlainText(QString("CHOOSE ANOTHER CHARACTER TO TRANSFER THE ITEM"));
}

void UI::endTransferItem()
{
    if (characterPointer!=swapCharacterPointer)
        data->transferItem(itemPointer,characterPointer,swapCharacterPointer);

    scene()->removeItem(mapBorder);
    scene()->removeItem(eventInfo);
    scene()->removeItem(mapInfo);
    eventInfo->setPos(eventInfo->x()+20,eventInfo->y()+150);
    eventInfo->setPlainText(QString(""));

    scene()->addItem(infobox);
    infobox->EmptyBox();

    updateCharacterInfo(characterPointer);
    scene()->addItem(characterInfo);


    itemPointer=0;
    affectItemPointer=0;
    characterPointer=swapCharacterPointer;
    int i;
    for (i=0;i<7;i++)
    {
        scene()->removeItem(itemPics[i]);
    };
}

void UI::startBlessHealCharacter()
{
    swapCharacterPointer=characterPointer;
    scene()->removeItem(mapInfo);
    scene()->removeItem(mapBorder);
    scene()->addItem(infobox);
    scene()->addItem(characterInfo);
    int i;
    for (i=0;i<7;i++)
    {
        scene()->removeItem(itemPics[i]);
    };
    updateCharacterInfo(swapCharacterPointer);
}

void UI::endBlessHealCharacter()
{
    characterPointer=swapCharacterPointer;
    itemPointer=0;
    affectItemPointer=0;
    eventInfo->setPos(eventInfo->x(),eventInfo->y()+150);
    scene()->removeItem(eventInfo);
    updateCharacterInfo(characterPointer);
}

void UI::startUseItemInBattle()
{
    scene()->removeItem(mapBorder);
    scene()->addItem(mapBorder);
    managePointer=0;
    itemPointer=0;
    mapInfo->setPlainText(QString(""));
    mapInfo->infomanFont();
    int i;
    for (i=0;i<7;i++)
    {
        scene()->addItem(itemPics[i]);
    };

}

void UI::endUseItemInBattle()
{
    managePointer=0;
    itemPointer=0;
    mapInfo->setPlainText(QString(""));
    mapInfo->infomanFont();
    int i;
    for (i=0;i<7;i++)
    {
        scene()->removeItem(itemPics[i]);
    };
    updateActionInfo();
}


void UI::updateMap()
{
    int i,j;
    int beginx=data->M.PL.x - data->M.screen_size/2;
    int beginy=data->M.PL.y - data->M.screen_size/2;
    for (i=beginx;i<beginx+ data->M.screen_size;i++)
    {
        for (j=beginy;j<beginy + data->M.screen_size;j++)
        {
            if (i<0 || i>=data->M.width || j<0 || j>=data->M.length) tileMap[i-beginx][j-beginy]->VoidTile();
            //else if (i==M.PL.x && j==M.PL.y) Party_Tile(x,y);
            else tileMap[i-beginx][j-beginy]->changeTile(data->M.Map[i][j]);
        }
    };
    //data->M.EventTile.x=-1;
    //data->M.EventTile.y=-1;
    printMapInfo();
    updatePartyQuickInfo();

}

void UI::printMapInfo()
 {
    QString result= "";
    int i,j;
    for (i=0;i<data->M.width;i++)
    {
        for (j=0;j<data->M.length;j++)
        {

            if (i == data->M.PL.x && j == data->M.PL.y) result+="╬";
            else if (data->M.Map[i][j] == data->getObjectKey("Door") || data->M.Map[i][j]== data->getObjectKey("Corridor")) result+="░";
            else if (data->M.Map[i][j] <= data->getObjectKey("Void")) result+="▁";
            //else if (data->M.Map[i][j] != data->getObjectKey("Floor")) result+="";
            else result+="█";
        };
        result+="\n";
    };
    mapInfo->setPlainText(result);
}

void UI::updateShopInfo()
{
    QString result;
    result+=QString::number(itemPointer+1)+"/"+QString::number(data->Itms.size)+"\n\n";
    result+="▶     "+data->Itms.Itm[itemPointer].Name+"\n";
    itemPics[0]->changePic(data->getItemKey(data->Itms.Itm[itemPointer].Name));

    int end=itemPointer+7;
    if (end>data->Itms.size) end=data->Itms.size;
    int i,count=1;
    for (i=itemPointer+1;i<end;i++)
    {
        itemPics[count]->changePic(data->getItemKey(data->Itms.Itm[i].Name));
        result+="      "+data->Itms.Itm[i].Name+"\n";
        count++;
    };
    for (i=count;i<7;i++)
    {
        itemPics[i]->EmptyPic();
    };

    for (i=1;i<=8-count;i++)
    {
        result+="\n";
    };
    int itemKey=data->getItemKey(data->Itms.Itm[itemPointer].Name);
    if (itemKey!=-1)
    {
        result+="▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁\n";
        result+="Name: "+data->Itms.Itm[itemKey].Name;
        if (data->Itms.Itm[itemKey].Charges !=-1)
            result+=" ("+QString::number(data->Itms.Itm[itemKey].Charges)+")\n";
        else result+="\n";
        result+="Value: "+QString::number(data->Itms.Itm[itemKey].Value)+"\n\n";
        QString description=data->Itms.Itm[itemKey].description.replace("*","\n");
        result+="Description: "+description+"\n";
        data->Itms.Itm[itemKey].description.replace("\n","*");
    };
    mapInfo->setPlainText(result);

}

void UI::updateCharacterInfo(int character)
{
    QString result="";
    result+= "Name:  "+data->P.Chars[character].Name+"\n";
    result+= "Level: "+QString::number(data->P.Chars[character].Level)+"\n";
    int maxLife=data->Clsses.Clss[data->P.Chars[character].ClassId].BaseLife+data->P.Chars[character].Level;
    result+= "Life:  "+QString::number(data->P.Chars[character].Life)+"/"+QString::number(maxLife)+"\n";
    result+= "Clues: "+QString::number(data->P.Chars[character].Clues)+"\n";
    result+= "\n";
    result+= "M.Hand: "+data->P.Chars[character].MainHand+"\n";
    result+= "O.Hand: "+data->P.Chars[character].OffHand+"\n";
    result+= "Armor:  "+data->P.Chars[character].Armor+"\n";
    characterInfo->setPlainText(result);
}

void UI::updatePartyQuickInfo()
{
    QString result="";
    int i;
    for (i=0;i<data->P.partysize;i++)
    {
        result+=data->P.Chars[i].Name+": \n\n";
    };
    for (i=0;i<4;i++)
    {
        if (data->P.Chars[i].Life<=0 || data->P.Chars[i].isFlee==1) characterPics[i]->setPixmap(QPixmap(""));
        else characterPics[i]->changePic(data->P.Chars[i].ClassId,"");
    }
    result+="Gold: "+QString::number(data->P.totalGold);
    partyQuickInfo->setPlainText(result);
    for (i=0;i<4;i++)
    {
        if (data->P.Chars[i].Life<=0)
        {
            characterHealthBars[i]->setPixmap(QPixmap(""));
            scene()->removeItem(characterHealthBars[i]->health);
        }
        else
        {
            int maxLife=data->Clsses.Clss[data->P.Chars[i].ClassId].BaseLife+data->P.Chars[i].Level;
            characterHealthBars[i]->setHealth(data->P.Chars[i].Life,maxLife);
        }
    }
}

void UI::updateMonsterEventInfo()
{
    QString monsterName = data->O.Obj[data->M.EventTileKey].name;
    QString text = "You have encounter "+monsterName+".\n- Press X to fight.\n- Press Z to let them act first.";
    eventInfo->setPlainText(text);
    gamePhase="MonsterEncounter";
}

void UI::updateActionInfo()
{
    QString result="\n\n";
    if (actionPointer==0)
    {
        result+="                ▶ ATTACK\n                  ITEMS\n                  FLEE\n";
    };
    if (actionPointer==1)
    {
        result+="                  ATTACK\n                ▶ ITEMS\n                  FLEE\n";
    };
    if (actionPointer==2)
    {
        result+="                  ATTACK\n                  ITEMS\n                ▶ FLEE\n";
    };
    result+="\n\n▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁\n";
    if (monsterInfoPointer==0)
    {
        result+="Name: "+data->battleMonster.name+"\n";
        result+="Level: "+QString::number(data->battleMonster.level)+"\n";
        result+="Treasure: "+QString::number(data->battleMonster.treasureAmount)+"\n\n";
        result+="Weakness: "+data->battleMonster.weakness+"\n";
        QString ability =data->battleMonster.ability.replace("*","\n");
        result+="Ability: "+ability+"\n";
        data->battleMonster.ability.replace("\n","*");
    }
    else
    {
        result+= "Name:  "+data->P.Chars[battlePointer].Name+"\n";
        result+= "Level: "+QString::number(data->P.Chars[battlePointer].Level)+"\n";
        int maxLife=data->Clsses.Clss[data->P.Chars[battlePointer].ClassId].BaseLife+data->P.Chars[battlePointer].Level;
        result+= "Life:  "+QString::number(data->P.Chars[battlePointer].Life)+"/"+QString::number(maxLife)+"\n";
        result+= "\n";
        result+= "M.Hand: "+data->P.Chars[battlePointer].MainHand+"\n";
        result+= "O.Hand: "+data->P.Chars[battlePointer].OffHand+"\n";
        result+= "Armor:  "+data->P.Chars[battlePointer].Armor+"\n";
    }
    result+="▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁";

    mapInfo->setPlainText(result);

}

void UI::updateManagementInfo()
{
    QString result="";
    if (managePointer==0) result="▶ SWAP\n  ITEMS\n  LEVEL UP";
    if (managePointer==1) result="  SWAP\n▶ ITEMS\n  LEVEL UP";
    if (managePointer==2) result="  SWAP\n  ITEMS\n▶ LEVEL UP";
    result+=" ("+QString::number(data->P.xpRolls)+")\n";
    eventInfo->setPlainText(result);
}

void UI::updateItemManagementInfo(int characterid)
{
    QString result;
    result+=QString::number(itemPointer+1)+"/"+QString::number(data->P.Chars[characterid].ItemsSize)+"\n\n";
    result+="▶     "+data->P.Chars[characterid].Items[itemPointer]+"\n";
    itemPics[0]->changePic(data->getItemKey(data->P.Chars[characterid].Items[itemPointer]));

    int end=itemPointer+7;
    if (end>data->P.Chars[characterid].ItemsSize) end=data->P.Chars[characterid].ItemsSize;
    int i,count=1;
    for (i=itemPointer+1;i<end;i++)
    {
        itemPics[count]->changePic(data->getItemKey(data->P.Chars[characterid].Items[i]));
        result+="      "+data->P.Chars[characterid].Items[i]+"\n";
        count++;
    };
    for (i=count;i<7;i++)
    {
        itemPics[i]->EmptyPic();
    };

    for (i=1;i<=8-count;i++)
    {
        result+="\n";
    };
    int itemKey=data->getItemKey(data->P.Chars[characterid].Items[itemPointer]);
    if (itemKey!=-1)
    {
        result+="▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁\n";
        result+="Name: "+data->Itms.Itm[itemKey].Name;
        if (data->P.Chars[characterid].ItemCharges[itemPointer]!=-1)
            result+=" ("+QString::number(data->P.Chars[characterid].ItemCharges[itemPointer])+")\n";
        else result+="\n";
        result+="Value: "+QString::number(data->Itms.Itm[itemKey].Value)+"\n\n";
        QString description=data->Itms.Itm[itemKey].description.replace("*","\n");
        result+="Description: "+description+"\n";
        data->Itms.Itm[itemKey].description.replace("\n","*");
    };
    mapInfo->setPlainText(result);
}

void UI::updateAffectItemInfo()
{
    QString result="";
    if (affectItemPointer==0) result="▶ USE\n  TRANSFER\n";
    if (affectItemPointer==1) result="  USE\n▶ TRANSFER\n";
    eventInfo->setPlainText(result);
}

void UI::buyAction()
{
    if (data->buyItem(battlePointer,data->Itms.Itm[itemPointer].Name)==0) {
        eventInfo->setPlainText(QString("You dont have enough golds to buy this item."));
        delay(1);
        eventInfo->setPlainText(QString("press Z to complete current character's purchase\nand go to the next character."));
    };
}

void UI::nextBuyer()
{
    characterPicProxy[battlePointer]->setPos(characterPics[battlePointer]->x,characterPics[battlePointer]->y+20);
    battlePointer+=1;
    itemPointer=0;
    if (battlePointer>=data->P.partysize)
    {
        endShop();
    }
    else
    {
        characterPicProxy[battlePointer]->setPos(characterPics[battlePointer]->x,characterPics[battlePointer]->y-20);
        updateShopInfo();
    };
}



void UI::levelupAction()
{
    gamePhase="NO";
    eventInfo->setPlainText(data->characterLevelUp(characterPointer));
    infobox->EmptyBox();
    updateCharacterInfo(characterPointer);
    eventInfo->setPos(eventInfo->x()-150,eventInfo->y());
    delay(2);
    eventInfo->setPos(eventInfo->x()+150,eventInfo->y());
    updateManagementInfo();
    gamePhase="ManageCharacter";
}

void UI::attackAction()
{
    gamePhase="NO";
    QString result=data->characterAttack(battlePointer);
    battleEffect->attackEffect(data->P.Chars[battlePointer].ClassId);
    attackSound();
    scene()->removeItem(characterPicProxy[battlePointer]);
    delay(1.3);

    scene()->addItem(characterPicProxy[battlePointer]);
    if (result=="miss")
    {
        battleEffect->missEffect();
        delay(1);
    }
    else
    {
        scene()->addItem(hitFlashProxy);
        hitFlash->changePic("flash");
        hitSound();
        delay(0.1);
        scene()->removeItem(hitFlashProxy);
    }
    actionPointer=0;
    characterPicProxy[battlePointer]->setPos(characterPics[battlePointer]->x,characterPics[battlePointer]->y+20);

    QString t="";
    if (data->battleMonster.amountDice>=0) t="AMOUNT: "+QString::number(data->battleMonster.amount);
    else t="HEATH: "+QString::number(data->battleMonster.amount);
    monsterLife->setHtml("<div style='background-color:#666666;'>" + t + "</div>");

    if (data->battleMonster.amount<=0)
    {
        // add win music
        endBattle("won");
        return;
    };
    nextBattleCharacter();
    if (data->isallDeadCharacters()==1) {
        endBattle("lose");
        return;
    }
    if (data->isAllFled()==1)
    {
        endBattle("flee");
        return;
    };
    characterPicProxy[battlePointer]->setPos(characterPics[battlePointer]->x,characterPics[battlePointer]->y-20);
    updateActionInfo();
    gamePhase="Battle";
}

void UI::shotAction()
{
    gamePhase="NO";
    int i;
    for (i=0;i<data->P.partysize;i++)
    {
        if (data->isCharacterEquip("Bow",i) || data->isCharacterEquip("Sling",i))
        {
            delay(1);
            QString result=data->characterShot(i);

            characterPicProxy[i]->setPos(characterPics[i]->x,characterPics[i]->y-20);
            QString t="";
            if (data->battleMonster.amountDice>=0) t="AMOUNT: "+QString::number(data->battleMonster.amount);
            else t="HEATH: "+QString::number(data->battleMonster.amount);
            monsterLife->setHtml("<div style='background-color:#666666;'>" + t + "</div>");
            battleEffect->shotEffect();
            shotSound();
            delay(1);
            if (result=="miss")
            {
                battleEffect->missEffect();
                delay(1);
            }
            else
            {
                scene()->addItem(hitFlashProxy);
                hitFlash->changePic("flash");
                hitSound();
                delay(0.1);
                scene()->removeItem(hitFlashProxy);
            }
            characterPicProxy[i]->setPos(characterPics[i]->x,characterPics[i]->y+20);
        };
    };

    if (data->battleMonster.amount<=0)
    {
        endBattle("won");
        return;
    };

    gamePhase="Battle";
}

void UI::fleeAction()
{
    gamePhase="NO";
    QString result=data->characterFlee(battlePointer);
    if (result=="THE CHARACTER HAS ESCAPED SUCCESSFULLY.")
    {
        characterPics[battlePointer]->setPixmap(QPixmap(""));
    };
    eventInfo->setPlainText(result);
    actionPointer=0;
    delay(1.2);
    eventInfo->setPlainText(QString(""));
    characterPicProxy[battlePointer]->setPos(characterPics[battlePointer]->x,characterPics[battlePointer]->y+20);
    if (data->isAllFled()==1)
    {
        endBattle("flee");
        return;
    };
    nextBattleCharacter();
    if (data->isAllFled()==1)
    {
        endBattle("flee");
        return;
    };
    characterPicProxy[battlePointer]->setPos(characterPics[battlePointer]->x,characterPics[battlePointer]->y-20);
    updateActionInfo();
    gamePhase="Battle";
}

void UI::useItemAction()
{
    QString result=data->characterUseItem(itemPointer,characterPointer,gamePhase);

    if (result=="CHOOSE ONE CHARACTER TO HEAL.\n")
    {
        gamePhase="HealCharacter";
        eventInfo->setPos(eventInfo->x()-150,eventInfo->y());
        eventInfo->setPlainText(result);
        startBlessHealCharacter();
    }
    else if (result=="CHOOSE ONE CHARACTER TO BLESS.\n")
    {
        gamePhase="BlessCharacter";
        eventInfo->setPos(eventInfo->x()-150,eventInfo->y());
        eventInfo->setPlainText(result);
        startBlessHealCharacter();
    }
    else
    {
        gamePhase="NO";
        eventInfo->setPos(eventInfo->x()-150,eventInfo->y());
        eventInfo->setPlainText(result);
        delay(2);
        eventInfo->setPos(eventInfo->x()+150,eventInfo->y());
        scene()->removeItem(eventInfo);
        itemPointer=0;
        gamePhase="ManageItems";
        updateItemManagementInfo(characterPointer);
    }
}

void UI::useItemInBattleAction()
{
    int isFlee=0;
    QString item=data->P.Chars[battlePointer].Items[itemPointer];
    if (item=="") return;

    if (item=="Ring of Teleportation")
    {
       isFlee=1;
       teleportringSound();
       monsterEffect->teleportringEffect(battlePointer);
       delay(1.1);
    };

    QString result=data->characterUseItem(itemPointer,battlePointer,gamePhase);
    gamePhase="NO";
    if (result=="hit" || result=="miss")
    {
        if (item=="Holy Water Vial")
        {
            holywaterSound();
            battleEffect->holywaterEffect();
        };
        if (item=="Fireball Spell" || item=="Fireball Staff")
        {
            fireballSound();
            battleEffect->fireballEffect();
        };
        if (item=="Lightning Bolt Spell")
        {
            lightningboltSound();
            battleEffect->lightningboltEffect();
        };
        if (item=="Sleeping Spell" || item=="Wand of Sleep")
        {
            sleepingSound();
            battleEffect->sleepingEffect();
        };
        if (item=="Protecting Spell")
        {
            protectingSound();
            battleEffect->protectingEffect();
        };
    }
    if (result!="hit" && result!="miss") eventInfo->setPlainText(result);
    updatePartyQuickInfo();
    if (item=="Escaping Spell")
    {
        if (result=="hit" || result=="miss")
        {
            escapingSound();
            monsterEffect->escapingEffect(battlePointer);
        };
        if (result=="hit")
        {
            isFlee=1;
        };
        delay(1.1);
        if (result=="miss")
        {
            monsterEffect->missMonsterEffect(battlePointer);
            delay(1);
        };
    }
    else
    {
        delay(1.1);
        if (result=="miss")
        {
            battleEffect->missEffect();
            delay(1);
        };
        if (result=="hit")
        {
            scene()->addItem(hitFlashProxy);
            hitFlash->changePic("flash");
            hitSound();
            delay(0.1);
            scene()->removeItem(hitFlashProxy);
        };
    };

    eventInfo->setPlainText(QString(""));
    if (isFlee==1)
    {
        data->P.Chars[battlePointer].isFlee=1;
        characterPics[battlePointer]->setPixmap(QPixmap(""));
    };
    if (result=="CAN'T USE THIS ITEM RIGHT NOW.\n" || result=="THIS CHARACTER CAN'T CAST THIS SPELL.\n"
            || result=="THIS CHARACTER CAN'T CAST SPELLS WHEN USING SHIELD OR HEAVY ARMOR.\n")
    {
        gamePhase="UseItemInBattle";
        return;
    }
    actionPointer=0;
    endUseItemInBattle();

    characterPicProxy[battlePointer]->setPos(characterPics[battlePointer]->x,characterPics[battlePointer]->y+20);

    QString t="";
    if (data->battleMonster.amountDice>=0) t="AMOUNT: "+QString::number(data->battleMonster.amount);
    else t="HEATH: "+QString::number(data->battleMonster.amount);
    monsterLife->setHtml("<div style='background-color:#666666;'>" + t + "</div>");

    if (data->isAllFled()==1)
    {
        endBattle("flee");
        return;
    };
    if (data->battleMonster.amount<=0)
    {
        endBattle("won");
        return;
    };
    nextBattleCharacter();
    if (data->isAllFled()==1)
    {
        endBattle("flee");
        return;
    };
    characterPicProxy[battlePointer]->setPos(characterPics[battlePointer]->x,characterPics[battlePointer]->y-20);
    updateActionInfo();
    gamePhase="Battle";
}


void UI::nextBattleCharacter()
{
    battlePointer+=1;

    if (battlePointer==data->P.partysize)
    {
        monsterAttackPhase();
        return;
    };
    while(data->P.Chars[battlePointer].isFlee==1)
    {
        battlePointer+=1;
        if (battlePointer==data->P.partysize)
        {
            monsterAttackPhase();
            return;
        };
    };
}

void UI::monsterAttackPhase()
{
    gamePhase="NO";
    if (data->monsterRegenerate())
    {
        QString t="";
        if (data->battleMonster.amountDice>=0) t="AMOUNT: "+QString::number(data->battleMonster.amount);
        else t="HEATH: "+QString::number(data->battleMonster.amount);
        monsterLife->setHtml("<div style='background-color:#666666;'>" + t + "</div>");
    };
    scene()->removeItem(monsterPicProxy);
    monsterPic->changePic(data->battleMonster.name,"move");
    monsterPicProxy->setPos(monsterPicProxy->x(),monsterPicProxy->y()+70);
    delay(0.5);
    scene()->addItem(monsterPicProxy);
    delay(0.5);

    int monsterBreathFire=data->monsterBreathFire();
    int isCatoblepas = 0;
    if (data->battleMonster.name=="Catoblepas-FirstAttack")
    {
        isCatoblepas=1;
        data->battleMonster.name="Catoblepas";
    };

    if (monsterBreathFire || isCatoblepas)
    {
        int i;
        for (i=0;i<data->P.partysize;i++)
        {
            if (data->P.Chars[i].isFlee!=1)
            {
                if (monsterBreathFire)
                {
                    lightningboltSound();
                    monsterEffect->monsterFireAttackEffect(i);
                }
                else if (isCatoblepas)
                {
                    fireballSound();
                    monsterEffect->monsterLightningAttackEffect(i);
                }

                QString result=data->monsterSpecialAttack(4,i);
                if (result=="miss")
                {
                    delay(1.2);
                    monsterEffect->missMonsterEffect(i);
                }
                else
                {
                    delay(1);
                    hitSound();
                    characterPics[i]->changePic(data->P.Chars[i].ClassId,"hit");
                    if (data->removeDeadCharacters())
                    {
                        delay(0.5);
                        int j;
                        for (j=0;j<4;j++)
                        {
                            classids[j]=data->P.Chars[j].ClassId;
                        };
                        i-=1;
                    };
                };
                delay(1.2);
            };
            updatePartyQuickInfo();
        };
        battlePointer=-1;
        nextBattleCharacter();
        scene()->removeItem(monsterPicProxy);
        monsterPic->changePic(data->battleMonster.name,"");
        monsterPicProxy->setPos(monsterPicProxy->x(),monsterPicProxy->y()-10);
        delay(0.5);
        scene()->addItem(monsterPicProxy);
        delay(0.5);
        return;
    };


    int i;
    int times= data->battleMonster.amount;
    if (data->battleMonster.amountDice<0) times=data->max(data->battleMonster.amount/2,1);
    for (i=0;i<times;i++)
    {
        int modifier=0;
        if (data->P.partysize==1) modifier=6;
        if (data->P.partysize==2) modifier=1.5;
        if (data->P.partysize==3) modifier=0.3;
        float rand=data->intrand(1,9)+0.1*data->intrand(1,10);
        int List[4];
        if (rand<=4+modifier)
        {
            List[0]=0;
            List[1]=1;
            List[2]=2;
            List[3]=3;
        }
        else if (rand<=7+modifier)
        {
            List[0]=1;
            List[1]=0;
            List[2]=2;
            List[3]=3;
        }
        else if (rand<=9+modifier)
        {
            List[0]=2;
            List[1]=0;
            List[2]=1;
            List[3]=3;
        }
        else
        {
            List[0]=3;
            List[1]=0;
            List[2]=1;
            List[3]=2;
        };
        int j;
        for (j=0;j<4;j++)
        {
            if (data->P.Chars[List[j]].isFlee==0 && data->P.Chars[List[j]].Life>0)
            {
                QString result=data->monsterAttack(List[j]);
                monsterEffect->monsterAttackEffect(List[j]);
                attackSound();
                if (result=="miss")
                {
                    delay(1);
                    monsterEffect->missMonsterEffect(List[j]);
                }
                else
                {
                    delay(0.8);
                    hitSound();
                    characterPics[List[j]]->changePic(data->P.Chars[List[j]].ClassId,"hit");
                    if (data->removeDeadCharacters())
                    {
                        int i;
                        for (i=0;i<4;i++)
                        {
                            classids[i]=data->P.Chars[i].ClassId;
                        };
                        delay(0.5);
                    };
                };
                delay(1);
                break;
            };

        };
        updatePartyQuickInfo();
        if (data->isallDeadCharacters()==1)
        {
            return;
        }
        if (data->isAllFled()==1)
        {
            return;
        };
    };

    battlePointer=-1;
    nextBattleCharacter();

    scene()->removeItem(monsterPicProxy);
    monsterPic->changePic(data->battleMonster.name,"");
    monsterPicProxy->setPos(monsterPicProxy->x(),monsterPicProxy->y()-10);
    delay(0.5);
    scene()->addItem(monsterPicProxy);
    delay(0.5);
    gamePhase="Battle";
}

void UI::delay(float second)
{
    QTime dieTime= QTime::currentTime().addMSecs(second*1000);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void UI::navigateSound()
{
    if (navigate->state()== QMediaPlayer::PlayingState) {
        navigate->setPosition(0);
    }
    else if (navigate->state() == QMediaPlayer::StoppedState) {
        navigate->play();
    }
}

void UI::selectSound()
{
    if (select->state()== QMediaPlayer::PlayingState) {
        select->setPosition(0);
    }
    else if (select->state() == QMediaPlayer::StoppedState) {
        select->play();
    }
}

void UI::stepSound()
{
    if (step->state()== QMediaPlayer::PlayingState) {
        step->setPosition(0);
    }
    else if (step->state() == QMediaPlayer::StoppedState) {
        step->play();
    }
}

void UI::healSound()
{
    if (heal->state()== QMediaPlayer::PlayingState) {
        heal->setPosition(0);
    }
    else if (heal->state() == QMediaPlayer::StoppedState) {
        heal->play();
    }
}

void UI::blessSound()
{
    if (bless->state()== QMediaPlayer::PlayingState) {
        bless->setPosition(0);
    }
    else if (bless->state() == QMediaPlayer::StoppedState) {
        bless->play();
    }
}

void UI::attackSound()
{
    if (attack->state()== QMediaPlayer::PlayingState) {
        attack->setPosition(0);
    }
    else if (attack->state() == QMediaPlayer::StoppedState) {
        attack->play();
    }
}

void UI::hitSound()
{
    if (hit->state()== QMediaPlayer::PlayingState) {
        hit->setPosition(0);
    }
    else if (hit->state() == QMediaPlayer::StoppedState) {
        hit->play();
    }
}

void UI::useSound()
{
    if (use->state()== QMediaPlayer::PlayingState) {
        use->setPosition(0);
    }
    else if (use->state() == QMediaPlayer::StoppedState) {
        use->play();
    }
}

void UI::shotSound()
{
    if (shot->state()== QMediaPlayer::PlayingState) {
        shot->setPosition(0);
    }
    else if (shot->state() == QMediaPlayer::StoppedState) {
        shot->play();
    }
}

void UI::escapingSound()
{
    if (escaping->state()== QMediaPlayer::PlayingState) {
        escaping->setPosition(0);
    }
    else if (escaping->state() == QMediaPlayer::StoppedState) {
        escaping->play();
    }
}

void UI::fireballSound()
{
    if (fireball->state()== QMediaPlayer::PlayingState) {
        fireball->setPosition(0);
    }
    else if (fireball->state() == QMediaPlayer::StoppedState) {
        fireball->play();
    }
}

void UI::holywaterSound()
{
    if (holywater->state()== QMediaPlayer::PlayingState) {
        holywater->setPosition(0);
    }
    else if (holywater->state() == QMediaPlayer::StoppedState) {
        holywater->play();
    }
}

void UI::lightningboltSound()
{
    if (lightningbolt->state()== QMediaPlayer::PlayingState) {
        lightningbolt->setPosition(0);
    }
    else if (lightningbolt->state() == QMediaPlayer::StoppedState) {
        lightningbolt->play();
    }
}

void UI::protectingSound()
{
    if (protecting->state()== QMediaPlayer::PlayingState) {
        protecting->setPosition(0);
    }
    else if (protecting->state() == QMediaPlayer::StoppedState) {
        protecting->play();
    }
}

void UI::sleepingSound()
{
    if (sleeping->state()== QMediaPlayer::PlayingState) {
        sleeping->setPosition(0);
    }
    else if (sleeping->state() == QMediaPlayer::StoppedState) {
        sleeping->play();
    }
}

void UI::teleportringSound()
{
    if (teleportring->state()== QMediaPlayer::PlayingState) {
        teleportring->setPosition(0);
    }
    else if (teleportring->state() == QMediaPlayer::StoppedState) {
        teleportring->play();
    }
}

void UI::dungeonMusic()
{
    QMediaPlaylist *playlist = new QMediaPlaylist();
    QString a = QFileInfo("sounds/dungeonMusic.mp3").absoluteFilePath();
    playlist->addMedia(QUrl::fromLocalFile(a));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    music->setPlaylist(playlist);
    music->play();
}

void UI::battleMusic()
{
    QMediaPlaylist *playlist = new QMediaPlaylist();
    QString a = QFileInfo("sounds/battleMusic.mp3").absoluteFilePath();
    playlist->addMedia(QUrl::fromLocalFile(a));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    music->setPlaylist(playlist);
    music->play();

}




