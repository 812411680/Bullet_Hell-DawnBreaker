#ifndef SIGMA_H__
#define SIGMA_H__

#include "Enemy.h"
class Sigma :public Enemy {
public:
	Sigma(int ,int, int, int, GameWorld*);
	void Reward();
	void Attack();
};

#endif