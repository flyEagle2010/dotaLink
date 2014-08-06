//XGate自动生成类
#ifndef __fancyHeart__XGate__
#define __fancyHeart__XGate__
#include <iostream>
#include "external/json/document.h"
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
class XGate{

private:
	Value v;
public:
	static XGate* record(Value v);
	rapidjson::Document doc;
	int getId();
	std::string getName();
	int getMapID();
	int getMGroup();
	int getMNum();
	int getMaxLv();
	int getMinLv();
	/*有BOSS的关卡必须杀死boss才可以获得通关的条件*/
	int getBoosID();
	std::string getDesc();
	/*杀死怪物数量,有BOSS的关卡必须杀死boss才可以获得通关的条件*/
	int getCondition();
	int getGold();
	int getItem();
};
#endif // defined(__dx__Data__)
