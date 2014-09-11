//
//  ShortCloud.cpp
//  JumpRabbit
//
//  Created by jihaitao on 14-9-11.
//
//

#include "ShortCloud.h"


bool ShortCloud::init(){
    Cloud::init();
    initWithFile("cloud_short.png");
    Cloud::initPhysics();
    return true;
}