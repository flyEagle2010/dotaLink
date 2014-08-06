//
//  Npc.cpp
//  dotaLink
//
//  Created by 秦亮亮 on 14-7-3.
//
//

#include "Npc.h"
Npc* Npc::create(int xid)
{
    Npc* pRet=new Npc();
    if(pRet && pRet->init(xid)){
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return pRet;
}
/*
void Npc::run()
{
    Vec2 position=this->getPosition();
    Vec2 toPos;
    
    log("dir:%d",dir);
//    if (position.x >= (150 * 19) ||
//        position.y >= (150 * 17) ||
//        position.y <= 0 ||
//        position.x <= 0)
//    {
//        if(dir==Dir::left)dir=Dir::right;
//        if(dir==Dir::right)dir=Dir::left;
//        if(dir==Dir::top)dir=Dir::bottom;
//        if(dir==Dir::bottom)dir=Dir::top;
//        this->setDir(dir);
//        
//        this->walk();
////        return;
//    }
    if(dir==Dir::left) toPos=Vec2(-150,0);
    if(dir==Dir::right) toPos=Vec2(150,0);
    if(dir==Dir::top) toPos=Vec2(0,150);
    if(dir==Dir::bottom) toPos=Vec2(0,-150);
    Sequence* seq=Sequence::create(MoveBy::create(1,toPos),CallFunc::create(CC_CALLBACK_0(BNpc::run, this)), NULL);
    this->runAction(seq);
    if(!this->sprite->getActionByTag(HERO_WALK)){
        this->walk();
    }
}
*/