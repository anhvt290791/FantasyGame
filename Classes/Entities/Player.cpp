#include "Player.h"
using namespace cocos2d;
using namespace std;

bool Player::init()
{
    sprite = Sprite::create("Players/Knight/Idle/idle1.png");
    this->addChild(sprite);
    this->scheduleUpdate();
    return true;
}


void Player::update(float dt)
{
    if (index == 12)
    {
        index = 1;
    }
    else
    {
        index++;
    }
    this->removeChild(sprite);
    sprite = Sprite::create("Players/Knight/Idle/idle" + to_string(index) + ".png");
    this->addChild(sprite);
}
