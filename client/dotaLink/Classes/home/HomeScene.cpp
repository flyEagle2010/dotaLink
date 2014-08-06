//
//  HomeScene.cpp
//  fancyHeart
//
//  Created by 秦亮亮 on 14-5-12.
//
//

#include "HomeScene.h"
Scene* HomeScene::createScene(){
	auto scene = Scene::create();
    auto layer = HomeScene::create();
    scene->addChild(layer);
	return scene;
}
HomeScene* HomeScene::create()
{
    HomeScene* homeScene=new HomeScene();
    if (homeScene && homeScene->init("publish/HomeScene.json",true)) {
        homeScene->autorelease();
        return homeScene;
    }
    CC_SAFE_DELETE(homeScene);
    return nullptr;
}
void HomeScene::onEnter()
{
    BaseUI::onEnter();
}
bool HomeScene::init(std::string fileName,bool isScence){
	if(!BaseUI::init(fileName,isScence)){
		return false;
	}
    Size dSize(1136,640);
    Size size=Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
    float scale=fmin(size.width/dSize.width,size.height/dSize.height);

    std::vector<std::string> buildNames={"img_hecheng","img_tiaozhan","img_hero","img_shichang","img_zhaohuan","img_fuben"};
    ComRender *render = static_cast<ComRender*>(layout->getChildByTag(10003)->getComponent("GUIComponent"));
    Layout *comLayout=static_cast<Layout*>(render->getNode());

   
    auto widget=static_cast<Widget*>(comLayout->getChildByName("home_botom"));
    widget->setPosition(Vec2(size.width/2, 0+widget->getContentSize().height*scale/2));
    widget->setScale(scale);
    
    widget=static_cast<Widget*>(comLayout->getChildByName("home_top"));
    widget->setPosition(Vec2(size.width/2, (size.height-widget->getContentSize().height*scale/2)));
    widget->setScale(scale);
    
    widget=static_cast<Widget*>(comLayout->getChildByName("home_leftop"));
    widget->setPosition(Vec2(widget->getContentSize().width*scale/2, (size.height-widget->getContentSize().height*scale/2)));
    widget->setScale(scale);
    
    widget=static_cast<Widget*>(comLayout->getChildByName("home_right"));
    widget->setPosition(Vec2(size.width-widget->getContentSize().width*scale/2, (size.height-widget->getContentSize().height*scale/2)));
    widget->setScale(scale);
  
    widget=static_cast<Widget*>(comLayout->getChildByName("home_build"));
    widget->setPosition(Vec2((size.width-widget->getContentSize().width*scale)/2, (size.height-widget->getContentSize().height)/2));
    widget->setScale(scale);
    for (std::string name : buildNames) {
        auto image=widget->getChildByName(name);
        image->setTouchEnabled(true);
        image->addTouchEventListener(CC_CALLBACK_2(HomeScene::touchBuildEvent, this));
    }
    
    widget=comLayout->getChildByName("img_cloud");
    lrTuoyuanConfig c;
    
    c.aLength=c.cLength=size.width/2;
    
    c.centerPosition=Vec2(size.width/2, size.height/2);
    widget->runAction(CircleMove::actionWithDuration(10, c));
    
    //layout->addTouchEventListener(CC_CALLBACK_2(HomeScene::touchEvent, this));
    
    srand((int)time(0));

	return true;
}

void HomeScene::touchBuildEvent(cocos2d::Ref *pSender, TouchEventType type)
{
    auto sprite=static_cast<Sprite*>(pSender);
    switch (type) {
        case TouchEventType::BEGAN:
            sprite->stopAllActions();
            sprite->runAction(Sequence::create(ScaleTo::create(0.15,1.1),ScaleTo::create(0.15, 1),NULL) );
            break;
        case TouchEventType::MOVED:
            break;
        case TouchEventType::ENDED:
        {
            switch (sprite->getTag()) {
                case 10001: //竞技场
                {
                    break;

                }
                case 10002: //市场
                {
                    break;

                }
                case 10003: //战场pve
                {
                    std::vector<int>vec={1,2};
//                    FightMgr::getInstance()->init(vec, 3);
                    break;
                }
                case 10004: //英雄编队（卡组）
                {
                    break;
                }
                case 10005: //英雄属性
                {
                        break;
                }
                case 10006: //合成
                {
                    break;
                }
                default:
                    break;
            }
        }
            break;
        default:
            break;
    }
}

void HomeScene::initNetEvent(){
    /*
    auto listener = EventListenerCustom::create(NET_MESSAGE, [=](EventCustom* event){
        NetMsg* msg = static_cast<NetMsg*>(event->getUserData());
        log("Custom event 1 received:%d,%d",msg->msgId,msg->len);
        switch (msg->msgId)
        {
            case C_LOGIN:
            {
                PackageLoginResp* pm=new PackageLoginResp();
                pm->ParseFromArray(msg->bytes, msg->len);
            }
                break;
            default:
                break;
        }
    });
    Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener,1);
     */
}

void HomeScene::onExit()
{
    BaseUI::onExit();
    this->removeAllChildrenWithCleanup(true);
}