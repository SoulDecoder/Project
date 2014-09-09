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
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto startItem = MenuItemImage::create(
                                           "home/menu_start_normal.png",
                                           "home/menu_start_selected.png",
                                           CC_CALLBACK_1(MainMenu::menuCallback, this));
    auto settingItem = MenuItemImage::create(
                                           "home/menu_setting_normal.png",
                                           "home/menu_setting_selected.png",
                                           CC_CALLBACK_1(MainMenu::menuCallback, this));
    auto aboutItem = MenuItemImage::create(
                                           "home/menu_about_normal.png",
                                           "home/menu_about_selected.png",
                                           CC_CALLBACK_1(MainMenu::menuCallback, this));
    
    startItem->setPosition(Vec2(visibleSize.width*1/5, visibleSize.height/2));
    startItem->setTag(MenuActionType::caseStart);
    settingItem->setPosition(Vec2(visibleSize.width*2/5, visibleSize.height/2));
    settingItem->setTag(MenuActionType::caseSetting);
    aboutItem->setPosition(Vec2(visibleSize.width*3/5, visibleSize.height/2));
    aboutItem->setTag(MenuActionType::caseAbout);
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(startItem,settingItem,aboutItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    //显示积分
    auto label = LabelTTF::create("10000", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x +  visibleSize.width/2,
                            origin.y + visibleSize.height/2 + 200));
    
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
