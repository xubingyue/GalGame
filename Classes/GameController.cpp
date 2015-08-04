//
//  GameController.cpp
//  Test
//
//  Created by KJTang on 15/7/14.
//
//

#include "GameController.h"

GameController* GameController::sharedGameController = NULL;

GameController::GameController(){}

GameController::~GameController(){}

bool GameController::init()
{
    // shaders
    LoadShader();

    currentState = STATE_PREPARING;
    return true;
}

void GameController::LoadShader()
{
    // grey shader
    auto greyShader = new GLProgram();
    greyShader->initWithFilenames("GreyVertexShader.vert", "GreyFragmentShader.frag");
    greyShader->bindAttribLocation(
                                   GLProgram::ATTRIBUTE_NAME_POSITION,
                                   GLProgram::VERTEX_ATTRIB_POSITION);
    greyShader->bindAttribLocation(
                                   GLProgram::ATTRIBUTE_NAME_COLOR,
                                   GLProgram::VERTEX_ATTRIB_COLOR);
    greyShader->bindAttribLocation(
                                   GLProgram::ATTRIBUTE_NAME_TEX_COORD,
                                   GLProgram::VERTEX_ATTRIB_TEX_COORDS);
    greyShader->link();
    greyShader->updateUniforms();
    GLProgramCache::getInstance()->addGLProgram(greyShader, "grey");
    
    // blur shader
    auto blur1 = new GLProgram();
    blur1->initWithFilenames("BlurVertexShader.vert", "BlurFragmentShader1.frag");
    blur1->bindAttribLocation(
                                   GLProgram::ATTRIBUTE_NAME_POSITION,
                                   GLProgram::VERTEX_ATTRIB_POSITION);
    blur1->bindAttribLocation(
                                   GLProgram::ATTRIBUTE_NAME_COLOR,
                                   GLProgram::VERTEX_ATTRIB_COLOR);
    blur1->bindAttribLocation(
                                   GLProgram::ATTRIBUTE_NAME_TEX_COORD,
                                   GLProgram::VERTEX_ATTRIB_TEX_COORDS);
    blur1->link();
    blur1->updateUniforms();
    GLProgramCache::getInstance()->addGLProgram(blur1, "blur1");
    
    // blur shader
    auto blur2 = new GLProgram();
    blur2->initWithFilenames("BlurVertexShader.vert", "BlurFragmentShader2.frag");
    blur2->bindAttribLocation(
                              GLProgram::ATTRIBUTE_NAME_POSITION,
                              GLProgram::VERTEX_ATTRIB_POSITION);
    blur2->bindAttribLocation(
                              GLProgram::ATTRIBUTE_NAME_COLOR,
                              GLProgram::VERTEX_ATTRIB_COLOR);
    blur2->bindAttribLocation(
                              GLProgram::ATTRIBUTE_NAME_TEX_COORD,
                              GLProgram::VERTEX_ATTRIB_TEX_COORDS);
    blur2->link();
    blur2->updateUniforms();
    GLProgramCache::getInstance()->addGLProgram(blur2, "blur2");
    
    // blur shader
    auto blur3 = new GLProgram();
    blur3->initWithFilenames("BlurVertexShader.vert", "BlurFragmentShader3.frag");
    blur3->bindAttribLocation(
                              GLProgram::ATTRIBUTE_NAME_POSITION,
                              GLProgram::VERTEX_ATTRIB_POSITION);
    blur3->bindAttribLocation(
                              GLProgram::ATTRIBUTE_NAME_COLOR,
                              GLProgram::VERTEX_ATTRIB_COLOR);
    blur3->bindAttribLocation(
                              GLProgram::ATTRIBUTE_NAME_TEX_COORD,
                              GLProgram::VERTEX_ATTRIB_TEX_COORDS);
    blur3->link();
    blur3->updateUniforms();
    GLProgramCache::getInstance()->addGLProgram(blur3, "blur3");
    
    // text's shader
    auto textShader = new GLProgram();
    textShader->initWithFilenames("TextBlurShader.vert", "TextBlurShader.frag");
    textShader->bindAttribLocation(
                                   GLProgram::ATTRIBUTE_NAME_POSITION,
                                   GLProgram::VERTEX_ATTRIB_POSITION);
    textShader->bindAttribLocation(
                                   GLProgram::ATTRIBUTE_NAME_COLOR,
                                   GLProgram::VERTEX_ATTRIB_COLOR);
    textShader->bindAttribLocation(
                                   GLProgram::ATTRIBUTE_NAME_TEX_COORD,
                                   GLProgram::VERTEX_ATTRIB_TEX_COORDS);
    textShader->link();
    textShader->updateUniforms();
    GLProgramCache::getInstance()->addGLProgram(textShader, "text");
}

void GameController::saveData(std::string dataname)
{
    std::string path = FileUtils::getInstance()->getWritablePath()+"dataname";
}

void GameController::loadData()
{
    
}

void GameController::enterStartScene()
{
    switch (currentState) {
        case STATE_PREPARING: {
            Director::getInstance()->runWithScene(StartScene::create());
            break;
        }
        case STATE_GAME_SCENE: {
            GameScene::getInstance()->clear();
            Director::getInstance()->purgeCachedData();
            Director::getInstance()->replaceScene(TransitionFade::create(0.5, StartScene::create()));
            break;
        }
        case STATE_CONFIG_SCENE: {
            Director::getInstance()->popScene();
            break;
        }
        default:
            //
            break;
    }
    currentState = STATE_START_SCENE;
}

void GameController::enterGameScene(std::string dataFilename)
{
    if (dataFilename.size()) {
        switch (currentState) {
            case STATE_START_SCENE:
                Director::getInstance()->purgeCachedData();
                Director::getInstance()->replaceScene(TransitionFade::create(0.5, GameScene::getInstance()));
                GameScene::getInstance()->startSavedGame(dataFilename);
                break;
            default:
                break;
        }
    } else {
        switch (currentState) {
            case STATE_START_SCENE: {
                Director::getInstance()->purgeCachedData();
                Director::getInstance()->replaceScene(TransitionFade::create(0.5, GameScene::getInstance()));
                GameScene::getInstance()->startNewGame();
                break;
            }
                
            default:
                break;
        }
    }
    currentState = STATE_GAME_SCENE;
}

void GameController::enterConfigScene()
{
//    Director::getInstance()->purgeCachedData();
    Director::getInstance()->pushScene(TransitionFade::create(0.5, ConfigScene::create()));
    currentState = STATE_CONFIG_SCENE;
}

void GameController::exitGame()
{
    // used on android
//    Director::getInstance()->end();
    // used on iOS
    exit(0);
}

void GameController::loadBGM(std::string filename)
{
    bgmFilename = filename;
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(bgmFilename.c_str());
}

void GameController::playBGM()
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(bgmFilename.c_str());
}

void GameController::pauseBGM()
{
    CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

void GameController::resumeBGM()
{
    CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

void GameController::stopBGM()
{
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
}

void GameController::setBGMVolume(float v)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(v);
}