//
//  Manager.h
//  fancyHeart
//
//  Created by 秦亮亮 on 14-5-4.
//
//

#ifndef __fancyHeart__Manager__
#define __fancyHeart__Manager__

#include <iostream>
#include "cocos2d.h"
#include "DeviceInfo.h"
#include "MsgID.h"
#include "BaseUI.h"
#include "BattleMap.h"
using namespace cocos2d;

#define EVENT_RUN "event_run"
#define EVENT_HERO_EVENTER "event_hero_enter"
class BattleMap;

class Manager{
    
public:
    Node* scene;
    BattleMap* bmap;
public:
    static Manager* getInstance();
    
    void switchScence(Scene* scene);
    
private:
    std::map<int, rapidjson::Value> netData;

};

#endif /* defined(__fancyHeart__Manager__) */
