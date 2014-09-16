//
//  PopScene.cpp
//  JumpRabbit
//
//  Created by jihaitao on 14-9-16.
//
//

#include "PopScene.h"

Scene* PopScene::createScene(){
    auto scene=Scene::create();
    auto layer = PopScene::create();
    scene->addChild(layer);
    return scene;
}

bool PopScene::init(){

    if (!Layer::init()) {
        return false;
    }
    
    
    visibleSize = Director::getInstance()->getVisibleSize();
    
    auto b = Sprite::create("game_back.png");
    b->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
    addChild(b);
    
    
    auto background = Sprite::create("setting_background.png");
    background->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
    addChild(background);
    
    Size contentSize = background->getContentSize();
    
    //添加音效标签
    auto label=Label::create();
    label->setString("音效：");
    label->setTextColor(Color4B::YELLOW);
    label->setSystemFontSize(48);
    label->setPosition(Vec2(contentSize.width/2-50, contentSize.height/2+50));
    background->addChild(label);
    
    //开关按钮
    auto bg = Sprite::create("bg.png");
    auto onSprite = Sprite::create("on.png");
    auto offSprite = Sprite::create("off.png");
    auto thumbSprite = Sprite::create("thumb.png");
    auto  ttfon=Label::create("","Arial",14);
    auto  ttfoff=Label::create("","Arial",14);
    
    auto mySwitch = ControlSwitch::create(bg, onSprite, offSprite, thumbSprite,ttfon,ttfoff);
    mySwitch->setPosition(Vec2(contentSize.width/2+50, contentSize.height/2+50));
    background->addChild(mySwitch);

    //清除最高分按钮
    auto clearButton = MenuItemImage::create("button_clear_normal.png",
                                             "button_clear_selected.png",
                                        CC_CALLBACK_1(PopScene::callback,this));
    clearButton->setPosition(Vec2(contentSize.width/2, contentSize.height/2-50));
    clearButton->setTag(2);
    
    
    auto menu = Menu::create(clearButton, NULL);
    menu->setPosition(Vec2::ZERO);
    menu->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
    background->addChild(menu);
    
    return true;
}

void PopScene::callback(cocos2d::Ref *pSender){

    MenuItem *item = (MenuItem*) pSender;
    switch (item->getTag()) {
        case 1:
            log("开关");
            break;
        case 2:
            log("清除数据数据");
            break;
        default:
            break;
    }

}