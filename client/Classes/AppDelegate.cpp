#include "AppDelegate.h"
#include "LoginScene.h"
#include "TestScene.h"
#include "Update.h"
USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    
    Size size=glview->getFrameSize();
//    if(((int)size.width%1024==0) && ((int)size.height%768==0)){
//        glview->setDesignResolutionSize(1136.0, 640.0, ResolutionPolicy::FIXED_WIDTH);
//    }
//    else{
        glview->setDesignResolutionSize(1136, 640, ResolutionPolicy::FIXED_HEIGHT);
//    }
    
//    glview->setDesignResolutionSize(1136.0, 640.0, ResolutionPolicy::FIXED_WIDTH);
    std::vector<std::string>searchPath;
    searchPath.push_back("/");
    CCFileUtils::getInstance()->setSearchPaths(searchPath);
//    director->setContentScaleFactor(640.0/320.0);

    std::string pathToSave = FileUtils::getInstance()->getWritablePath();
    pathToSave += "tmpdir";
    std::vector<std::string> searchPaths = FileUtils::getInstance()->getSearchPaths();
    std::vector<std::string>::iterator iter = searchPaths.begin();
    searchPaths.insert(iter, pathToSave);
    FileUtils::getInstance()->setSearchPaths(searchPaths);

    
    srand(time(0));

    // create a scene. it's an autorelease object
    auto scene = LoginScene::createScene();
//   auto scene = Update::createScene();

    // run
//    director->runWithScene(scene);
//    
//    Manager::getInstance()->scene=scene;
    Manager::getInstance()->switchScence(scene);
    DeviceInfo* d=new DeviceInfo();
    log("uuid:%s",d->getUUID());
    log("sys:%s",d->getSystem());
    delete d;
    
//    Manager::getInstance()->socket=new Socket();
//    Manager::getInstance()->socket->init(IP, PORT);qll
    
    
    
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
