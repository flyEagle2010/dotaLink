//
//  BattleMap.h
//  dotaLink
//
//  Created by 秦亮亮 on 14-6-30.
//
//

#ifndef __dotaLink__BattleMap__
#define __dotaLink__BattleMap__

#include <iostream>
#include "cocos2d.h"
#include "Manager.h"
#include "Hero.h"
#include "MNpc.h"
#include "Npc.h"
#include "BNpc.h"
#include "MNpc.h"
#include "Team.h"
USING_NS_CC;

class MNpc;

class BattleMap:public Node{
public:
    CREATE_FUNC(BattleMap);
    
    static Scene* createScene();

	virtual void onEnter();
	virtual void onExit();
	virtual bool init();
    
    void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    
    bool isblock(Vec2 pos);
    //type:1 npc 2 hero
    Vector<BNpc*> getTargets(int xID,BNpc* attacker);
    
    void sortDepth();
public:
    Team* team;

private:
    void createHero(int type); //1hero 2monster
    void update(float dt);
    void pickUp();
    void setViewPointCenter(cocos2d::Point position);
    Vec2 tileCoordForPosition(Vec2 position);
private:
	cocos2d::TMXTiledMap *tileMap;
	cocos2d::TMXLayer *background;
	Hero *player;
    Hero* player2;
    TMXLayer *foreground;
    TMXLayer* coverLayer;
    TMXLayer* blockLayer;
    
    Vector<BNpc*> npcs;
};
#endif /* defined(__dotaLink__BattleMap__) */
