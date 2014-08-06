//
//  MNpc.h
//  dotaLink
//
//  Created by 秦亮亮 on 14-7-3.
//
//

#ifndef __dotaLink__MNpc__
#define __dotaLink__MNpc__

#include <iostream>
#include "cocos2d.h"
#include "Skill.h"
#include "Buff.h"
#include "BNpc.h"
using namespace cocos2d;


#define HERO_SKILL_COLDDOWN "skill_colddown"
class Skill;
enum fstate{
    idle, //空闲
    start, //开始攻击
    spell, //吟唱
    buildup, //蓄力
    throwing, //仍东西
    cast,  //正式攻击
    die //死亡
};
class MNpc:public Ref
{
public:
    static MNpc* create(BNpc* view);
    virtual bool init(BNpc* view);
    bool init();
    void attack();
    
public:
    BNpc* view;
    fstate state;
    Vector<Skill*> skills;
    Vector<Buff*> buffs;
    
private:
    void initSkill();
    Skill* selectSkill();
    
};
#endif /* defined(__dotaLink__MNpc__) */
