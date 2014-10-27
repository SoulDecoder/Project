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
#include "GameOverScene.h"

USING_NS_CC;

class MainScene:public Layer
{
private:
    Size visibleSize;
    Rabbit *rabbit;
    Sprite * topbar;
    Sprite * background;
    Sprite * gameContainer;
    float d;
public:
    
    static Scene * createScene();
    
    virtual bool init();
    
    //添加兔子
    void addRabbit(float dt);

    //添加云彩
    void addCloud(float dt);
    
    //添加监听器
    void addListener();
    
    //添加Topbar
    void addTopBar();
    
    void addGameContainer();
    
    //添加边界，使兔子的移动不超出左右边界
    void addEdge();
    
    //移除越界的云彩
    void removeOutBoundingCloud();
    
    void gameOver();
    CREATE_FUNC(MainScene);
};

#endif /* defined(__JumpRabbit__MainScene__) */
