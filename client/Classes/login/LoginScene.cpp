#include "LoginScene.h"
#include "external/json/document.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "ShaderNode.h"


Scene* LoginScene::createScene()
{
    auto scene = Scene::create();
    auto layer = LoginScene::create();
    scene->addChild(layer);
    return scene;
}

LoginScene* LoginScene::create()
{
    LoginScene* loginScene=new LoginScene();
    if (loginScene && loginScene->init("login.json")) {
        loginScene->autorelease();
        return loginScene;
    }
    CC_SAFE_DELETE(loginScene);
    return nullptr;
}

bool LoginScene::init(std::string fileName)
{
    if(!BaseUI::init(fileName))
    {
        return false;
    }
    Size sSize=Director::getInstance()->getOpenGLView()->getFrameSize();
    Size winsize=Director::getInstance()->getWinSize();
    return true;
}

void LoginScene::onEnter()
{
    BaseUI::onEnter();
    auto btn=static_cast<ui::Button*>(layout->getChildByName("Button_9"));
    btn->addTouchEventListener(CC_CALLBACK_2(LoginScene::touchEvent,this));
    btn->setTouchEnabled(true);
    
//    this->initGame();
}

//init 游戏服务器 服务器认证
void LoginScene::initGame()
{
//    std::string url="http://192.168.1.132:8080/GameAuth/login?account=ceshi2&password=ceshi2";
//    ?account=ceshi2&password=ceshi2"
    WebHttp::getInstance()->send(HTTP_URL, CC_CALLBACK_1(LoginScene::initGameCallback, this),"account=ceshi2&password=ceshi2");
}

void LoginScene::initGameCallback(std::vector<char> *data)
{
    std::string str(data->begin(),data->end());
    sData.Parse<0>(str.c_str());
    
    if (sData["loginState"].GetInt()!=0 || sData["areaList"].Size()<1) {//先用以后修改
        log("服务列表数据长度不够");
        return;
    }
//    string ip=this->sData["areaList"][1]["ip"].GetString();
//    int port=this->sData["areaList"][1]["port"].GetInt();
    
//    Manager::getInstance()->socket=new Socket();
//    Manager::getInstance()->socket->init(ip, port);
}

void LoginScene::onDlgClose(rapidjson::Value &data)
{
    BaseUI::onDlgClose(data);
    std::string btnName=data.GetString();
    log("you click confirm %s",btnName.c_str());
}

void LoginScene::touchEvent(Ref *pSender, Widget::TouchEventType type)
{
    switch (type)
    {
        case TouchEventType::BEGAN:
            break;
        case TouchEventType::MOVED:
            break;
        case TouchEventType::ENDED:
        {
            Manager::getInstance()->switchScence(BattleMap::createScene());
            break;
        }
        case TouchEventType::CANCELED:
            break;
        default:
            break;
    }
}

void LoginScene::initNetEvent(){
    /*
    auto listener = EventListenerCustom::create(NET_MESSAGE, [=](EventCustom* event){
        NetMsg* msg = static_cast<NetMsg*>(event->getUserData());
        log("Custom event 1 received:%d,%d",msg->msgId,msg->len);
        switch (msg->msgId)
        {
            case CONNECTED:
            {
                PackageLoginReq pbLogin;
                pbLogin.set_account(sData["userBean"]["name"].GetString());
                pbLogin.set_key(sData["key"].GetString());
                Manager::getInstance()->socket->send(C_LOGIN, &pbLogin);
                break;
            }
            case C_LOGIN:
            {
                //需要存储
                PackageLoginResp *pb=new PackageLoginResp();
                pb->ParseFromArray(msg->bytes, msg->len);
                Manager::getInstance()->setMsg(C_LOGIN, pb);
                Manager::getInstance()->switchScence(HomeScene::createScene());
                pb=nullptr;
     
                break;
            }
            default:
                break;
        }
    });
    Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener,1);
*/
}


