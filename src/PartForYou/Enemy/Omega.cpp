#include "Omega.h"
#include "GameWorld.h"
#include "RedBullet.h"
#include "PowerUp.h"
#include "MeteorProp.h"
#include "Explosion.h"
Omega::Omega(int x, int y, int HP, int Speed, int ATK, GameWorld* world) :Enemy(IMGID_OMEGATRON, x, y, HP, 50, Speed, ATK, world){}
void Omega::Reward() {
    world->IncreaseScore(200);
    world->AddKilled();
    if (randInt(1, 5) <= 2) {
        if (randInt(1, 5) !=5 ) {
            world->AddObject(new PowerUp(GetX(), GetY(), world));
        }
        else {
            world->AddObject(new MeteorProp(GetX(), GetY(), world));
        }
    }
    world->AddObject(new Explosion(GetX(), GetY(), world));
    return;
}
void Omega::Attack() {
    if (MP == 50) {
        MP = 0;
        world->AddObject(new RedBullet(ATK, GetX(), GetY() - 50, 162, world));
        world->AddObject(new RedBullet(ATK, GetX(), GetY() - 50, 198, world));
    }
    if (MP < 50)MP++;
    return;
}