
#include "OepenLayer.h"
bool OpenLayer::init()
{
	Size winsize = Director::getInstance()->getWinSize();
	Label *label = Label::createWithSystemFont("Pong!", "", 48);
	label->setPosition(Vec2(winsize.width / 2, winsize.height*0.8));
	this->addChild(label);

	Label *labelStart = Label::createWithSystemFont("Start", "", 24);
	MenuItemLabel * menuItem = MenuItemLabel::create(labelStart, CC_CALLBACK_1(OpenLayer::menuCallBack, this));
	menuItem->setTag(101);
	menuItem->setPosition(Vec2(winsize.width / 2, winsize.height*0.55));

	Label *labelHelp = Label::createWithSystemFont("Help", "", 24);
	MenuItemLabel *menuItem_3 = MenuItemLabel::create(labelHelp, CC_CALLBACK_1(OpenLayer::menuCallBack,this));
	menuItem_3->setTag(103);
	menuItem_3->setPosition(winsize.width / 2, winsize.height*0.4);

	Label *labelQuit = Label::createWithSystemFont("Quit","", 24);
	MenuItemLabel * menuItem_2 = MenuItemLabel::create(labelQuit, CC_CALLBACK_1(OpenLayer::menuCallBack, this));
	menuItem_2->setTag(102);
	menuItem_2->setPosition(Vec2(winsize.width / 2, winsize.height*0.25));

	auto menu = Menu::create(menuItem, menuItem_2, menuItem_3,NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);
	return true;
}


void OpenLayer::menuCallBack(Ref * pSender)
{
	switch (((MenuItem*)pSender)->getTag())
	{
	case 101:
		tsm->goToGameScene(); 
		break;
	case 102:
	{
		Director::getInstance()->end();
		exit(0);
	}
		break;
	case 103:
	{
		tsm->goToHelpScene();
		break;
	}
	default:
		break;
	}
}