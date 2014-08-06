//
//  HomeScene.h
//  fancyHeart
//
//  Created by 秦亮亮 on 14-5-12.
//
//

#ifndef __fancyHeart__HomeScene__
#define __fancyHeart__HomeScene__

#include <iostream>
#include "cocos2d.h"
#include "Manager.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "CircleMove.h"
#include <map>
USING_NS_CC;
using namespace ui;
using namespace cocostudio;

class HomeScene:public BaseUI{
public:
	static Scene* createScene();
    static HomeScene* create();
    virtual void onEnter();
    virtual void onExit();
	virtual bool init(std::string fileName,bool isScence=false);

private:
    float buildScale=1;
    void initNetEvent();
    void touchBuildEvent(Ref *pSender, TouchEventType type);
};

#endif /* defined(__fancyHeart__HomeScene__) */
