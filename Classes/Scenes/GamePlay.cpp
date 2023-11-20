#ifndef __GAME_PLAY__CPP
#include "cocos2d.h";
#include "GamePlay.h";
#include "Entities/Player.h";
using namespace cocos2d;

bool GamePlay::init() 
{
	auto visualSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto sprite = Sprite::create("BG/Background.png");
	sprite->setPosition(Vec2(visualSize.width / 2 + origin.x, visualSize.height / 2 + origin.y));
	this->addChild(sprite);

	Player* player = Player::create();
	this->addChild(player);
	player->setPosition(Vec2(visualSize.width / 2 + origin.x, visualSize.height / 2 + origin.y));
	return true;
};

#endif // !__GAME_PLAY__CPP