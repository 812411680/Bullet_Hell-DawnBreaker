#ifndef STAR_H__
#define STAR_H__

#include "Decoration.h"

class Star : public Decoration {
public:
    Star(int, int, double, GameWorld*);
    void Update();
};


#endif // !STAR_H__
