//
//  BattleMap.cpp
//  dotaLink
//
//  Created by 秦亮亮 on 14-6-30.
//
//

#include "BattleMap.h"
Scene* BattleMap::createScene()
{
	auto scene = Scene::create();
    auto layer = BattleMap::create();
    Manager::getInstance()->bmap=layer;

    scene->addChild(layer);
	return scene;
}

bool BattleMap::init()
{
    Node::init();
	//对cocostudio 设计的ui进行调整
    //std::string fileName="TileMap.tmx";
    //std::string fileName="stormwind.tmx";
    std::string fileName="map2.tmx";
    auto str=String::createWithContentsOfFile(FileUtils::getInstance()->fullPathForFilename(fileName.c_str()).c_str());
    
    this->tileMap=TMXTiledMap::createWithXML(str->getCString(), "");
    this->coverLayer=tileMap->getLayer("coverLayer");
    this->blockLayer=tileMap->getLayer("blockLayer");
    this->blockLayer->setVisible(false);
    this->addChild(tileMap, -1,100);
    
    this->createHero(1);
    this->setViewPointCenter(player->getPosition());
    
    
   
    
//    TMXObjectGroup* buildGroup=this->tileMap->getObjectGroup("build");
//    //TMXLayer* buildLayer=this->tileMap->getLayer("buildlayer");
//    for(auto item : buildGroup->getObjects())
//    {
//
//    }
    
 

	auto listener = EventListenerTouchOneByOne::create();
    
	//lambda expression: advanced feature in C++ 11
	listener->onTouchBegan = [&](Touch *touch, Event *unused_event)->bool {return true;};
	listener->onTouchEnded = CC_CALLBACK_2(BattleMap::onTouchEnded, this);
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    this->scheduleUpdate();
	return true;
}

void BattleMap::onEnter()
{
    Node::onEnter();
}

void BattleMap::createHero(int type)
{
    TMXObjectGroup* objectGroup=this->tileMap->getObjectGroup("items");
    if(type==1){
        auto born=objectGroup->getObject("hero");
        float x=born["x"].asDouble();
        float y=born["y"].asDouble();
        this->player=Hero::create(101);
        this->player->type=type;
        this->player->setIsLead(true);
        this->player->setPosition(x,y);
        this->tileMap->addChild(player,0);
//        this->coverLayer->addChild(player);
        this->team=Team::create(player);
        
        Hero* player2=Hero::create(103);
        player2->type=type;
        player2->setIsLead(false);
        player2->preHero=player;
        tileMap->addChild(player2,0);
//        this->coverLayer->addChild(player2);
        this->team->addMember(player2);
        this->team->retain();
    }
    type=2;
    int ids[6]={102,103,201,301,302,401};
    if(type==2){
        ValueVector vec=objectGroup->getObjects();
        log("npc size:%zd",vec.size());
        for(int i=0;i<vec.size();i++){
            ValueMap v=vec[i].asValueMap();
            if(v["name"].asString()=="npc"){
                Npc* npc=Npc::create(ids[rand()%6]);
                npc->type=type;
                float x=v["x"].asDouble();
                float y=v["y"].asDouble();
                this->tileMap->addChild(npc);
//                this->coverLayer->addChild(npc);
                npc->setPosition(x,y);
                npc->run();
                this->npcs.pushBack(npc);

            }
        }
    }
}

void BattleMap::setViewPointCenter(cocos2d::Point position)
{
    auto winSize = Director::getInstance()->getWinSize();
    float x = MAX(position.x, winSize.width / 2);
    float y = MAX(position.y, winSize.height / 2);
    x = MIN(x, (tileMap->getMapSize().width * this->tileMap->getTileSize().width) - winSize.width / 2);
    y = MIN(y, (tileMap->getMapSize().height * tileMap->getTileSize().height) - winSize.height / 2);
    auto actualPosition = Point(x, y);
    
    auto centerOfView = Point(winSize.width / 2, winSize.height / 2);
    auto viewPoint = centerOfView - actualPosition;
    this->setPosition(viewPoint);
}


Vec2 BattleMap::position2Grid(Point position)
{
    log("before pos:%f,%f",position.x,position.y);
    position=CC_POINT_POINTS_TO_PIXELS(position);
    log("after pos:%f,%f",position.x,position.y);
    int x = position.x / tileMap->getTileSize().width;
//    int y = position.y / tileMap->getTileSize().height;
    int y =((tileMap->getMapSize().height * tileMap->getTileSize().height) - position.y) / tileMap->getTileSize().height;
    return Vec2(x, y);
}


void BattleMap::pickUp()
{
//    for(Hero* hero : team)
    {
//        Point tileCoord = this->position2Grid(hero->getPosition());
        //int tileGid = this->tileLayer->getTileGIDAt(tileCoord);
//        auto collectable = this->tileMap->getPropertiesForGID(tileGid)["Collectable"].asString();
//        if ("True" == collectable) {
//                meta->removeTileAt(tileCoord);
//                foreground->removeTileAt(tileCoord);
//    
//               this->numCollected++;
//               this->hud->numCollectedChanged(_numCollected);
//        }
    }
}

