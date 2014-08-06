//
//  Team.cpp
//  dotaLink
//
//  Created by 秦亮亮 on 14-8-5.
//
//

#include "Team.h"
Team* Team::create(Hero *hero)
{
    Team* pRet=new Team();
    if(pRet && pRet->init(hero)){
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool Team::init(Hero *hero)
{
    this->items.pushBack(hero);
    hero->run();
    return true;
}

Hero* Team::getLeader()
{
    if(this->items.size()>0){
        return (Hero*)this->items.at(0);
    }
    return nullptr;
}

void Team::addMember(Hero *hero)
{
    hero->preHero=(Hero*)this->items.at(items.size()-1);
    this->items.pushBack(hero);
    hero->setDir(items.at(0)->getDir());
    hero->run();
}