//
//  Utils.cpp
//  fancyHeart
//
//  Created by 秦亮亮 on 14-6-3.
//
//

#include "Utils.h"
#define PI 3.14159265
#define EPSION 0.0001f
#define IS_EQUAL(val1, val2)  (fabs((val1) - (val2)) <= EPSION)
#include "BezierMove.h"
float Utils::random01()
{
    //srand(time(0));
    return (float)rand()/RAND_MAX;
}

long Utils::getTime()
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

double Utils::distance(Vec2 sp,Vec2 ep)
{
    return sqrt((ep.x-sp.x)*(ep.x-sp.x)+(ep.y-sp.y)*(ep.y-sp.y));
}

std::vector<int> Utils::randSeveral(int num,bool isRepeat)
{
    std::vector<int> arr;
    for(int i=0;i<num;i++)
    {
        int item=random()%num;
        if(isRepeat)
        {
            arr.push_back(item);
            continue;
        }
        if( find(arr.begin(),arr.end(),item) == arr.end())
        {
            i--;
        }else{
            arr.push_back(item);
        }
    }
    return arr;
}

std::vector<std::string> Utils::split(std::string str, std::string match)
{
    std::vector<std::string> strvec;
    std::string::size_type pos1, pos2;
    pos2 = str.find(match);
    pos1 = 0;
    while (std::string::npos != pos2)
    {
        strvec.push_back(str.substr(pos1, pos2 - pos1));
        
        pos1 = pos2 + 1;
        pos2 = str.find(' ', pos1);
    }
    strvec.push_back(str.substr(pos1));
    return strvec;
}