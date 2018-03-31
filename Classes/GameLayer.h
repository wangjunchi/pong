#pragma once
#include <iostream>
#include "cocos2d.h"
#include "SceneManager.h"
#include "Ball.h"
#include "Badmintion.h"
USING_NS_CC;

class GameLayer :public Layer {
public:
	CREATE_FUNC(GameLayer);
	virtual bool init();
	void update(float delta);
	void update_2(float dalta);
	//void update2(float delta);
	void menuCallBack(Ref *pSender);
	
public:
	//获取窗口大小
	Size winSize = Director::getInstance()->getWinSize();
	SceneManager *tsm;
	Sprite * backGround;
	Sprite * wall_L;
	Sprite * wall_R;
	Ball * ball;
	Badmintion * badMinton_1;
	Badmintion * badMinton_2;
	Label *scoreLabelUp;
	Label *scoreLabelDown;
};