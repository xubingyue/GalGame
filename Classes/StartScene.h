//
//  StartScene.h
//  Test
//
//  Created by KJTang on 15/7/14.
//
//

#ifndef StartScene_cpp
#define StartScene_cpp

#include "cocos2d.h"
#include "MenuLayer.h"
#include "GallaryLayer.h"

using namespace cocos2d;

class StartScene : public Scene
{
private:
    Size visibleSize;
    Layer *backgroundLayer;
    MenuLayer *menuLayer;
    GallaryLayer *gallaryLayer;
public:
    LayerColor *black;
public:
    StartScene();
    ~StartScene();
    
    virtual bool init();
    CREATE_FUNC(StartScene);
};

#endif /* StartScene_cpp */
