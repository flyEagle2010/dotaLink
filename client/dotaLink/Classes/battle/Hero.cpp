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

void Hero::run()
{
    this->state=HState::walk;
//    this->walk();
    
//    Vec2 endPos=this->getEndPos();
//    if(Manager::getInstance()->bmap && Manager::getInstance()->bmap->isblock(this->getPosition()+endPos)){
//        this->invert();
//        endPos=this->getEndPos();
//    }
//    Sequence* seq=Sequence::create(MoveBy::create(0.6, endPos),CallFunc::create(CC_CALLBACK_0(BNpc::run, this)), NULL);
//    this->runAction(seq);
}

void Hero::follow(Hero* hero)
{
    this->preHero=hero;
    Vec2 pos=hero->getPosition();
    this->unschedule(SEL_SCHEDULE(&BNpc::timerAi));
    
//    RepeatForever* repeat=RepeatForever::create(MoveTo::create(1/30, hero->getPosition()));
//    this->runAction(repeat);
//    this->runAction(MoveTo::create(0.8, pos));
//    this->setDir(hero->dir);
//    if(!this->sprite->getActionByTag(HERO_WALK)){
//        this->walk();
//    }
}