#pragma once
#include <iostream>
#include "cocos2d.h"
#include "SceneManager.h"
USING_NS_CC;


class LoadLayer :public Layer {  
public:
	CREATE_FUNC(LoadLayer);
	virtual bool init();  
	void onScheduleOnce(float dt);
	SceneManager * tsm;
};