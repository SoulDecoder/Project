//
//  Rabbit.h
//  JumpRabbit
//
//  Created by jihaitao on 14-9-10.
//
//

#ifndef __JumpRabbit__Rabbit__
#define __JumpRabbit__Rabbit__

#include <iostream>
#include <cocos2d.h>


USING_NS_CC;

class Rabbit:public Sprite{

public:
    virtual bool init();
    CREATE_FUNC(Rabbit);
};

#endif /* defined(__JumpRabbit__Rabbit__) */
