#pragma once
#pragma once
#include <iostream>
#include "cocos2d.h"
#include "SceneManager.h"
USING_NS_CC;

class HelpLayer :public Layer {
public:

	CREATE_FUNC(HelpLayer);
	virtual bool init();
	void menuCallBack(Ref * pSender);
	SceneManager * tsm;

};