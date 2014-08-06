//
//  HeroUnit.h
//  dotaLink
//
//  Created by 秦亮亮 on 14-7-3.
//
//

#ifndef __dotaLink__HeroUnit__
#define __dotaLink__HeroUnit__

#include <iostream>
#include "cocos2d.h"
#include "BNpc.h"

class Hero:public BNpc
{
    CC_SYNTHESIZE(bool, isLead, IsLead);
public:
    static Hero* create(int xid);
    virtual bool init(int xid);
    virtual void update(float dt);
    virtual void run();
    void follow(Hero* hero);

public:
    Hero* preHero;
//    Vec2 prePos;
    std::vector<Vec3> positiones;

private:
};
#endif /* defined(__dotaLink__HeroUnit__) */
