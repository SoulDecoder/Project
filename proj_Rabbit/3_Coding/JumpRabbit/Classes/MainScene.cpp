//
//  MainScene.cpp
//  JumpRabbit
//
//  Created by jihaitao on 14-8-29.
//
//

#include "MainScene.h"
Scene* MainScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MainScene::create();
    scene->addChild(layer);
    return scene;
}

bool MainScene::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    visibleSize = Director::getInstance()->getVisibleSize();
    auto cloud = Cloud::create();
    cloud->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    addChild(cloud);
    
    return  true;
}