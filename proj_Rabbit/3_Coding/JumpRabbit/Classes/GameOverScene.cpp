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
    
    
    auto background = Sprite::create("game_back.png");
    background->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
    addChild(background);
    
    auto overLabel = Label::create();
    overLabel->setString("GameOver");
    overLabel->setSystemFontSize(48);
    overLabel->setTextColor(Color4B::YELLOW);
    overLabel->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2+350));
    addChild(overLabel);

    
    
    auto scoreLabel = Label::create();
    scoreLabel->setString("得分：");
    scoreLabel->setSystemFontSize(36);
    scoreLabel->setTextColor(Color4B::YELLOW);
    scoreLabel->setPosition(Vec2(visibleSize.width/2-50,visibleSize.height/2+250));
    addChild(scoreLabel);
    
    auto score = Label::create();
    score->setString("1000");
    score->setSystemFontSize(36);
    score->setTextColor(Color4B::YELLOW);
    score->setPosition(Vec2(visibleSize.width/2+50,visibleSize.height/2+250));
    addChild(score);
    
    auto maxScoreLabel = Label::create();
    maxScoreLabel->setString("最高分：");
    maxScoreLabel->setSystemFontSize(36);
    maxScoreLabel->setTextColor(Color4B::YELLOW);
    maxScoreLabel->setPosition(Vec2(visibleSize.width/2-50,visibleSize.height/2+150));
    addChild(maxScoreLabel);
    
    auto maxScore = Label::create();
    maxScore->setString("1000");
    maxScore->setSystemFontSize(36);
    maxScore->setTextColor(Color4B::YELLOW);
    maxScore->setPosition(Vec2(visibleSize.width/2+50,visibleSize.height/2+150));
    addChild(maxScore);
    
    
    
    auto replay = MenuItemImage::create("button_again_normal.png", "button_again_selected.png",
                                        CC_CALLBACK_1(GameOverScene::callback,this));
    replay->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2-50));
    replay->setTag(1);
    
    auto goMenu = MenuItemImage::create("button_goback_normal.png", "button_goback_selected.png",
                                        CC_CALLBACK_1(GameOverScene::callback,this));
    goMenu->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2-200));
    goMenu->setTag(2);
    
    
    auto menu = Menu::create(replay,goMenu, NULL);
    menu->setPosition(Vec2::ZERO);
    addChild(menu);
    
    
    return  true;
}

void GameOverScene::callback(cocos2d::Ref *pSender){
    
    MenuItem *item = (MenuItem*) pSender;
    switch (item->getTag()) {
        case 1:
             Director::getInstance()->replaceScene(MainScene::createScene());
            break;
        case 2:
             Director::getInstance()->replaceScene(MainMenu::createScene());
            break;
        default:
            break;
    }

}