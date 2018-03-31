#include "GameLayer.h"
#include "cmath"
bool GameLayer::init()
{
	
	//创建返回菜单
	MenuItem * menuItem = MenuItemLabel::create(Label::createWithTTF
		("Back", "fonts/consola.ttf", 24), CC_CALLBACK_1(GameLayer::menuCallBack, this));
	//createWithTTF("Loading......", "fonts/Marker Felt.ttf", 24)
	menuItem->setPosition(Vec2(winSize.width*0.9,winSize.height*0.9));
	auto menu = Menu::create(menuItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);
	//创建背景
	backGround = Sprite::create("load.png");
	backGround->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	backGround->setScale(1.0);
	this->addChild(backGround,-1);
	//创建两个记分板
	scoreLabelUp = Label::createWithTTF("0","fonts/pixel.ttf",20);
	scoreLabelDown = Label::createWithTTF("0", "fonts/pixel.ttf", 20);
	scoreLabelDown->setPosition(Vec2(winSize.width*0.1, winSize.height*0.05));
	scoreLabelUp->setPosition(Vec2(winSize.width*0.1, winSize.height*0.95));
	this->addChild(scoreLabelDown, 1);
	this->addChild(scoreLabelUp, 1);
	//创建左右两边的墙
	wall_L = Sprite::create("wall_2.png");
	wall_R = Sprite::create("wall_2.png");
	wall_L->setPosition(Vec2(0-7, winSize.height / 2));
	wall_R->setPosition(Vec2(winSize.width+8, winSize.height / 2));
	this->addChild(wall_L);
	this->addChild(wall_R);
	//创建球拍
	badMinton_1 = Badmintion::create("badminton_round.png");
	badMinton_1->setPosition(Vec2(winSize.width / 2, winSize.height * 0.1));
	badMinton_1->setScaleX(1);
	this->addChild(badMinton_1, 1);
	badMinton_2 = Badmintion::create("badminton_round.png");
	badMinton_2->setPosition(Vec2(winSize.width / 2, winSize.height * 0.9));
	this->addChild(badMinton_2, 1);
	ball = Ball::create("ball_2.png");
	//ball->setScale(1);
	ball->setPosition(Vec2(winSize.width / 2, winSize.height * 0.1+10));	
	this->addChild(ball, 1);
	
	
	//响应键盘事件
	auto listener = EventListenerKeyboard::create();
	//下一行是网上找的，我也不知道=[=]什么意思，总之这么写就对了
	listener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		//log("key pressed%d",keyCode);
	//创建动作
		
		auto moveBy_R = MoveBy::create(5, Vec2(winSize.width , 0));
		auto moveBy_L = MoveBy::create(5, Vec2(-winSize.width , 0));
		switch (keyCode)
		{
		case cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE:
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_SPACE:
			//如果已经开球，则屏蔽空格键
			if(!ball->ball_Started)
			//开球
			ball->ballFly();
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		{
			
			//badMinton_1->setPosition(Vec2(badMinton_1->getPosition().x - 5, badMinton_1->getPosition().y));
			//如果还没有开始，则球跟着球拍运动
			badMinton_1->goLeft();
			break;
		}
			
		case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:

			badMinton_1->goRight();
			/*if (!(ball->ball_Started))
			{
				//Vec2 badmintion_position = badMinton_1->getPosition();
				//ball->setPosition(Vec2(badmintion_position.x, badmintion_position.y + 10));
				//ball->runAction(moveBy_R);
			}*/
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_A:
			badMinton_2->goLeft();
			break;		
		case cocos2d::EventKeyboard::KeyCode::KEY_D:
			badMinton_2->goRight();
			break;		
		case cocos2d::EventKeyboard::KeyCode::KEY_S:
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_W:
			break;
		
		default:
			break;
		}
		
	};
	listener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event)
	{
		switch (keyCode)
		{
		case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
			badMinton_1->stopAllActions();
			badMinton_1->setSpeed_X(0);
			/*if (!(ball->ball_Started))
			{
				//Vec2 badmintion_position = badMinton_1->getPosition();
				//ball->setPosition(Vec2(badmintion_position.x, badmintion_position.y + 10));
				ball->stopAllActions();
			}*/
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
			badMinton_1->stopAllActions();
			badMinton_1->setSpeed_X(0);
			/*if (!(ball->ball_Started))
			{
				//Vec2 badmintion_position = badMinton_1->getPosition();
				//ball->setPosition(Vec2(badmintion_position.x, badmintion_position.y + 10));
				ball->stopAllActions();
			}*/
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_A:
			badMinton_2->setSpeed_X(0);
			badMinton_2->stopAllActions();
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_D:
			badMinton_2->setSpeed_X(0);
			badMinton_2->stopAllActions();
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_S:
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_W:
			break;

		default:
			break;
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	schedule(CC_SCHEDULE_SELECTOR(GameLayer::update, 0),0);
	return true;
	
}
//返回键的回调函数，将分数清零，返回上一层
void GameLayer::menuCallBack(Ref * pSender)
{
	badMinton_1->scoreResume();
	badMinton_2->scoreResume();
	tsm->goToOpenScene();
}
void GameLayer::update(float delta)
{
	if (ball->ball_Started == false)
	{
		float posDown = badMinton_1->getPositionX();
		float posUp = badMinton_2->getPositionX();
		if (ball->resumeFlag == ball->downBad)
			ball->setPositionX(posDown);
		else
			ball->setPositionX(posUp);
	}
	else
	{
		ball->updatePosition();
		//和球拍1的碰撞检测
		if (std::abs(ball->getPosition().x - badMinton_1->getPosition().x) < (ball->boundingBox().size.width / 2 + badMinton_1->boundingBox().size.width / 2) &&
			(ball->getPosition().y - badMinton_1->getPosition().y) > 0
			&& (ball->getPosition().y - badMinton_1->getPosition().y) < (ball->boundingBox().size.height / 2 + badMinton_1->boundingBox().size.height / 2))
		{
			if (ball->collFlag != ball->ballToDownBad)
			{
				float speed_Y = ball->getSpeed_Yf();
				//log("%f", speed_Y);
				speed_Y = speed_Y* -1 +0.1;
				//log("%f", speed_Y);
				//log("pong!");
				ball->stopAllActions();
				ball->setSpeed_Yf(speed_Y);
				ball->setSpeed_Xf(ball->getSpeed_Xf() + badMinton_1->getSpeed_X()*0.7 / 60);
				if (ball->getSpeed_Xf() > ball->Speed_Xf_Max)
					ball->setSpeed_Xf(ball->Speed_Xf_Max);
				ball->collFlag = ball->ballToDownBad;
			}

		}
		//和球拍2的碰撞检测
		else if (std::abs(ball->getPosition().x - badMinton_2->getPosition().x) < (ball->boundingBox().size.width / 2 + badMinton_2->boundingBox().size.width / 2) &&
			(badMinton_2->getPosition().y - ball->getPosition().y) >= 0
			&& (badMinton_2->getPosition().y - ball->getPosition().y) < (ball->boundingBox().size.height / 2 + badMinton_2->boundingBox().size.height / 2))
		{
			if (ball->collFlag != ball->ballToUpBad)
			{
				ball->setSpeed_Yf(ball->getSpeed_Yf()*(-1.0f)-0.1);
				ball->setSpeed_Xf(ball->getSpeed_Xf() + badMinton_2->getSpeed_X()*0.7 / 60);
				if (ball->getSpeed_Xf() > ball->Speed_Xf_Max)
					ball->setSpeed_Xf(ball->Speed_Xf_Max);
				ball->collFlag = ball->ballToUpBad;
			}

		}
		//与墙的检测碰撞
		else if ((ball->getPosition().x - wall_L->getPosition().x) < ball->boundingBox().size.width / 2 + 1 ||
			(wall_R->getPosition().x - ball->getPosition().x) < ball->boundingBox().size.width / 2 + 1)
		{
			if (ball->collFlag != ball->ballToWall)//判断球的碰撞，防止在墙里来回弹
			{
				ball->setSpeed_Xf(ball->getSpeed_Xf()*(-1.0f));
				ball->collFlag = ball->ballToWall;
			}

		}
		//如果超出窗口则复位
		else if (ball->getPositionY() + 10 < 0)
		{
			//复位
			auto moveTo_Resume = MoveTo::create(0, Vec2(winSize.width / 2, winSize.height * 0.9 - 10));
			ball->resumeFlag = ball->upBad;
			ball->runAction(moveTo_Resume);
			ball->ball_Started = false;	//恢复空格响应
			ball->collFlag = ball->noCollision;
			//记分板加1
			badMinton_2->scoreAdded();
			char str[10] = { '0' };
			sprintf(str, "%d", badMinton_2->getScore());
			scoreLabelUp->setString(str);
			ball->resume();
		}
		else if (ball->getPositionY() - 10 > winSize.height)
		{
			//复位
			auto moveTo_Resume = MoveTo::create(0, Vec2(winSize.width / 2, winSize.height * 0.1 + 10));
			ball->resumeFlag = ball->downBad;
			ball->runAction(moveTo_Resume);
			ball->ball_Started = false;	//状态位归位（恢复空格响应）
			ball->collFlag = ball->noCollision;
			//记分板加1
			badMinton_1->scoreAdded();
			char str[10] = { '0' };
			sprintf(str, "%d", badMinton_1->getScore());
			scoreLabelDown->setString(str);
			ball->resume();
		}
	}
}


