//
//  GameOverScene.cpp
//  JumpRabbit
//
//  Created by jihaitao on 14-9-14.
//
//

#include "GameOverScene.h"
Scene* GameOverScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GameOverScene::create();
    scene->addChild(layer);
    return scene;
}

bool GameOverScene::init()
{
    if (!LayerColor::initWithColor(Color4B::WHITE)) {
        return false;
    }
    
    visibleSize = Director::getInstance()->getVisibleSize();
    auto overLabel = Label::create();
    overLabel->setString("GameOver");
    overLabel->setSystemFontSize(48);
    overLabel->setTextColor(Color4B::BLACK);
    overLabel->setPosition(Vec2(visibleSize.width/2,visibleSize.height-150));
    addChild(overLabel);
    
    auto background = Sprite::create("splash_rabbit.png");
    background->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2+200));
    addChild(background);
    
    auto msgLabel = Label::create();
    msgLabel->setString("还差一点，接近妹子");
    msgLabel->setSystemFontSize(36);
    msgLabel->setTextColor(Color4B::BLACK);
    msgLabel->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
    addChild(msgLabel);
    
    replay = Label::create();
    replay->setString("再来一次");
    replay->setSystemFontSize(36);
    replay->setTextColor(Color4B::BLACK);
    replay->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2-150));
    addChild(replay);
    
    returnManMenu = Label::create();
    returnManMenu->setString("返回主菜单");
    returnManMenu->setSystemFontSize(36);
    returnManMenu->setTextColor(Color4B::BLACK);
    returnManMenu->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2-300));
    addChild(returnManMenu);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [this](Touch *t,Event *e){
        if (replay->getBoundingBox().containsPoint(t->getLocation())) {
             Director::getInstance()->replaceScene(MainScene::createScene());
        }
        if(returnManMenu->getBoundingBox().containsPoint(t->getLocation())){
             Director::getInstance()->replaceScene(MainMenu::createScene());
        }
        return false;
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    return  true;
}