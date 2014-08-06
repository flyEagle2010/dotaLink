//XMGroup自动生成类
#ifndef __fancyHeart__XMGroup__
#define __fancyHeart__XMGroup__
#include <iostream>
#include "external/json/document.h"
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
class XMGroup{

private:
	Value v;
public:
	static XMGroup* record(Value v);
	rapidjson::Document doc;
	int getId();
	int getWarrior();
	int getWRate();
	int getHunter();
	int getHRate();
	int getMage();
	int getMRate();
};
#endif // defined(__dx__Data__)
