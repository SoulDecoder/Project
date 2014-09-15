//
//  AboutScene.cpp
//  JumpRabbit
//
//  Created by jihaitao on 14-9-15.
//
//

#include "AboutScene.h"


Scene* AboutScene::createScene()
{
    auto scene = Scene::create();
    auto layer = AboutScene::create();
    scene->addChild(layer);
    return scene;
}

bool AboutScene::init()
{
    if (!Layer::init()) {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();

    
    auto background=Sprite::create("about_back.png");
    background->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    background->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    addChild(background);
    
    
    auto scoreLabel = Label::create();
    scoreLabel->setString("流氓兔跳跃");
    scoreLabel->setSystemFontSize(60);
    scoreLabel->setTextColor(Color4B::YELLOW);
    scoreLabel->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2+300));
    addChild(scoreLabel);
    
    auto score = Label::create();
    score->setString("一款自由主题的休闲神器");
    score->setSystemFontSize(36);
    score->setTextColor(Color4B::YELLOW);
    score->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2+200));
    addChild(score);
    
    auto maxScoreLabel = Label::create();
    maxScoreLabel->setString("作者：阿博，Rocky");
    maxScoreLabel->setSystemFontSize(36);
    maxScoreLabel->setTextColor(Color4B::YELLOW);
    maxScoreLabel->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2-200));
    addChild(maxScoreLabel);
    
    auto maxScore = Label::create();
    maxScore->setString("souldecoder@sina.com");
    maxScore->setSystemFontSize(36);
    maxScore->setTextColor(Color4B::YELLOW);
    maxScore->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2-300));
    addChild(maxScore);

    return  true;
}