//
//  Buff.cpp
//  dotaLink
//
//  Created by 秦亮亮 on 14-7-3.
//
//

#include "Buff.h"
Buff* Buff::create(int buffID)
{
    Buff* pRet=new Buff();
    if(pRet)
    {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool Buff::init(int buffID)
{
    if (buffID <= 0 ) {
        return false;
    }
    this->setBuffID(buffID);
    
    XBuff* xb=XBuff::record(Value(buffID));
    float duration=xb->getDuration()/1000.0;
    Director::getInstance()->getScheduler()->schedule(SEL_SCHEDULE(&Buff::finish),this,duration,false);
    return true;
}

void Buff::start()
{
    //属性修正
    XBuff* xb=XBuff::record(Value(buffID));
//    this->mf->data->addBuff(this);
    /*
    if(xb->getDps()>0)
    {
        Director::getInstance()->getScheduler()->schedule(SEL_SCHEDULE(&Buff::dps),this,1,false);
    }
    */
}

void Buff::finish()
{
//    this->mf->clearBuff(this);
}

void Buff::dps()
{
    XBuff* xb=XBuff::record(Value(buffID));
//    this->mf->fallHp(xb->getDps());
}

Buff::~Buff()
{
    Director::getInstance()->getScheduler()->unschedule(SEL_SCHEDULE(&Buff::finish),this);
    Director::getInstance()->getScheduler()->unschedule(SEL_SCHEDULE(&Buff::dps), this);
}