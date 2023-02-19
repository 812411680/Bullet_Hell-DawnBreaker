#include "Alpha.h"
#include "GameWorld.h"
#include "RedBullet.h"
#include "Explosion.h"
Alpha::Alpha(int x, int y, int HP, int Speed, int ATK, GameWorld* world) :Enemy(IMGID_ALPHATRON, x, y, HP, 25, Speed, ATK, world) {}
void Alpha::Reward() {
    world->IncreaseScore(50);
    world->AddKilled();
    world->AddObject(new Explosion(GetX(), GetY(), world));
    return;
}
void Alpha::Attack() {
    if (world->GetDistanceDawn(this, Options::Option_X)<=10 && MP>=25) {
        if (randInt(1, 4) == 2) {
            MP -= 25;
            world->AddObject(new RedBullet(ATK, GetX(), GetY() - 50, 180, world));
        }
    }
    if (MP < 25)MP++;
    return;
}
