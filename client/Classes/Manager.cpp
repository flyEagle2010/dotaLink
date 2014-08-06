//
//  Manager.cpp
//  fancyHeart
//
//  Created by 秦亮亮 on 14-5-4.
//
//

#include "Manager.h"
static Manager* instance=nullptr;

Manager* Manager::getInstance(){
    if(instance==nullptr){
        instance=new Manager();
    }
    return instance;
}

void Manager::switchScence(Scene* scene)
{
    auto curScene=Director::getInstance()->getRunningScene();
    if (curScene) {
        Director::getInstance()->replaceScene(scene);
    }else{
        Director::getInstance()->runWithScene(scene);
    }
    getInstance()->scene=scene;
}
