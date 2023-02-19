#ifndef ALPHA_H__
#define ALPHA_H__
#include "Enemy.h"

class Alpha : public Enemy {
public:
    Alpha(int x, int y, int HP, int Speed, int ATK, GameWorld* world);
    void Reward();
    void Attack();
};
#endif // !ALPHA_H__
