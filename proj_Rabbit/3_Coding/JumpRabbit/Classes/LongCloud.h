//
//  LongCloud.h
//  JumpRabbit
//
//  Created by jihaitao on 14-9-11.
//
//

#ifndef __JumpRabbit__LongCloud__
#define __JumpRabbit__LongCloud__

#include <iostream>
#include <cocos2d.h>
#include "Cloud.h"

USING_NS_CC;

class LongCloud:public Cloud{

public:
    virtual bool init();
    CREATE_FUNC(LongCloud);
};

#endif /* defined(__JumpRabbit__LongCloud__) */
