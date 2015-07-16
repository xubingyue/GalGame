//
//  GameScene.h
//  Test
//
//  Created by KJTang on 15/7/16.
//
//

#ifndef GameScene_cpp
#define GameScene_cpp

#include <thread>

#include "cocos2d.h"

#include "GameController.h"
#include "ScriptController.h"

using namespace cocos2d;

class GameScene : public Scene
{
private:
    static GameScene* sharedGameScene;
    Size visibleSize;
    
    Layer *backgroundLayer, *menuLayer;
    // bgp
    Sprite *bgp;
    std::string bgpFilename;
    float bgpDuration;
    float bgpScale;
    float bgpPositionX, bgpPositionY;
    Sprite *ch01, *ch02, *ch03, *ch04;
    
    EventListenerTouchOneByOne* touchListener;
public:
    GameScene();
    ~GameScene();
    
    virtual bool init();
    static GameScene* getInstance()
    {
        if (!sharedGameScene) {
            sharedGameScene = new GameScene();
            sharedGameScene->init();
        }
        return sharedGameScene;
    }
    void clear() {
        this->removeAllChildren();
        this->init();
    }
    
    // mission completed
    bool isMissionCompleted;
    
    void startNewGame();
    void scriptControlThread();
    void startSavedGame();
    // set
    bool setBgpStart();
    void setBgpFilename(std::string filename) { bgpFilename = filename; isMissionCompleted = true;}
    void setBgpDuration(float duration) { bgpDuration = duration; isMissionCompleted = true;}
    void setBgpScale(float scale) { bgpScale = scale; isMissionCompleted = true;}
    void setBgpPosition(float x, float y) {
        bgpPositionX = x, bgpPositionY = y;
        isMissionCompleted = true;
    }
    
    bool setCh01Picture(std::string filename);
    bool setCh02Picture(std::string filename);
    bool setCh03Picture(std::string filename);
    bool setCh04Picture(std::string filename);
    // get
    void enableScreenTouchEventListener(bool b);
};

#endif /* GameScene_cpp */
