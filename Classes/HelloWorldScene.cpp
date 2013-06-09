#include "HelloWorldScene.h"
#include "Button.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

//    /////////////////////////////
//    // 3. add your codes below...
//
//    // add a label shows "Hello World"
//    // create and initialize a label
//    
//    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
//    
//    // position the label on the center of the screen
//    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
//                            origin.y + visibleSize.height - pLabel->getContentSize().height));
//
//    // add the label as a child to this layer
//    this->addChild(pLabel, 1);
//
//    // add "HelloWorld" splash screen"
//    CCSprite* pSprite = CCSprite::create("HelloWorld.png");
//
//    // position the sprite on the center of the screen
//    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
//
//    // add the sprite as a child to this layer
//    this->addChild(pSprite, 0);
    
    Button* b1 = Button::create();
    b1->setText("foo");
    b1->setContentSize(CCSize(100, 100));
    b1->setPosition(ccp(visibleSize.width * 0.25f, visibleSize.height * 0.5f));
    b1->setTarget(this, menu_selector(HelloWorld::onTapped));
    this->addChild(b1);
    
    Button* b2 = Button::create();
    b2->setImageFile("HelloWorld.png");
    b2->setContentSize(CCSize(100, 100));
    b2->setPosition(ccp(visibleSize.width * 0.5f, visibleSize.height * 0.5f));
    b2->setTarget(this, menu_selector(HelloWorld::onTapped));
    this->addChild(b2);
    
    Button* b3 = Button::create();
    b3->setText("bar", "Thonburi", 72);
    b3->setImageFile("HelloWorld.png");
    b3->setContentSize(CCSize(100, 100));
    b3->setPosition(ccp(visibleSize.width * 0.75f, visibleSize.height * 0.5f));
    b3->setTarget(this, menu_selector(HelloWorld::onTapped));
    this->addChild(b3);
    
    return true;
}

void HelloWorld::onTapped()
{
    CCLog("tapped");
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
