//XSkill自动生成类
#ifndef __fancyHeart__XSkill__
#define __fancyHeart__XSkill__
#include <iostream>
#include "external/json/document.h"
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
class XSkill{

private:
	Value v;
public:
	static XSkill* record(Value v);
	rapidjson::Document doc;
	int getId();
	std::string getName();
	std::string getDesc();
	int getType();
	/*百分比*/
	/*q ll:
秒*/
	int getDuration();
	/*q ll:
秒*/
	int getCd();
	int getRange();
};
#endif // defined(__dx__Data__)
