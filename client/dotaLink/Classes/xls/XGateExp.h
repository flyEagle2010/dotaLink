//XGateExp自动生成类
#ifndef __fancyHeart__XGateExp__
#define __fancyHeart__XGateExp__
#include <iostream>
#include "external/json/document.h"
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
class XGateExp{

private:
	Value v;
public:
	static XGateExp* record(Value v);
	rapidjson::Document doc;
	int getId();
	int getExp1();
	int getExp2();
	int getExp3();
};
#endif // defined(__dx__Data__)
