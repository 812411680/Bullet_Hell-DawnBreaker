#ifndef EXPLOSION_H__
#define EXPLOSION_H__

#include "Decoration.h"

class Explosion : public Decoration {
public:
    Explosion(int, int, GameWorld*);
    void Update();
private:
    int tick;
};

#endif // !EXPLOSION_H__
