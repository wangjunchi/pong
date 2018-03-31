#include "LoadLayer.h"
bool LoadLayer::init()
{
	Label *label = Label::createWithTTF("Loading......", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(240, 180));
	this->addChild(label);
	scheduleOnce(CC_SCHEDULE_SELECTOR(LoadLayer::onScheduleOnce), 2);
	return true;
}

void LoadLayer::onScheduleOnce(float dt)
{
	tsm->goToOpenScene();
}