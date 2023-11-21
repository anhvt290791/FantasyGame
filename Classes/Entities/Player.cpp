#include "Player.h"
using namespace cocos2d;
using namespace std;

bool Player::init()
{
    sprite = Sprite::create("Players/Knight/Idle/idle1.png");
    this->addChild(sprite);
    this->scheduleUpdate();
    currentState = State::Idle;
    // Create Listener event of Keyboard input
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(Player::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(Player::onKeyReleased, this);
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    return true;
}


void Player::update(float dt)
{
    switch (currentState)
    {
    case Idle:
        OnIdle();
        break;
    case Run:
        OnRun();
        break;
    case Attack:
        OnAttack();
        break;
    case Climb:
        OnClimb();
        break;
    case Jump:
        OnJump();
        break;
    case Walk:
        OnWalk();
        break;
    case Death:
        OnDeath();
        break;
    default:
        break;
    }
}

void Player::OnIdle()

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
    if (sprite == nullptr) return;
    this->addChild(sprite);
    Size contentSize = this->getContentSize();
    sprite->setPosition(contentSize.width / 2, contentSize.height / 2);
}

void Player::OnRun()
{
    if (index == 8)
    {
        index = 1;
    }
    else
    {
        index++;
    }
    this->removeChild(sprite);
    sprite = Sprite::create("Players/Knight/Run/run" + to_string(index) + ".png");
    if (sprite == nullptr) return;
    this->addChild(sprite);
}

void Player::OnAttack()
{
    if (index == 4)
    {
        index = 1;
    }
    else
    {
        index++;
    }
    this->removeChild(sprite);
    sprite = Sprite::create("Players/Knight/Attack/attack" + to_string(index) + ".png");
    if (sprite == nullptr) return;
    this->addChild(sprite);
}

void Player::OnClimb()
{
    if (index == 4)
    {
        index = 1;
    }
    else
    {
        index++;
    }
    this->removeChild(sprite);
    sprite = Sprite::create("Players/Knight/Climb/climb" + to_string(index) + ".png");
    if (sprite == nullptr) return;
    this->addChild(sprite);
}

void Player::OnJump()
{

    if (index == 7)
    {
        index = 1;
    }
    else
    {
        index++;
    }
    this->removeChild(sprite);
    sprite = Sprite::create("Players/Knight/Jump/jump" + to_string(index) + ".png");
    if (sprite == nullptr) return;
    this->addChild(sprite);

}

void Player::OnWalk()
{

    if (index == 6)
    {
        index = 1;
    }
    else
    {
        index++;
    }
    this->removeChild(sprite);
    sprite = Sprite::create("Players/Knight/Walk/walk" + to_string(index) + ".png");
    if (sprite == nullptr) return;
    this->addChild(sprite);
}

void Player::OnDeath()
{
    if (index == 10)
    {
        index = 1;
    }
    else
    {
        index++;
    }
    this->removeChild(sprite);
    sprite = Sprite::create("Players/Knight/Death/death" + to_string(index) + ".png");
    if (sprite == nullptr) return;
    this->addChild(sprite);
}

void Player::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW || keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
    {
        if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
        {
            this->setRotationY(180);
        }
        else
        {
            this->setRotationY(0);
        }
        index = 1;
        currentState = State::Run;
    }
    if (keyCode == EventKeyboard::KeyCode::KEY_A)
    {
        index = 1;
        currentState = State::Attack;
    }
    if (keyCode == EventKeyboard::KeyCode::KEY_C)
    {
        index = 1;
        currentState = State::Climb;
    }
    if (keyCode == EventKeyboard::KeyCode::KEY_J)
    {
        index = 1;
        currentState = State::Jump;
    }
    if (keyCode == EventKeyboard::KeyCode::KEY_W)
    {
        index = 1;
        currentState = State::Walk;
    }
    if (keyCode == EventKeyboard::KeyCode::KEY_D)
    {
        index = 1;
        currentState = State::Death;
    }
}

void Player::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    index = 1;
    currentState = State::Idle;
}