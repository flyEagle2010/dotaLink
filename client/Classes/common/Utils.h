//
//  Utils.h
//  fancyHeart
//
//  Created by 秦亮亮 on 14-6-3.
//
//

#ifndef __fancyHeart__Utils__
#define __fancyHeart__Utils__
#include "cocos2d.h"
#include <iostream>
#include <sys/time.h>
using namespace cocos2d;
class Utils {
    
    
public:
    
    static float random01();
    static long getTime();

    static double distance(Vec2 sp,Vec2 ep);
    
//    static bool sortLessHp(MFighter* f1,MFighter* f2);
//    static bool sortMoreHp(MFighter* f1,MFighter* f2);
//    static bool sortNear(MFighter* f1,MFighter* f2);
//    static bool sortFar(MFighter* f1,MFighter* f2);
    
    static std::vector<int> randSeveral(int num,bool isRepeat);
    static std::vector<std::string> split(std::string str,std::string match);
};
#endif /* defined(__fancyHeart__Utils__) */