void BattleMap::update(float dt)
{
    this->sortDepth();

    this->setViewPointCenter(player->getPosition());
}

bool BattleMap::isblock(Vec2 pos)
{
    /*
    pos=CC_POINT_POINTS_TO_PIXELS(pos);
    TMXObjectGroup* objectGroup=this->tileMap->getObjectGroup("block");
    auto left=objectGroup->getObject("left");
    auto right=objectGroup->getObject("right");
    auto top=objectGroup->getObject("top");
    auto bottom=objectGroup->getObject("bottom");
    
    if(pos.x<=left["width"].asDouble()    || pos.x>=right["x"].asDouble()||
       pos.y<=bottom["height"].asDouble() || pos.y>=top["y"].asDouble())
    {
        return true;
    } 
    */
    Vec2 grid=this->position2Grid(pos);
    int tileGrid=this->blockLayer->getTileGIDAt(grid);
    Value properties=tileMap->getPropertiesForGID(tileGrid);
    if(properties.getType()==Value::Type::MAP){
        ValueMap map=properties.asValueMap();
        auto block = map["isBlock"].asString();
        if ("true" == block) {
            return true;
        }
    }
    return false;
}

Vector<BNpc*> BattleMap::getTargets(int xID,BNpc* attacker)
{
    XRange* xr=XRange::record(Value(xID));
    std::vector<std::string> grids=Utils::split(xr->getRange(),",");
    
    Vector<BNpc*> targets;
    for(int i=0;i<grids.size();i++){
        Vec2 grid=PointFromString(grids.at(i));
        if(grid.x==0 && grid.y==0){
            continue;
        }

        Vec2 attackerGrid=this->position2Grid(attacker->getPosition());
        Vector<BNpc*> tmpArr;
        //英雄
        if(attacker->type==1){
            tmpArr=this->npcs;
        }
        //怪物 boss
        if(attacker->type==2 || attacker->type==3){
            tmpArr=this->team->items;
        }
        for(BNpc* hero : tmpArr){
            Vec2 heroGrid=this->position2Grid(hero->getPosition());
            if(heroGrid==attackerGrid+grid){
                targets.pushBack(hero);
            }
        }
    }
    return targets;
}

void BattleMap::sortDepth()
{
    /*
    auto p = this->player->getPosition();
    p = CC_POINT_POINTS_TO_PIXELS(p);
    Sprite* sprite=this->coverLayer->getTileAt(this->position2Grid(p));
//    this->tileMap->reorderChild(player, 0);
    if(!sprite){
        log("zorder:%d",this->coverLayer->getZOrder());
        return;
    }
    for(auto hero : this->team->items){
        auto sp=sprite->getPosition();
        if(sp.y-75>=p.y){
            this->tileMap->reorderChild(hero, 3);
        } else{
            this->tileMap->reorderChild(hero, 0);
        }
    }
    for(auto npc : this->npcs){
        this->tileMap->reorderChild(npc, 0);
        auto p = npc->getPosition();
        p = CC_POINT_POINTS_TO_PIXELS(p);
        auto sp=sprite->getPosition();
        if(sp.y-75>=p.y){
            this->tileMap->reorderChild(npc, 3);
        } else{
            this->tileMap->reorderChild(npc, 0);
        }
    }
    */
    if(this->npcs.size()==0 || !this->team || this->team->items.size()==0){
        return;
    }
    Vector<BNpc*> items;//=this->npcs;
    items.pushBack(npcs);
    items.pushBack(this->team->items);
    int gridWidth=tileMap->getMapSize().width;
    int gridHeight=tileMap->getMapSize().height;
    for(int i=0;i<gridWidth;i++){
        for(int j=0;j<gridHeight;j++){
            Sprite* sprite=this->coverLayer->getTileAt(Vec2(i,j));
            if(!sprite){
                continue;
            }
            for(auto hero : items){
                Vec2 pos=hero->getPosition();
                Vec2 heroGrid=this->position2Grid(hero->getPosition());
                if(heroGrid!= Vec2(i,j)){
                    break;
                }
                if(sprite->getPositionY()+75 >= pos.y){
                    this->tileMap->reorderChild(hero, 5);
                } else{
                    this->tileMap->reorderChild(hero, 0);
                }
            }
        }
    }
    items.clear();
}

void BattleMap::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
    auto touchPoint = touch->getLocation();
    auto startPoint=touch->getStartLocation();
    touchPoint = this->convertToNodeSpace(touchPoint);
    startPoint = this->convertToNodeSpace(startPoint);
    float dx=touchPoint.x-startPoint.x;
    float dy=touchPoint.y-startPoint.y;
    if(dx>0 && fabs(dx)>fabs(dy)) this->player->setDir(Dir::right);
    if(dx<0 && fabs(dx)>fabs(dy)) this->player->setDir(Dir::left);
    if(dy>0 && fabs(dy)>fabs(dx)) this->player->setDir(Dir::top);
    if(dy<0 && fabs(dy)>fabs(dx)) this->player->setDir(Dir::bottom);
}

void BattleMap::onExit()
{

}