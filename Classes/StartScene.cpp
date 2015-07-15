//
//  StartScene.cpp
//  Test
//
//  Created by KJTang on 15/7/14.
//
//

#include "StartScene.h"

StartScene::StartScene(){}

StartScene::~StartScene(){}

bool StartScene::init()
{
    if (!Scene::init())
        return false;
    
    visibleSize = Director::getInstance()->getVisibleSize();
    
    background = Layer::create();
    this->addChild(background);
    
    auto pic = GyroBackground::create("HelloWorld.png", 2);
    background->addChild(pic, -1);
    
    auto button = ButtonSprite::create("CloseNormal.png");
    background->addChild(button);
    button->setScale(3);
    button->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    button->setCallbackFunc([](){
        log("testtestest");
    });
    
    return true;
}
