//
//  Cloud.cpp
//  JumpRabbit
//
//  Created by jihaitao on 14-8-28.
//
//

#include "Cloud.h"

Vector<Cloud*> *Cloud::clouds = new Vector<Cloud*>;

Vector<Cloud*>* Cloud::getClouds(){
    return Cloud::clouds;
}

bool Cloud::init()
{
    Sprite::init();
    visibleSize = Director::getInstance()->getVisibleSize();
    return true;
}

void Cloud::initPhysics(){
    Size size = getContentSize();
    setPhysicsBody(PhysicsBody::createBox(size));
    getPhysicsBody()->setRotationEnable(false);
    getPhysicsBody()->setContactTestBitmask(1);
    getPhysicsBody()->setCollisionBitmask(0);
    
    getPhysicsBody()->setGravityEnable(false);
    getPhysicsBody()->setVelocity(Vec2(0, -200));
    
    float f =  ((float)(rand()%95))/100;
    
    if(visibleSize.width*f < size.width/2){//当云彩左边越界，则云彩矫正至挨着左边缘
        setPosition(Vec2(size.width/2, visibleSize.height));
    }
    else if(visibleSize.width*f>(visibleSize.width-size.width/2)){//当云彩右边越界，则云彩矫正至挨着右边缘
          setPosition(Vec2(visibleSize.width*f-size.width/2, visibleSize.height));
    }
    else{
        setPosition(Vec2(visibleSize.width*f, visibleSize.height));
    }
    
}
