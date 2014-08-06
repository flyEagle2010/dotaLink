//
//  Team.cpp
//  dotaLink
//
//  Created by 秦亮亮 on 14-7-1.
//
//

#include "Team.h"
Team* Team::create(Hero* hero)
{
    Team* pRet=new Team();
    if(pRet && pRet->init(hero)){
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool Team::init(Hero* hero)
{
    this->items.pushBack(hero);
    this->addChild(hero);
    
    return true;
}

void Team::addMember(Hero *hero)
{
    hero->preHero=this->items.at(items.size()-1);
    this->items.pushBack(hero);
    this->addChild(hero);
    hero->setDir(items.at(0)->getDir());
    Vec2 position=this->getItemPosition(items.size());
    
    hero->setPosition(position-Vec2(50,0));
//    Sequence* seq=Sequence::create(MoveTo::create(1, position),CallFunc::create(CC_CALLBACK_0(BNpc::run, hero)), NULL);
//    this->runAction(seq);
}

void Team::setDir(Dir dir)
{
    for(Hero* hero : this->items){
        hero->setDir(dir);
    }
}

Hero* Team::getLeader()
{
    if(this->items.size()>0){
        return this->items.at(0);
    }
    return nullptr;
}

Vec2 Team::getItemPosition(int pos)
{
    Hero* leader=this->items.at(0);
    Vec2 position;
    if(leader->getDir()==Dir::left){
        position=leader->getPosition()+Vec2(GAP*pos,0);
    }
    if(leader->getDir()==Dir::right){
        position=leader->getPosition()+Vec2(-GAP*pos,0);
    }
    if(leader->getDir()==Dir::top){
        position=leader->getPosition()+Vec2(0,-GAP*pos);
    }
    if(leader->getDir()==Dir::bottom){
        position=leader->getPosition()+Vec2(0,GAP*pos);
    }
    return position;
}