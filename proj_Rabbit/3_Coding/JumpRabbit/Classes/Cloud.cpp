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
    float f =  ((float)(rand()%95))/100;
    setPosition(Vec2(visibleSize.width*f, visibleSize.height));
    return true;
}

void Cloud::initPhysics(){
    Size size = getContentSize();
    setPhysicsBody(PhysicsBody::createBox(size));
    getPhysicsBody()->setRotationEnable(false);
    getPhysicsBody()->setContactTestBitmask(1);
    getPhysicsBody()->setGravityEnable(false);
    getPhysicsBody()->setVelocity(Vec2(0, -300));
}
