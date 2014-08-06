//
//  Skill.h
//  dotaLink
//
//  Created by 秦亮亮 on 14-7-3.
//
//

#ifndef __dotaLink__Skill__
#define __dotaLink__Skill__

#include <iostream>
#include "cocos2d.h"
#include "XSkill.h"
#include "XRange.h"
#include "Utils.h"
#include "BattleMap.h"
#include "MNpc.h"
using namespace cocos2d;
class MNpc;
class Skill:public Ref
{
    CC_SYNTHESIZE(bool, isReady, IsReady);
public:
    ~Skill();
    static Skill* create(int skillID);
    bool init(int skillID);
    void start();
    void shoot(MNpc* npc);
    void hit(MNpc* npc);
public:
    BNpc* npc;
private:
    void coldDown();
    
private:
    int skillID;
    Vector<BNpc*> targets;
    void selectTarget();
};

#endif /* defined(__dotaLink__Skill__) */
