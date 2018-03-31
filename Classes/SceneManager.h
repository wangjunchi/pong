#pragma once
#include <iostream>
#include <cocos2d.h>
USING_NS_CC;
class SceneManager {
public:
	Scene *loadScene;
	Scene *openScene;
	Scene *gameScene;

	void createLoadScene();
	void goToOpenScene();
	void goToGameScene();
};
