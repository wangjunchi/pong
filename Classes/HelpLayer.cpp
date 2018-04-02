#include "HelpLayer.h"


bool HelpLayer::init()
{
	//获取窗口大小
	Size winSize = Director::getInstance()->getWinSize();
	MenuItem * menuItem = MenuItemLabel::create(Label::createWithSystemFont
	("Back", "", 24), CC_CALLBACK_1(HelpLayer::menuCallBack, this));
	menuItem->setPosition(Vec2(winSize.width*0.9, winSize.height*0.9));
	auto menu = Menu::create(menuItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	//添加说明本文
	auto helpLabel = Label::createWithSystemFont("Press A and D to control the badmintion up.\nPress <- and -> to control the badmintion below\nPress Space to start the game.","",20);
	helpLabel->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	this->addChild(helpLabel);
	return true;
}

void HelpLayer::menuCallBack(Ref * pSender)
{
	tsm->goToOpenScene();
}