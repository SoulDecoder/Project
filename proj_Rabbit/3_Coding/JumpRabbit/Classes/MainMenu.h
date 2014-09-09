//
//  Menu.h
//  JumpRabbit
//
//  Created by linbo on 14/8/27.
//
//

#ifndef __JumpRabbit__Menu__
#define __JumpRabbit__Menu__

#include "cocos2d.h"


USING_NS_CC;
typedef enum
{
    caseStart,
    caseAbout,
    caseSetting
} MenuActionType;

class MainMenu: public cocos2d::Layer{
    
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainMenu);
};




#endif /* defined(__JumpRabbit__Menu__) */
