//
//  MNpc.cpp
//  dotaLink
//
//  Created by 秦亮亮 on 14-7-3.
//
//

#include "MNpc.h"

MNpc* MNpc::create(BNpc* view)
{
    MNpc* pRet=new MNpc();
    if(pRet && pRet->init(view))
    {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool MNpc::init(BNpc* view)
{
    this->initSkill();
    return true;
}

void MNpc::initSkill()
{
    std::vector<int> skills={10101,10201,10301,10401,10501,10601,10701,10801,10901,11001,11101,11201,20101,20201,20301,20401,20501,30101,30201,30301,30401,30501,30601,30701,30801};
    for(int i=0;i<2;i++){
        int skillID=skills[rand()%skills.size()];
        Skill* skill=Skill::create(skillID);
        skill->npc=this;
        this->skills.pushBack(skill);
    }
}

void MNpc::attack()
{
    Skill* pSkill=this->selectSkill();
    pSkill->start();
}

Skill* MNpc::selectSkill()
{
    return this->skills.at(0);
//    Skill* pSkill=nullptr;
//    for(Skill* skill : this->skills){
//        if(!skill->getIsReady()) continue;
//    }
//    return pSkill;
}