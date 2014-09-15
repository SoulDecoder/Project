//
//  GameOverScene.h
//  JumpRabbit
//
//  Created by jihaitao on 14-9-14.
//
//

#ifndef __JumpRabbit__GameOverScene__
#define __JumpRabbit__GameOverScene__

#include <iostream>
#include <cocos2d.h>

#include "MainScene.h"
#include "MainMenu.h"
#include "AboutScene.h"

USING_NS_CC;

class GameOverScene:public LayerColor{
    
private:
    Size visibleSize;
    Label *replay;
    Label *returnManMenu;
    
public:
    static Scene * createScene();
    virtual bool init();
    CREATE_FUNC(GameOverScene);
    
    void callback(Ref* pSender);
};

#endif /* defined(__JumpRabbit__GameOverScene__) */
