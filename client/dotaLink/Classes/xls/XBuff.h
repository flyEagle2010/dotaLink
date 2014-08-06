//XBuff自动生成类
#ifndef __fancyHeart__XBuff__
#define __fancyHeart__XBuff__
#include <iostream>
#include "external/json/document.h"
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
class XBuff{

private:
	Value v;
public:
	static XBuff* record(Value v);
	rapidjson::Document doc;
	int getId();
	std::string getName();
	std::string getDesc();
	int getType();
	/*单位为“秒”*/
	int getDuration();
	/*单位为“秒”*/
	int getCd();
	int getRange();
};
#endif // defined(__dx__Data__)
