//
//  Menu.cpp
//  JumpRabbit
//
//  Created by linbo on 14/8/27.
//
//

#include "MainMenu.h"
#include "SettingScene.h"
#include "MainScene.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenu::create();
    
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    log("width=%g,height=%g",visibleSize.width,visibleSize.height);
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    auto background=Sprite::create("menu_background.jpg");
    background->setScale(visibleSize.width/720, visibleSize.height/1280);
    background->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    background->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    addChild(background);
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto startItem = MenuItemImage::create(
                                           "menu_start_normal.png",
                                           "menu_start_selected.png",
                                           CC_CALLBACK_1(MainMenu::menuCallback, this));
    auto settingItem = MenuItemImage::create(
                                           "menu_setting_normal.png",
                                           "menu_setting_selected.png",
                                           CC_CALLBACK_1(MainMenu::menuCallback, this));
    auto aboutItem = MenuItemImage::create(
                                           "menu_about_normal.png",
                                           "menu_about_selected.png",
                                           CC_CALLBACK_1(MainMenu::menuCallback, this));
    
    startItem->setPosition(Vec2(visibleSize.width*0.5, visibleSize.height*0.6));
    startItem->setScale(visibleSize.width/720, visibleSize.height/1280);
    startItem->setTag(MenuActionType::caseStart);
    settingItem->setPosition(Vec2(visibleSize.width*0.5, visibleSize.height*0.45));
    settingItem->setScale(visibleSize.width/720, visibleSize.height/1280);
    settingItem->setTag(MenuActionType::caseSetting);
    aboutItem->setPosition(Vec2(visibleSize.width*0.5, visibleSize.height*0.3));
    aboutItem->setScale(visibleSize.width/720, visibleSize.height/1280);
    aboutItem->setTag(MenuActionType::caseAbout);
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(startItem,settingItem,aboutItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    //显示积分
    auto label = LabelTTF::create("最高分:10000", "Arial", 30);
    label->setColor(Color3B::YELLOW);
    label->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    // position the label on the center of the screen
    label->setPosition(10,10);
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    return true;
}

void MainMenu::menuCallback(Ref* pSender)
{
    log("lsdlfkasdlkfjaklsdf");
    MenuItem*nmitem = (MenuItem*)pSender;
    
    log("%d",nmitem->getTag());
    
    switch (nmitem->getTag()) {
        case caseAbout:
            log("Item about");
            Director::getInstance()->replaceScene(AboutScene::createScene());
            break;
        case caseStart:
            log("Item start");
            Director::getInstance()->replaceScene(MainScene::createScene());
            break;
        case caseSetting:
            log("Item setting");
            Director::getInstance()->replaceScene(SettingScene::createScene());
            break;
            
        default:
            break;
    }
}
