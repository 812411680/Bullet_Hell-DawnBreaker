#ifndef OMEGA_H__
#define OMEGA_H__

#include "Enemy.h"
class Omega :public Enemy {
public:
	Omega(int x, int y, int HP, int Speed, int ATK, GameWorld* world);
	void Reward();
	void Attack();
};

#endif // !OMEGA_H__
