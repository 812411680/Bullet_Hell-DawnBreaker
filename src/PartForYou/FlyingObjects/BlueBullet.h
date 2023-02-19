#ifndef BLUEBULLET_H__
#define BLUEBULLET_H__
#include "FlyingObjects.h"

class Blue_Bullet : public FlyingObjects {
public:
    Blue_Bullet(int, int, int, double, GameWorld*);
    void Move();
    bool IsEnemy() { return false; }
    bool IsFriend() { return true; }
    void Collision();

};

#endif // !
