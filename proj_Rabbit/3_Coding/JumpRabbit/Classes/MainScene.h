//
//  MainScene.h
//  JumpRabbit
//
//  Created by jihaitao on 14-8-29.
//
//

#ifndef __JumpRabbit__MainScene__
#define __JumpRabbit__MainScene__

#include <iostream>
#include <cocos2d.h>
#include "Cloud.h"
#include "Rabbit.h"
#include "LongCloud.h"
#include "ShortCloud.h"

USING_NS_CC;

class MainScene:public Layer
{
private:
    Size visibleSize;
    Rabbit *rabbit;
public:
    static Scene * createScene();
    virtual bool init();
    void addRabbit();
    void addCloud(float dt);
    void addListener();
    void addTopBar();
    CREATE_FUNC(MainScene);
};

#endif /* defined(__JumpRabbit__MainScene__) */
