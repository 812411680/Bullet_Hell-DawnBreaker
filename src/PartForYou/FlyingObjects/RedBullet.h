#ifndef REDBULLET_H__
#define REDBULLET_H__

#include "FlyingObjects.h"
class RedBullet :public FlyingObjects {
public:
	RedBullet(int, int, int, int, GameWorld*);
	void Move();
	bool IsEnemy() { return false; }
	bool IsFriend() { return false; }
	void Collision();
};

#endif // !REDBULLET_H__
