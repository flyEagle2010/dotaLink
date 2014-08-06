//XHero
#include "XHero.h"
static XHero* instance;

XHero* XHero::record(Value v){ 
	if(instance==NULL) instance=new XHero();
	if(instance->doc.IsNull()){
		std::string fullPath=FileUtils::getInstance()->fullPathForFilename("XHero.json");
		std::string str=FileUtils::getInstance()->getStringFromFile(fullPath);
		instance->doc.Parse<0>(str.c_str());
		if(instance->doc.HasParseError()){
			log("GetParseError %s",instance->doc.GetParseError());
		}
	}
	instance->v=v;
	return instance;
}
int XHero::getId(){
	return doc[v.asString().c_str()]["id"].GetInt();
}
int XHero::getHeroID(){
	return doc[v.asString().c_str()]["heroID"].GetInt();
}
int XHero::getLevel(){
	return doc[v.asString().c_str()]["level"].GetInt();
}
int XHero::getAttack(){
	return doc[v.asString().c_str()]["attack"].GetInt();
}
int XHero::getPower(){
	return doc[v.asString().c_str()]["power"].GetInt();
}
int XHero::getDefence(){
	return doc[v.asString().c_str()]["defence"].GetInt();
}
int XHero::getHp(){
	return doc[v.asString().c_str()]["hp"].GetInt();
}
int XHero::getMSpeed(){
	return doc[v.asString().c_str()]["mSpeed"].GetInt();
}
int XHero::getASpeed(){
	return doc[v.asString().c_str()]["aSpeed"].GetInt();
}
int XHero::getHeal(){
	return doc[v.asString().c_str()]["heal"].GetInt();
}
int XHero::getRange(){
	return doc[v.asString().c_str()]["range"].GetInt();
}
