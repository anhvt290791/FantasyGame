#ifndef __Player__H
#include "cocos2d.h"
using namespace NS_CC;

class Player : public Node
{
public:
	bool init() override;
	CREATE_FUNC(Player);
};

#endif // !__Player__H
