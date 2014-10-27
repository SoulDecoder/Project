//
//  SettingScene.h
//  JumpRabbit
//
//  Created by jihaitao on 14-8-28.
//
//

#ifndef __JumpRabbit__SettingScene__
#define __JumpRabbit__SettingScene__

#include <iostream>
#include <cocos2d.h>
#include "MainMenu.h"


USING_NS_CC;

class SettingScene : public Layer{
private:
    Size visibleSize;
    MenuItemImage* onButton;
    MenuItemImage* offButton;
public:
   
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(SettingScene);
    void callback(Ref* pSender);
};

#endif /* defined(__JumpRabbit__PopScene__) */
