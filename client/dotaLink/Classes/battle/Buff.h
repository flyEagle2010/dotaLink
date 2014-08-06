//
//  Buff.h
//  dotaLink
//
//  Created by 秦亮亮 on 14-7-3.
//
//

#ifndef __dotaLink__Buff__
#define __dotaLink__Buff__

#include <iostream>
#include "cocos2d.h"
#include "XBuff.h"

using namespace cocos2d;

class Buff:public Ref
{
    CC_SYNTHESIZE(int, buffID, BuffID);
public:
    ~Buff();
    static Buff* create(int buffID);
    bool init(int buffID);
    void start();
    
    void atkBreak();
    
    bool canSkill();
    bool canHeal();
    bool isMatkMiss();
    bool isAtkMiss();
    int getGroupID();
    int getLv();
private:
    void finish();
    void dps();
};

#endif /* defined(__dotaLink__Buff__) */
