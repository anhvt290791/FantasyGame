#ifndef __Player__H
#include "cocos2d.h"
using namespace NS_CC;

class Player : public Node
{
private:
	Sprite* sprite;
	int index = 0;
public:
	bool init() override;

	void playAnim();
	void update(float dt) override;
	CREATE_FUNC(Player);
};

#endif // !__Player__H
