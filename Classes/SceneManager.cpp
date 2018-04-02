//
//SceneManager.cpp
//Pong!
//
//created by wangjunchi 2018/1/31
//
//
/******************************************************/
/*�������Ƴ���֮���ת����ϵ���������ǵ���Directorʵ��*/
/******************************************************/
#include "SceneManager.h"
#include "LoadLayer.h"
#include "OepenLayer.h"
#include "GameLayer.h"
#include "HelpLayer.h"
//�������صĳ������ٵģ�
void SceneManager::createLoadScene()
{
	loadScene = Scene::create();
	LoadLayer *layer = LoadLayer::create();
	layer->tsm = this;   //ָ��ָ��Scene Manager�����ڵ�������Ӧ���
	loadScene->addChild(layer);
	
}
//��ת����ʼ����ĺ������ȴ�����ʼ����
void SceneManager::goToOpenScene()
{
	openScene = Scene::create();
	OpenLayer *layer = OpenLayer::create();
	layer->tsm = this; 
	openScene->addChild(layer);
	Director::getInstance()->replaceScene(openScene);  //����Director�л�����
}

//��ת����Ϸ����ĺ������ȴ�����Ϸ����
void SceneManager::goToGameScene()
{
	gameScene = Scene::create();
	GameLayer *layer = GameLayer::create();
	layer->tsm = this;
	gameScene->addChild(layer);
	Director::getInstance()->replaceScene(gameScene);

}

//��ת����������
void SceneManager::goToHelpScene()
{
	helpScene = Scene::create();
	HelpLayer *layer = HelpLayer::create();
	layer->tsm = this;
	helpScene->addChild(layer);
	Director::getInstance()->replaceScene(helpScene);
}
