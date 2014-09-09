//
//  Cloud.cpp
//  JumpRabbit
//
//  Created by jihaitao on 14-8-28.
//
//

#include "Cloud.h"

Cloud* Cloud::create()
{
    auto cloud = new Cloud();
    cloud->init();
    cloud->autorelease();
    return cloud;
}

bool Cloud::init()
{
    
    Sprite::init();
    visibleSize = Director::getInstance()->getVisibleSize();
    
    Size size =Size(100,100);
    
    setContentSize(size);
    setAnchorPoint(	Point::ZERO);
    setTextureRect(Rect(0,0,size.width,size.height));
    setColor(Color3B::GREEN);
   
    return true;
}