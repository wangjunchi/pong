#pragma once
#include <iostream>
#include "cocos2d.h"
#include "SceneManager.h"
USING_NS_CC;

class Badmintion :public Sprite {
private:
	float speed_X = 0;
	float speed_Y = 0;
	float time = 100.0f;//球拍运动的时间
	int collisionFlag = 0;
	int score=0;
public:
	int getScore();
	void scoreResume();
	void scoreAdded();
	Size winSize = Director::getInstance()->getWinSize();
	static Badmintion* create(const char*);//重载  
	void goLeft();
	void goRight();
	float getSpeed_X()
	{
		return speed_X;
	}
	float getSpeed_Y()
	{
		return speed_Y;
	}
	void setSpeed_X(int s)
	{
		speed_X = s;
	}
	void setSpeed_Y(int s)
	{
		speed_Y = s;
	}
};