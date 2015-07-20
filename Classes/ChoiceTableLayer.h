//
//  ChoiceTableLayer.h
//  Test
//
//  Created by KJTang on 15/7/18.
//
//

#ifndef ChoiceTableLayer_cpp
#define ChoiceTableLayer_cpp

#include "cocos2d.h"

using namespace cocos2d;

class ChoiceTableLayer : public Layer
{
private:
    Size visibleSize;

    Vector<Label*> choices;
    int choiceNumber;
    int choiceResult;
    
    EventListenerTouchOneByOne *touchListener;
    Vector<EventListenerTouchOneByOne*> listeners;
public:
    ChoiceTableLayer();
    ~ChoiceTableLayer();
    
    virtual bool init();
    CREATE_FUNC(ChoiceTableLayer);
    
    void setChoiceNumber(int number);
    void setChoiceContent(int id, std::string content);
    void setChoiceChoosable(int id, bool choosable);
    
    void showChoiceTable();
    
    void setChoiceResult(int result);
    int getChoiceReuslt();
};

#endif /* ChoiceTableLayer_cpp */