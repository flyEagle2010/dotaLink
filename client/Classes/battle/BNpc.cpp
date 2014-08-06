//
//  BNpc.cpp
//  dotaLink
//
//  Created by 秦亮亮 on 14-7-1.
//
//

#include "BNpc.h"
#include "Manager.h"

bool BNpc::init(int xid)
{
    this->xid=xid;
	//如果需要对cocostudio 设计的ui进行调整
    const char* plistName = String::createWithFormat("ani%d.plist",xid)->getCString();
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(plistName);
    this->sprite=Sprite::create();
    this->sprite->setAnchorPoint(Vec2(0.5,0));
    this->addChild(sprite);
//    this->dir=Dir::left;
    this->timerAi();
    this->stand();
    this->initSkill();
    
    this->schedule(SEL_SCHEDULE(&BNpc::timerAi), 6);
    this->scheduleUpdate();

    
	return true;
}

void BNpc::onEnter()
{
    Node::onEnter();
}

void BNpc::initSkill()
{
//    std::vector<int> skills={10101,10201,10301,10401,10501,10601,10701,10801,10901,11001,11101,11201,20101,20201,20301,20401,20501,30101,30201,30301,30401,30501,30601,30701,30801};
//    this->skillID=skills[rand()%skills.size()];
//    this->skill=Skill::create(skillID);
//    this->skill->attacker=this;
    
}

void BNpc::timerAi()
{
    float num=Utils::random01();
    if(num<0.25){
        this->setDir(Dir::left);
        return;
    }
    if(num<=0.5){
        this->setDir(Dir::right);
        return;
    }
    if(num<=0.75){
        this->setDir(Dir::top);
        return;
    }
    if(num<=1){
        this->setDir(Dir::bottom);
        return;
    }
}

void BNpc::update(float dt)
{
    return;
    
    if(this->state==HState::walk){
        Vec2 pos=this->getEndPos();
        Vec2 sPos=this->getPosition();
        
        Vec2 end=pos+sPos;
        if(Manager::getInstance()->bmap && Manager::getInstance()->bmap->isblock(sPos)){
            this->invert();
            pos=this->getEndPos();
            this->walk();
        }
        
        this->setPosition(sPos+pos/40);
        if(!this->sprite->getActionByTag(HERO_WALK)){
            this->walk();
        }
    }
}

void BNpc::run()
{
    this->state=HState::walk;
    this->walk();

    Vec2 endPos=this->getEndPos();
    if(Manager::getInstance()->bmap && Manager::getInstance()->bmap->isblock(this->getPosition()+endPos)){
        this->invert();
        return;
//        endPos=this->getEndPos();
    }
    Sequence* seq=Sequence::create(MoveBy::create(0.3, endPos),CallFunc::create(CC_CALLBACK_0(BNpc::run, this)), NULL);
    this->runAction(seq);
}

void BNpc::stand()
{
    Animation* standAnim = this->createAnimation("ani_%d_idle_%d.png",8,12);
    this->sprite->stopAllActions();
    RepeatForever* action=RepeatForever::create(Animate::create(standAnim));
    action->setTag(HERO_STAND);
    this->sprite->runAction(action);
    
    this->state=HState::stand;
}

void BNpc::walk()
{
    Animation* walkAnim=this->createAnimation("ani_%d_walk_%d.png",8,12);
    this->sprite->stopAllActions();
    RepeatForever* action=RepeatForever::create(Animate::create(walkAnim));
    action->setTag(HERO_WALK);
    this->sprite->runAction(action);
    this->state=HState::walk;
}

void BNpc::attack()
{
    Animation* attackAnim=this->createAnimation("ani_%d_attack01_%d.png",8,12);
    Animate* action=Animate::create(attackAnim);
    action->setTag(HERO_ATTACK);
    this->stopAllActions();
    this->sprite->runAction(Sequence::create(action,CCCallFunc::create(CC_CALLBACK_0(BNpc::walk, this)), NULL));
    this->state=HState::attack;
}

void BNpc::skillAttack()
{
    Animation* skillAnim=this->createAnimation("ani_%d_skillAttack01_%d.png",10,12);
    Animate* action=Animate::create(skillAnim);
    action->setTag(HERO_SKILL_ATTACK);
    this->sprite->runAction(action);
    this->state=HState::skillAttack;
}

Animation* BNpc::createAnimation(const char* formatStr, int frameCount, int fps)
{
    Vector<SpriteFrame*> frames;
    for(int i=1;i<=frameCount;i++){
        const char* imgName = String::createWithFormat(formatStr,xid,dir*100+i)->getCString();
        SpriteFrame *pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(imgName);
        frames.pushBack(pFrame);
    }
    return Animation::createWithSpriteFrames(frames, 1.0f / fps);
}


void BNpc::invert()
{
    if(getDir() == Dir::left){
        this->setDir(Dir::right);
        return;
    }
    if(getDir() == Dir::right){
        this->setDir(Dir::left);
        return;
    }
    if(getDir() == Dir::bottom){
        this->setDir(Dir::top);
        return;
    }
    if(getDir() == Dir::top){
        this->setDir(Dir::bottom);
        return;
    }
}

void BNpc::setDir(Dir value)
{
    this->dir=value;
    if(this->state==HState::stand) this->stand();
    if(this->state==HState::walk){
//        this->walk();
        this->stopAllActions();
        this->run();
    }
    if(this->state==HState::attack) this->attack();
    if(this->state==HState::skillAttack) this->skillAttack();
}

Dir BNpc::getDir()
{
    return this->dir;
}

Vec2 BNpc::getEndPos()
{
    if(dir==Dir::left)   return Vec2(-150/2,0);
    if(dir==Dir::right)  return Vec2(150/2,0);
    if(dir==Dir::top) return Vec2(0,150/2);
    if(dir==Dir::bottom) return Vec2(0,-150/2);
    return Vec2(0,0);
}

void BNpc::onExit()
{
    Node::onExit();
}