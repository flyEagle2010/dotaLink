//XGateExp
#include "XGateExp.h"
static XGateExp* instance;

XGateExp* XGateExp::record(Value v){ 
	if(instance==NULL) instance=new XGateExp();
	if(instance->doc.IsNull()){
		std::string fullPath=FileUtils::getInstance()->fullPathForFilename("XGateExp.json");
		std::string str=FileUtils::getInstance()->getStringFromFile(fullPath);
		instance->doc.Parse<0>(str.c_str());
		if(instance->doc.HasParseError()){
			log("GetParseError %s",instance->doc.GetParseError());
		}
	}
	instance->v=v;
	return instance;
}
int XGateExp::getId(){
	return doc[v.asString().c_str()]["id"].GetInt();
}
int XGateExp::getExp1(){
	return doc[v.asString().c_str()]["exp1"].GetInt();
}
int XGateExp::getExp2(){
	return doc[v.asString().c_str()]["exp2"].GetInt();
}
int XGateExp::getExp3(){
	return doc[v.asString().c_str()]["exp3"].GetInt();
}
