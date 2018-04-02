//
//SceneManager.cpp
//Pong!
//
//created by wangjunchi 2018/1/31
//
//
/******************************************************/
/*用来控制场景之间的转换关系，本质是是调用Director实现*/
/******************************************************/
#include "SceneManager.h"
#include "LoadLayer.h"
#include "OepenLayer.h"
#include "GameLayer.h"
#include "HelpLayer.h"
//创建加载的场景（假的）
void SceneManager::createLoadScene()
{
	loadScene = Scene::create();
	LoadLayer *layer = LoadLayer::create();
	layer->tsm = this;   //指针指向Scene Manager，便于调用以响应点击
	loadScene->addChild(layer);
	
}
//跳转到开始界面的函数，先创建开始场景
void SceneManager::goToOpenScene()
{
	openScene = Scene::create();
	OpenLayer *layer = OpenLayer::create();
	layer->tsm = this; 
	openScene->addChild(layer);
	Director::getInstance()->replaceScene(openScene);  //调用Director切换场景
}

//跳转到游戏界面的函数，先创建游戏场景
void SceneManager::goToGameScene()
{
	gameScene = Scene::create();
	GameLayer *layer = GameLayer::create();
	layer->tsm = this;
	gameScene->addChild(layer);
	Director::getInstance()->replaceScene(gameScene);

}

//跳转到帮助界面
void SceneManager::goToHelpScene()
{
	helpScene = Scene::create();
	HelpLayer *layer = HelpLayer::create();
	layer->tsm = this;
	helpScene->addChild(layer);
	Director::getInstance()->replaceScene(helpScene);
}
