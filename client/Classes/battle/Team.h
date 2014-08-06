//
//  Team.h
//  dotaLink
//
//  Created by 秦亮亮 on 14-7-1.
//
//

#ifndef __dotaLink__Team__
#define __dotaLink__Team__

#include <iostream>
#include "cocos2d.h"
#include "Manager.h"
#include "Hero.h"
using namespace cocos2d;
using namespace ui;
using namespace cocostudio;

#define GAP 50

class Team:public Node {
    
public:
    Vector<Hero*> items;
    static Team* create(Hero* hero);
    virtual bool init(Hero* hero);
    void addMember(Hero* hero);
    Vec2 getItemPosition(int pos);
    void setDir(Dir dir);
    Hero* getLeader();
public:
    Hero* leader;
};

#endif /* defined(__dotaLink__Team__) */
