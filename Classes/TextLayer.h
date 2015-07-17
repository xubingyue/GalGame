//
//  TextLayer.h
//  Test
//
//  Created by KJTang on 15/7/17.
//
//

#ifndef TextLayer_cpp
#define TextLayer_cpp

#include "cocos2d.h"

using namespace cocos2d;

class TextLayer : public Layer
{
private:
    Size visibleSize;
    Label *text;
    std::string strSave, strShow;
    int pos;
public:
    TextLayer();
    ~TextLayer();
    
    virtual bool init();
    CREATE_FUNC(TextLayer);
    
    void setText(std::string s) {strSave = s;}
    void showText(float interval);
    void stopText();
    
    void postStopedMsg();
    void textUpdate(float dt);
};

#endif /* TextLayer_cpp */