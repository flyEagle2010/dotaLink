//
//  Team2.h
//  dotaLink
//
//  Created by 秦亮亮 on 14-8-5.
//
//

#ifndef __dotaLink__Team2__
#define __dotaLink__Team2__

#include <iostream>
#include "cocos2d.h"
//#include "MNpc.h"
#include "Hero.h"
using namespace cocos2d;

class Team2:public Ref
{
public:
    static Team2* create(Hero* hero);
    bool init(Hero* hero);
    Hero* getLeader();
    void addMember(Hero* hero);
public:
    Vector<BNpc*> items;
};
#endif /* defined(__dotaLink__Team2__) */
