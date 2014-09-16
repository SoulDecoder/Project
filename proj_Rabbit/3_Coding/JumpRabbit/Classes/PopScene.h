//
//  PopScene.h
//  JumpRabbit
//
//  Created by jihaitao on 14-9-16.
//
//

#ifndef __JumpRabbit__PopScene__
#define __JumpRabbit__PopScene__

#include <iostream>
#include <cocos2d.h>
#include <cocos-ext.h>

USING_NS_CC;
USING_NS_CC_EXT;

class PopScene : public Layer{
private:
    Size visibleSize;
    
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(PopScene);
    void callback(Ref* pSender);
};

#endif /* defined(__JumpRabbit__PopScene__) */
