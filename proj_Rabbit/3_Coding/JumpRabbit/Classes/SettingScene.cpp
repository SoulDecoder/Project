//
//  SettingScene.cpp
//  JumpRabbit
//
//  Created by jihaitao on 14-8-28.
//
//

#include "SettingScene.h"

Scene* SettingScene::createScene(){
    auto scene=Scene::create();
    auto layer = SettingScene::create();
    scene->addChild(layer);
    return scene;
}

bool SettingScene::init(){

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
    label->setSystemFontSize(60);
    label->setPosition(Vec2(contentSize.width/2-50, contentSize.height/2+50));
    background->addChild(label);
    


    //开关按钮
    onButton = MenuItemImage::create("button_soundopen_normal.png",
                                           "button_soundopen_selected.png",
                                             CC_CALLBACK_1(SettingScene::callback,this));
    onButton->setPosition(Vec2(contentSize.width/2+110, contentSize.height/2+50));
    onButton->setTag(0);

    
    offButton = MenuItemImage::create("button_soundclose_normal.png",
                                     "button_soundclose_selected.png",
                                     CC_CALLBACK_1(SettingScene::callback,this));
    offButton->setPosition(Vec2(contentSize.width/2+110, contentSize.height/2+50));
    offButton->setTag(1);
    offButton->setVisible(false);
    
    //清除最高分按钮
    auto clearButton = MenuItemImage::create("button_clear_normal.png",
                                             "button_clear_selected.png",
                                        CC_CALLBACK_1(SettingScene::callback,this));
    clearButton->setPosition(Vec2(contentSize.width/2, contentSize.height/2-50));
    clearButton->setTag(2);
    
    //返回菜单
    auto backMenuButton = MenuItemImage::create("button_goback_normal.png",
                                             "button_goback_selected.png",
                                             CC_CALLBACK_1(SettingScene::callback,this));
    backMenuButton->setPosition(Vec2(contentSize.width/2, contentSize.height/2-400));
    backMenuButton->setTag(3);
    
    
    auto menu = Menu::create(onButton,offButton,clearButton,backMenuButton, NULL);
    menu->setPosition(Vec2::ZERO);
    menu->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
    background->addChild(menu);
    
    return true;
}

void SettingScene::callback(cocos2d::Ref *pSender){

    MenuItem *item = (MenuItem*) pSender;
    switch (item->getTag()) {
        case 0:
            log("关闭声音");
            onButton->setVisible(false);
            offButton->setVisible(true);
            //关闭声音操作
            
            break;
        case 1:
            log("打开声音");
            onButton->setVisible(true);
            offButton->setVisible(false);
            //打开声音操作
            
            break;
        case 2:
            log("清除数据数据");
            break;
        case 3:
            log("返回菜单");
            Director::getInstance()->replaceScene(MainMenu::createScene());
            break;
            
        default:
            break;
    }
}