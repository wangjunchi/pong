#include<Ball.h>

//create����������
Ball* Ball::create(const char* filename)
{
	Ball * sprite = new Ball();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

//����
void Ball::ballFly()
{
	srand(GetTickCount());

	float temp = float(-20+ rand() %40) ;
	temp = temp/60;
	log("%f", temp);
	//int CurrentX = getPositionX();
	//int CurrentY = getPositionY();
	//setSpeed_Xf(random(-30,30));	//X����ٶ�
	if (resumeFlag == downBad)
	{
		setSpeed_Y(100);	//Y����ٶ�
		setSpeed_Yf(1.5);
		setSpeed_Xf(temp);
	}
		
	else if (resumeFlag == upBad)
	{
		setSpeed_Y(-100);	//Y����ٶ�
		setSpeed_Yf(-1.5);
		setSpeed_Xf(temp);
	}
	ball_Started = true;
}

void Ball::updatePosition()
{
	float newX = getPositionX()+speed_Xf;
	float newY = getPositionY()+speed_Yf;
	setPosition(Vec2(newX, newY));
}

void Ball::resume()
{
	speed_Xf = 0.0;
	speed_Yf = 0.0;
}