//XGate
#include "XGate.h"
static XGate* instance;

XGate* XGate::record(Value v){ 
	if(instance==NULL) instance=new XGate();
	if(instance->doc.IsNull()){
		std::string fullPath=FileUtils::getInstance()->fullPathForFilename("XGate.json");
		std::string str=FileUtils::getInstance()->getStringFromFile(fullPath);
		instance->doc.Parse<0>(str.c_str());
		if(instance->doc.HasParseError()){
			log("GetParseError %s",instance->doc.GetParseError());
		}
	}
	instance->v=v;
	return instance;
}
int XGate::getId(){
	return doc[v.asString().c_str()]["id"].GetInt();
}
std::string XGate::getName(){
	return doc[v.asString().c_str()]["name"].GetString();
}
int XGate::getMapID(){
	return doc[v.asString().c_str()]["mapID"].GetInt();
}
int XGate::getMGroup(){
	return doc[v.asString().c_str()]["mGroup"].GetInt();
}
int XGate::getMNum(){
	return doc[v.asString().c_str()]["mNum"].GetInt();
}
int XGate::getMaxLv(){
	return doc[v.asString().c_str()]["maxLv"].GetInt();
}
int XGate::getMinLv(){
	return doc[v.asString().c_str()]["minLv"].GetInt();
}
int XGate::getBoosID(){
	return doc[v.asString().c_str()]["boosID"].GetInt();
}
std::string XGate::getDesc(){
	return doc[v.asString().c_str()]["desc"].GetString();
}
int XGate::getCondition(){
	return doc[v.asString().c_str()]["condition"].GetInt();
}
int XGate::getGold(){
	return doc[v.asString().c_str()]["gold"].GetInt();
}
int XGate::getItem(){
	return doc[v.asString().c_str()]["item"].GetInt();
}
