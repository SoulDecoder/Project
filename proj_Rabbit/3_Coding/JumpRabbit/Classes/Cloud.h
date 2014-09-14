//
//  Cloud.h
//  JumpRabbit
//
//  Created by jihaitao on 14-8-28.
//
//

#ifndef __JumpRabbit__Cloud__
#define __JumpRabbit__Cloud__

#include <iostream>

#include <cocos2d.h>

USING_NS_CC;

class Cloud:public Sprite
{
private:
    static Vector<Cloud*> *clouds;
    
protected:
    //屏幕的可见区域
    Size visibleSize;
public:
    static Vector<Cloud*>* getClouds();
    virtual bool init();
    virtual void initPhysics();
   
};

#endif /* defined(__JumpRabbit__Cloud__) */
