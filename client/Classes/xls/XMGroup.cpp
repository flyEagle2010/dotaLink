//XMGroup
#include "XMGroup.h"
static XMGroup* instance;

XMGroup* XMGroup::record(Value v){ 
	if(instance==NULL) instance=new XMGroup();
	if(instance->doc.IsNull()){
		std::string fullPath=FileUtils::getInstance()->fullPathForFilename("XMGroup.json");
		std::string str=FileUtils::getInstance()->getStringFromFile(fullPath);
		instance->doc.Parse<0>(str.c_str());
		if(instance->doc.HasParseError()){
			log("GetParseError %s",instance->doc.GetParseError());
		}
	}
	instance->v=v;
	return instance;
}
int XMGroup::getId(){
	return doc[v.asString().c_str()]["id"].GetInt();
}
int XMGroup::getWarrior(){
	return doc[v.asString().c_str()]["warrior"].GetInt();
}
int XMGroup::getWRate(){
	return doc[v.asString().c_str()]["wRate"].GetInt();
}
int XMGroup::getHunter(){
	return doc[v.asString().c_str()]["hunter"].GetInt();
}
int XMGroup::getHRate(){
	return doc[v.asString().c_str()]["hRate"].GetInt();
}
int XMGroup::getMage(){
	return doc[v.asString().c_str()]["mage"].GetInt();
}
int XMGroup::getMRate(){
	return doc[v.asString().c_str()]["mRate"].GetInt();
}
