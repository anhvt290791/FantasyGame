#ifndef __Player__H
#include "cocos2d.h"
#include "./Base/Entity.h"
using namespace NS_CC;

class Player : public Node
{
private:
	Sprite* sprite;
	int index = 0;
	State currentState;
	

	void OnIdle();
	void OnRun();
	void OnAttack();
	void OnClimb();
	void OnJump();
	void OnWalk();
	void OnDeath();
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

public:
	bool init() override;
	void update(float dt) override;

	CREATE_FUNC(Player);
};

#endif // !__Player__H
