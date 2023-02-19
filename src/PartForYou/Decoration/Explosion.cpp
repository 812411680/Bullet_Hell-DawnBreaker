#include "Explosion.h"

Explosion::Explosion(int x, int y, GameWorld* world) : tick(0), Decoration(IMGID_EXPLOSION, x, y, 0, 3, 4.5, world) { ID = IMGID_EXPLOSION; }
void Explosion::Update() {
    if (status == 0)return;
    tick++;
    SetSize(GetSize() - 0.2);
    if (tick >= 20) status = 0;
    return;
}
