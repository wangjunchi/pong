#include"Badmintion.h"

Badmintion * Badmintion::create(const char* filename)
{
	Badmintion * sprite = new Badmintion();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void Badmintion::goLeft()
{
	setSpeed_X(-100);	//X轴的速度
	//setSpeed_Y(0);	//Y轴的速度
	auto moveBy_Left = MoveBy::create(time, Vec2(time*speed_X,0));
	this->runAction(moveBy_Left);
}


void Badmintion::goRight()
{
	setSpeed_X(100);	//X轴的速度
	//setSpeed_Y(0);	//Y轴的速度
	auto moveBy_Right = MoveBy::create(time, Vec2( time*speed_X,0));
	this->runAction(moveBy_Right);
}
int Badmintion::getScore()
{
	return score;
}
void Badmintion::scoreAdded()
{
	score++;
	
}

void Badmintion::scoreResume()
{
	score = 0;
}