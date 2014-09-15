///*对话框场景类的具体实现*/
//#include "PopScene.h"
//
//Scene * PopScene::scene()
//{
//	Scene * scene = NULL;
//	do
//	{
//		scene = Scene::create();
//		PopScene * layer = PopScene::create();
//		scene->addChild(layer);
//	}
//	while(0);
//    
//	return scene;
//}
//
//bool PopScene::init()
//{
//	bool bRet = false;
//	do
//	{
//		CC_BREAK_IF(!CCLayer::init());
//        
//		Size winSize = Director::getInstance()->getVisibleSize();
//        
//		//设置这个层的背景图片，并且设置其位置为整个屏幕的中点
//		Sprite * background = Sprite::create("background.png");
//		m_bgSprite = background;
//		background->setPosition(Vec2(winSize.width/2,winSize.height/2));
//		this->addChild(background);
//        
//		//获得背景图片的大小
//		Size contentSize = background->getContentSize();
//		m_size = contentSize;
//        
//		//添加俩个菜单在这个层中
//		MenuItemImage * item1 = MenuItemImage::create("btn-play-normal.png",
//                                                          "btn-play-selected.png","",
//                                                          this,menu_selector(PopScene::yesButton));
//        
//		MenuItemImage * item2 = MenuItemImage::create("btn-highscores-normal.png",
//                                                          "btn-highscores-selected.png","",
//                                                          this,menu_selector(PopScene::noButton));
//        
//		CCMenu * menu = CCMenu::create(item1,item2,NULL);
//		menu->alignItemsHorizontallyWithPadding(5);
//		menu->setPosition(ccp(contentSize.width/2,contentSize.height/3));
//		//kCCMenuHandlerPriority的值为-128，代表的是菜单按钮的触摸优先级
//		//设置menu优先级，这里设置为普通menu的二倍减一，原因看下边
//		menu->setTouchPriority(kCCMenuHandlerPriority*2-1);
//        
//		background->addChild(menu);
//        
//		//设置题目和文本内容
//		this->setTitle();
//		this->setContent();
//        
//		this->setTouchEnabled(true);
//		bRet = true;
//	}
//	while(0);
//    
//	return bRet;
//}
//
////void PopScene::registerWithTouchDispatcher()
////{
////	//kCCMenuHandlerPriority=-128，将这个值设置为-128的二倍，可以比下边的层的优先级高
////	//而且ccTouchBegan的返回值为true，说明其他的层将接受不到这个触摸消息了，只有这个层上边的
////	//菜单的优先级比他还要打，所以它上边的菜单是可以接收到触摸消息的
////	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,
////                                                                            kCCMenuHandlerPriority*2,true);
////}
//
//bool PopScene::onTouchesBegan(Touch * touch,Event * pevent)
//{
//	return true;
//}
//
////点击菜单按钮的时候调用的事件处理函数
//void PopScene::yesButton(Object * object)
//{
//	this->removeFromParentAndCleanup(true);
//}
//
//void PopScene::noButton(Object * object)
//{
//	this->removeFromParentAndCleanup(true);
//}
//
////设置这个层的题目
//void PopScene::setTitle()
//{
//	
//	CCLabelBMFont * title = CCLabelBMFont::create("Tips","bitmapFontChinese.fnt");
//	title->setPosition(ccp(m_size.width/2,m_size.height-title->getContentSize().height/2));
//	m_bgSprite->addChild(title);
//}
//
////设置层的内容
//void PopScene::setContent()
//{
//	Label * content = Label::create("hello! everyone,welcome to www.zaojiahua.com",
//                                              "",24);
//	content->setPosition(Vec2(m_size.width/2,m_size.height/2));
//	//设置ttf的文本域
//	content->setDimensions(m_size.width-60,m_size.height-100);
//	//设置ttf的水平对齐方式
//    content->setHorizontalAlignment(kCCTextAlignmentLeft);
//    
//	m_bgSprite->addChild(content);
//}
//
//
//
//
//
//
//
//
//
