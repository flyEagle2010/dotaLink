//
//  HeroUnit.cpp
//  dotaLink
//
//  Created by 秦亮亮 on 14-7-3.
//
//

#include "Hero.h"

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
    BNpc::update(dt);
    this->positions.push_back(this->getPosition());
    if(this->preHero && this->state==HState::walk){
        this->setPosition(this->preHero->positions.at(0)-Vec2(50,0));
        this->preHero->positions.erase(preHero->positions.begin());
    }
}

void Hero::follow(Hero* hero)
{
    this->preHero=hero;
    this->walk();
}