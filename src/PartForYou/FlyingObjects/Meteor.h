#ifndef METEOR_H__
#define METEOR_H__

#include "FlyingObjects.h"


class Meteor : public FlyingObjects {
public:
    Meteor(int, int, GameWorld*);
    void Move();
    bool IsEnemy() { return false; }
    bool IsFriend() { return true; }
    void Collision();

};


#endif // !METEOR_H__
