#pragma once
#include <iostream>
#include "cocos2d.h"
#include "SceneManager.h"
USING_NS_CC;

class OpenLayer :public Layer {
public:
	CREATE_FUNC(OpenLayer);
	virtual bool init();
	void menuCallBack(Ref * pSender);
	SceneManager * tsm;

};