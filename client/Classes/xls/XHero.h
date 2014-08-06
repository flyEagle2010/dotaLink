//XHero自动生成类
#ifndef __fancyHeart__XHero__
#define __fancyHeart__XHero__
#include <iostream>
#include "external/json/document.h"
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
class XHero{

private:
	Value v;
public:
	static XHero* record(Value v);
	rapidjson::Document doc;
	int getId();
	int getHeroID();
	int getLevel();
	int getAttack();
	int getPower();
	int getDefence();
	int getHp();
	int getMSpeed();
	int getASpeed();
	/*sony:
单位为秒*/
	int getHeal();
	/*sony:
*/
	int getRange();
};
#endif // defined(__dx__Data__)
