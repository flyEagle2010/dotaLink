//
//  Skill.cpp
//  dotaLink
//
//  Created by 秦亮亮 on 14-7-3.
//
//

#include "Skill.h"
class BattleMap;

Skill* Skill::create(int skillID)
{
    Skill* pRet=new Skill();
    if(pRet && pRet->init(skillID))
    {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool Skill::init(int skillID)
{
    this->skillID=skillID;
    XSkill* xskill=XSkill::record(Value(skillID));
    Director::getInstance()->getScheduler()->schedule(SEL_SCHEDULE(&Skill::coldDown),this,xskill->getCd(),false);
    return true;
}

void Skill::start()
{
    /*
    this->xSkill=XSkill::record(Value(skillID));
    if(xSkill->getRange()==300){
        
    }
    if(xSkill->getRange()==400){
        
    }
    XRange* xr=XRange::record(Value(xSkill->getRange()));
    std::string str=xr->getRange();
    std::vector<std::string> vector=Utils::split(str, ";");
    std::vector<Vec2> points;
    for(std::string str : vector){
        points.push_back(PointFromString(str));
    }
    this->targets=Manager::getInstance()->bmap->getTargets(points);
    */
    
//    this->targets=Manager::getInstance()->bmap->getTarget(attacker);
//    int rangeType=xr->getRangeType();
    /*
    for(MHero* mh : targets)
    {
        int arrowNum=xSkill->getRangeParam2();
        //带弹道的
        if(arrowNum>0 && attacker->state==fstate::throwing)
        {
            this->shoot(mh);
            continue;
        }
        this->hit(mh);
    }
    */

}

void Skill::selectTarget()
{
    XSkill* xskill=XSkill::record(Value(skillID));
    switch (xskill->getRange()) {
        case 300: //self
            this->targets.pushBack(this->npc);
            break;
        case 400: //team
            this->targets=Manager::getInstance()->bmap->team->items;
            break;
        case 500: //none
            break;
        default:  //other
            this->targets=Manager::getInstance()->bmap->getTargets(xskill->getRange(), this->npc);
            break;
    }
}

void Skill::coldDown()
{
    this->setIsReady(true);
    //主动技能通知UI现实可操作
    XSkill* xSkill=XSkill::record(Value(skillID));
    if(xSkill->getType()==0){
        Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(HERO_SKILL_COLDDOWN);
    }
    this->npc->attack();
}

void Skill::shoot(MNpc* mh)
{
//    this->npc->state=fstate::throwing;
    Director::getInstance()->getScheduler()->schedule(SEL_SCHEDULE(&Skill::hit), this, 1,0,2, false);
    //int arrowType=XSkill::record(Value(skillID))->getArrowType();
    //this->attacker->shoot(mh,arrowType);
}

void Skill::hit(MNpc* mh)
{
    
}

Skill::~Skill()
{
    Director::getInstance()->getScheduler()->unschedule(SEL_SCHEDULE(&Skill::coldDown),this);
}