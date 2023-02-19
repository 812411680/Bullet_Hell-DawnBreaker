#ifndef POWERUP_H__
#define POWERUP_H__

#include "Props.h"
class PowerUp :public Props {
public:
	PowerUp(int x,int y, GameWorld*);
	void Check();
};

#endif // !HPRESTORE_H__
