//
//  AboutScene.h
//  JumpRabbit
//
//  Created by jihaitao on 14-9-15.
//
//

#ifndef __JumpRabbit__AboutScene__
#define __JumpRabbit__AboutScene__

#include <iostream>
#include <cocos2d.h>

USING_NS_CC;


class AboutScene:public Layer{
    
public:
    static Scene * createScene();
    virtual bool init();
    CREATE_FUNC(AboutScene);
};

#endif /* defined(__JumpRabbit__AboutScene__) */
