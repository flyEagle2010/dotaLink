//
//  Npc.h
//  dotaLink
//
//  Created by 秦亮亮 on 14-7-3.
//
//

#ifndef __dotaLink__Npc__
#define __dotaLink__Npc__

#include <iostream>
#include "BNpc.h"

class Npc:public BNpc
{
public:
    static Npc* create(int xid);
//    virtual void run();
};
#endif /* defined(__dotaLink__Npc__) */
