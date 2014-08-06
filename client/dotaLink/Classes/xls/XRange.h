//XRange自动生成类
#ifndef __fancyHeart__XRange__
#define __fancyHeart__XRange__
#include <iostream>
#include "external/json/document.h"
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
class XRange{

private:
	Value v;
public:
	static XRange* record(Value v);
	rapidjson::Document doc;
	int getId();
	std::string getRange();
};
#endif // defined(__dx__Data__)
