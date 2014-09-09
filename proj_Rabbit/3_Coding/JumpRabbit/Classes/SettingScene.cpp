//
//  SettingScene.cpp
//  JumpRabbit
//
//  Created by jihaitao on 14-8-28.
//
//

#include "SettingScene.h"

Scene* SettingScene::createScene()
{
    auto scene = Scene::create();
    auto layer = SettingScene::create();
    scene->addChild(layer);
    return scene;
}

bool SettingScene::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    Size size = Director::getInstance()->getVisibleSize();
    
    auto s = Sprite::create("HelloWorld.png");
    s->cocos2d::Node::setPosition(Vec2(size.width/2,size.height/2));
    addChild(s);

    return  true;
}