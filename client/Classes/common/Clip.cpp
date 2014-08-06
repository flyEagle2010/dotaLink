//
//  Clip.cpp
//  dotaLink
//
//  Created by 秦亮亮 on 14-7-14.
//
//

#include "Clip.h"

Clip* Clip::create(std::string plistFile,int fps)
{
    Clip* pRet=new Clip();
    if(pRet && pRet->init(plistFile,fps)){
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    
    return nullptr;
}

bool Clip::init(std::string plistFile,int fps)
{
    std::string fullPath = FileUtils::getInstance()->fullPathForFilename(plistFile);
    ValueMap dict = FileUtils::getInstance()->getValueMapFromFile(fullPath);
    ValueVector map=dict["frames"].asValueVector();
    
    Vector<SpriteFrame*> frames;

    for(int i=0;i<map.size();i++){
        std::string index=i<10?(Value("0").asString()+Value(i+1).asString()):Value(i).asString();
        std::string imgName=plistFile+index+".png";
        if(i==0) this->setSpriteFrame(imgName);
        SpriteFrame* pFrame=SpriteFrameCache::getInstance()->getSpriteFrameByName(imgName);
        frames.pushBack(pFrame);
    }
    this->animation=Animation::createWithSpriteFrames(frames,1.f/fps);
    
    return true;
}

void Clip::play(bool isLoop)
{
    if(isLoop){
        RepeatForever* action=RepeatForever::create(Animate::create(this->animation));
        this->runAction(action);
    }else{
        Animate* ani=Animate::create(this->animation);
        this->runAction(Sequence::create(ani,CCCallFunc::create(CC_CALLBACK_0(Clip::removeFromParent,this)),NULL));
    }
}