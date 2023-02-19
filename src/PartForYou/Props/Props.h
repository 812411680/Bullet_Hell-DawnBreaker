#ifndef PROPS_H__
#define PROPS_H__
#include "GameObjects.h"
class Props :public GameObject {
public:
	Props(int ID, int x, int y, GameWorld*);
	void Move();
	void Update();
	virtual void Check()=0;
	virtual int GetDamage() { return -1; }
	virtual bool IsEnemy() { return false; }
	virtual bool IsFriend() { return false; }
};
#endif // !PROPS_H__