//
//  LongCloud.cpp
//  JumpRabbit
//
//  Created by jihaitao on 14-9-11.
//
//

#include "LongCloud.h"


bool LongCloud::init(){
    Cloud::init();
    initWithFile("cloud_long.png");
    Cloud::initPhysics();
    return true;
}