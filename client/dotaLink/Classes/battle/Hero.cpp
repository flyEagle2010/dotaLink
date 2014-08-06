//
//  HeroUnit.cpp
//  dotaLink
//
//  Created by 秦亮亮 on 14-7-3.
//
//

#include "Hero.h"
#include "Manager.h"

Hero* Hero::create(int xid)
{
    Hero* pRet=new Hero();
    if(pRet && pRet->init(xid)){
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return pRet;
}

bool Hero::init(int xid)
{
    BNpc::init(xid);
    return true;
}

void Hero::update(float dt)
{
    if(this->isLead){
        BNpc::update(dt);
        Vec3 pos=Vec3(getPositionX(),getPositionY(),this->dir);
        this->positiones.push_back(pos);
    }else{
        if(this->preHero->positiones.size()<20){
            BNpc::update(dt);
        }else{
            Vec3 pos=this->preHero->positiones.at(0);
            this->setPosition(Vec2(pos.x, pos.y));
            if(this->dir!=pos.z){
                this->setDir((Dir)pos.z);
            }
            this->preHero->positiones.erase(preHero->positiones.begin());
        }
    }
}