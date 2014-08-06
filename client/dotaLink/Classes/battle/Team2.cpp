//
//  Team2.cpp
//  dotaLink
//
//  Created by 秦亮亮 on 14-8-5.
//
//

#include "Team2.h"
Team2* Team2::create(Hero *hero)
{
    Team2* pRet=new Team2();
    if(pRet && pRet->init(hero)){
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool Team2::init(Hero *hero)
{
    this->items.pushBack(hero);
    hero->run();
    return true;
}

Hero* Team2::getLeader()
{
    if(this->items.size()>0){
        return (Hero*)this->items.at(0);
    }
    return nullptr;
}

void Team2::addMember(Hero *hero)
{
    hero->preHero=(Hero*)this->items.at(items.size()-1);
    this->items.pushBack(hero);
    hero->setDir(items.at(0)->getDir());
    hero->run();
}