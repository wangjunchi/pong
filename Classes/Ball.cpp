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

	float temp = float(-40+ rand() %80) ;
	temp = temp/60;
	log("%f", temp);
	if (resumeFlag == downBad)
	{
		setSpeed_Yf(-1.5);
		setSpeed_Xf(temp);
	}
		
	else if (resumeFlag == upBad)
	{
		setSpeed_Yf(-1.5);
		setSpeed_Xf(temp);
	}
	ball_Started = true;
}

void Ball::updatePosition()
{
	newX = getPositionX()+speed_Xf;
	newY = getPositionY()+speed_Yf;
	setPosition(Vec2(newX, newY));
}

void Ball::resume()
{
	ball_Started = false;	//״̬λ��λ���ָ��ո���Ӧ��
	collFlag = noCollision;
	speed_Xf = 0.0;
	speed_Yf = 0.0;
}