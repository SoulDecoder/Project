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

USING_NS_CC;

class SettingScene:public Layer{
    
public:
    static Scene * createScene();
    virtual bool init();
    CREATE_FUNC(SettingScene);
};

#endif /* defined(__JumpRabbit__SettingScene__) */
