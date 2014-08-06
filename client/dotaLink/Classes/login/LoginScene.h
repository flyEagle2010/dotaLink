#ifndef __fancyHeart__LoginScene__
#define __fancyHeart__LoginScene__

#include "cocos2d.h"
#include "UIButton.h"
#include "UIText.h"
#include "Manager.h"
#include "WebHttp.h"
#include "HomeScene.h"
#include "BattleMap.h"
USING_NS_CC;
using namespace ui;
using namespace cocostudio;
class LoginScene : public BaseUI
{
public:

    static cocos2d::Scene* createScene();
    static LoginScene* create();
    virtual bool init(std::string fileName);
    virtual void onEnter();
    virtual void onDlgClose(rapidjson::Value &data);
private:
    rapidjson::Document sData;
    void initGame();
    void initGameCallback(std::vector<char> *data);
    void initNetEvent();
    void touchEvent(Ref *pSender, Widget::TouchEventType type);
};

#endif // __HELLOWORLD_SCENE_H__
