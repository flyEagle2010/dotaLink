//
//  BNpc.h
//  dotaLink
//
//  Created by 秦亮亮 on 14-7-1.
//
//

#ifndef __dotaLink__BNpc__
#define __dotaLink__BNpc__

#include <iostream>
#include "cocos2d.h"
#include "Utils.h"
//#include "Skill.h"

using namespace cocos2d;
using namespace ui;
//class Skill;


#define SPEED 150.0
#define HERO_STAND 100
#define HERO_WALK 101
#define HERO_ATTACK 102
#define HERO_SKILL_ATTACK 103



enum Dir{
    top=8,
    bottom=2,
    left=4,
    right=6
};

enum HState{
    stand,
    walk,
    attack,
    skillAttack
};


class BNpc:public Node{
public:
    BNpc(){};
    ~BNpc(){};
	virtual void onEnter();
	virtual void onExit();
	virtual bool init(int xid);
    virtual void update(float dt);
    virtual void run();
    void stand();
    void walk();
    void attack();
    void skillAttack();
    void timerAi();

    void invert();
    void setDir(Dir value);
    Dir getDir();
    Vec2 getEndPos();
    
protected:
    Animation* createAnimation(const char* formatStr, int frameCount, int fps);
    void initSkill();
protected:
    int xid;
    Dir dir;
    int skillID;
public:
    int type; //1hero 2npc 3boss
    Sprite* sprite;
    HState state;
};
#endif /* defined(__dotaLink__BNpc__) */
