#pragma once
#include <iostream>
#include "cocos2d.h"
#include "SceneManager.h"
USING_NS_CC;

class Ball :public Sprite
{
private:
	float speed_X = 0;
	float speed_Y = 0;
	float speed_Xf;
	float speed_Yf;
	float time = 10.0f;//球运动的时间
public:
	const float Speed_X_Max = 240.0f;
	const float Speed_Y_Max = 240.0f;
	const float Speed_Xf_Max = 3.5f;
	const float Speed_Yf_Max = 2.0f;
	//球的碰撞状态
	enum collision { noCollision, ballToWall, ballToDownBad, ballToUpBad };  	
	collision collFlag = noCollision;
	//球的复位状态
	enum resume {upBad, downBad};
	resume resumeFlag = downBad;
	bool ball_Started = false;
	Size winSize = Director::getInstance()->getWinSize();
	static Ball* create(const char*);//重载  
	void ballFly();
	void updatePosition();
	void resume();
	float getSpeed_X()
	{
		return speed_X;
	}
	float getSpeed_Y()
	{
		return speed_Y;
	}
	float getSpeed_Xf()
	{
		return speed_Xf;
	}
	float getSpeed_Yf()
	{
		return speed_Yf;
	}
	void setSpeed_X(float s)
	{
		speed_X = s;
	}
	void setSpeed_Y(float s)
	{
		speed_Y = s;
	}
	void setSpeed_Xf(float s)
	{
		speed_Xf = s;
	}
	void setSpeed_Yf(float s)
	{
		speed_Yf = s;
	}
};