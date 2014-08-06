//XRange
#include "XRange.h"
static XRange* instance;

XRange* XRange::record(Value v){ 
	if(instance==NULL) instance=new XRange();
	if(instance->doc.IsNull()){
		std::string fullPath=FileUtils::getInstance()->fullPathForFilename("XRange.json");
		std::string str=FileUtils::getInstance()->getStringFromFile(fullPath);
		instance->doc.Parse<0>(str.c_str());
		if(instance->doc.HasParseError()){
			log("GetParseError %s",instance->doc.GetParseError());
		}
	}
	instance->v=v;
	return instance;
}
int XRange::getId(){
	return doc[v.asString().c_str()]["id"].GetInt();
}
std::string XRange::getRange(){
	return doc[v.asString().c_str()]["range"].GetString();
}
