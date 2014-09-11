//
//  ShortCloud.h
//  JumpRabbit
//
//  Created by jihaitao on 14-9-11.
//
//

#ifndef __JumpRabbit__ShortCloud__
#define __JumpRabbit__ShortCloud__

#include <iostream>
#include <cocos2d.h>
#include "Cloud.h"

USING_NS_CC;

class ShortCloud:public Cloud{

public:
    virtual bool init();
    CREATE_FUNC(ShortCloud);
};

#endif /* defined(__JumpRabbit__ShortCloud__) */
