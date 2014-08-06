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
class Team;

class BattleMap:public Node{
public:
    CREATE_FUNC(BattleMap);
    
    static Scene* createScene();

	virtual void onEnter();
	virtual void onExit();
	virtual bool init();
    
    void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    
    bool isblock(Vec2 pos);
    
    Vector<MNpc*> getTargets(std::vector<Vec2> arr,int type);
public:

private:
    void createHero(int type); //1hero 2monster
    void repositionHero();
    void update(float dt);
    void pickUp();
    void setViewPointCenter(cocos2d::Point position);
	void setPlayerPosition(cocos2d::Point position);
    Vec2 tileCoordForPosition(Vec2 position);
private:
	cocos2d::TMXTiledMap *tileMap;
	cocos2d::TMXLayer *background;
//	Hero *player;
//    Hero* player2;
    
    TMXLayer *foreground;
    TMXLayer* coverLayer;
    TMXLayer* blockLayer;
    
    Vector<MNpc*> team;
    
    Vector<MNpc*> npcs;
    Team* heroTeam;
};
#endif /* defined(__dotaLink__BattleMap__) */