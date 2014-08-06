//
//  Team.h
//  dotaLink
//
//  Created by 秦亮亮 on 14-8-5.
//
//

#ifndef __dotaLink__Team__
#define __dotaLink__Team__

#include <iostream>
#include "cocos2d.h"
#include "Hero.h"
using namespace cocos2d;

class Team:public Ref
{
public:
    static Team* create(Hero* hero);
    bool init(Hero* hero);
    Hero* getLeader();
    void addMember(Hero* hero);
public:
    Vector<BNpc*> items;
};
#endif /* defined(__dotaLink__Team__) */
