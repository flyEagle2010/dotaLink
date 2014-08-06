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
public:
    static Hero* create(int xid);
    virtual bool init(int xid);
    virtual void update(float dt);
    void follow(Hero* hero);
    std::vector<Vec2> positions;
    Hero* preHero;

private:
    
};
#endif /* defined(__dotaLink__HeroUnit__) */
