#include "Star.h"
Star::Star(int x, int y, double size, GameWorld* world) : Decoration(IMGID_STAR, x, y, 0, 4, size, world) { ID = IMGID_STAR; }
void Star::Update() {
    if (GetY() < 0)status = 0;
    if (status == 0)return;
    MoveTo(GetX(), GetY() - 1);
    return;
}