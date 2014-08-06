//XBuff
#include "XBuff.h"
static XBuff* instance;

XBuff* XBuff::record(Value v){ 
	if(instance==NULL) instance=new XBuff();
	if(instance->doc.IsNull()){
		std::string fullPath=FileUtils::getInstance()->fullPathForFilename("XBuff.json");
		std::string str=FileUtils::getInstance()->getStringFromFile(fullPath);
		instance->doc.Parse<0>(str.c_str());
		if(instance->doc.HasParseError()){
			log("GetParseError %s",instance->doc.GetParseError());
		}
	}
	instance->v=v;
	return instance;
}
int XBuff::getId(){
	return doc[v.asString().c_str()]["id"].GetInt();
}
std::string XBuff::getName(){
	return doc[v.asString().c_str()]["name"].GetString();
}
std::string XBuff::getDesc(){
	return doc[v.asString().c_str()]["desc"].GetString();
}
int XBuff::getType(){
	return doc[v.asString().c_str()]["type"].GetInt();
}
int XBuff::getDuration(){
	return doc[v.asString().c_str()]["duration"].GetInt();
}
int XBuff::getCd(){
	return doc[v.asString().c_str()]["cd"].GetInt();
}
int XBuff::getRange(){
	return doc[v.asString().c_str()]["range"].GetInt();
}
