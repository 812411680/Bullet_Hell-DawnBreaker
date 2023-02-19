#ifndef FLYINGOBJECTS_H__
#define FLYINGOBJECTS_H__
#include "GameObjects.h"
class FlyingObjects :public GameObject {
public:
	FlyingObjects(int, int, int, int, double, GameWorld *, int);
	void Update();
	int GetDamage();
	bool IsEnemy()=0;
	bool IsFriend() = 0;
	virtual void Move() = 0;
	virtual void Collision() = 0;
protected:
	int damage;
};
#endif // !FLYINGOBJECTS_H__
