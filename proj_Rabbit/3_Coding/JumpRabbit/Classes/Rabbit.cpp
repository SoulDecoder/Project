//
//  Rabbit.cpp
//  JumpRabbit
//
//  Created by jihaitao on 14-9-10.
//
//

#include "Rabbit.h"



bool Rabbit::init(){
    
    Sprite::init();
    initWithFile("game_rabbit.png");
    Size visibleSize = Director::getInstance()->getVisibleSize();
    setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
    
    Size size = this->getContentSize();
    setPhysicsBody(PhysicsBody::createBox(size));
    
    getPhysicsBody()->setRotationEnable(false);
    getPhysicsBody()->setContactTestBitmask(1);
    
    //test
    getPhysicsBody()->setGravityEnable(true);
    
    return true;

}