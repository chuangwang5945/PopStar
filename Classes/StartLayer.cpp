#include "GameScene.h"
#include "GameLevel.h"

#include "StartLayer.h"

USING_NS_CC;

enum
{
    tagClassicItem = 101,
    tagLimmitItem,
};

CCScene* StartLayer::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	StartLayer *layer = StartLayer::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool StartLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	float scale = visibleSize.width/320.f;

	CCSprite* popStarBg = CCSprite::create("popstar_start.png");
	popStarBg->setPosition(ccp(160*scale, 240*scale));
	popStarBg->setScale(scale);
	this->addChild(popStarBg, 0);


    CCMenuItemFont* pClassicalItem = CCMenuItemFont::create("经典玩法", this, menu_selector(StartLayer::onClickMenu));
    pClassicalItem->setPosition(ccp(visibleSize.width/2, visibleSize.height*0.6f));
    pClassicalItem->setTag(tagClassicItem);
    CCMenuItemFont* pLimmitItem = CCMenuItemFont::create("极限挑战", this, menu_selector(StartLayer::onClickMenu));
    pLimmitItem->setPosition(ccp(visibleSize.width/2, visibleSize.height*0.3f));
    pLimmitItem->setTag(tagLimmitItem);
	CCMenu* menu = CCMenu::create(pClassicalItem, NULL);//pLimmitItem,
	menu->setPosition(CCPointZero);
	this->addChild(menu);

	return true;
}

void StartLayer::onClickMenu(CCObject* obj)
{
    CCMenuItem* pItem = (CCMenuItem*)obj;
    switch (pItem->getTag())
    {
        case tagClassicItem:
        {
            changeLayer( this, GameLevel::create() );
        }
            break;
        case tagLimmitItem:
        {
            //极限挑战玩法
        }
            break;
            
        default:
            break;
    }
}
