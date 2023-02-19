#include "BlueBullet.h"
#include "GameWorld.h"
#include "Enemy.h"
Blue_Bullet::Blue_Bullet(int damage, int x, int y, double size, GameWorld* world) : FlyingObjects(IMGID_BLUE_BULLET, x, y, 0, size, world, damage) { ID = IMGID_BLUE_BULLET; }
void Blue_Bullet::Move() {
    Collision();
    if (status == 0)return;
    MoveTo(GetX(), GetY() + 6);
    Collision();
    return;
}

void Blue_Bullet::Collision() {
    std::vector<Enemy*> Collision_Objects = world->CheckEnemy(this);
    for (auto Collision_Object : Collision_Objects) {
        if (Collision_Object->GetStatus() == 0)continue;
        Collision_Object->GetHP() -= damage;
        if (Collision_Object->GetHP() <= 0) {
            Collision_Object->GetStatus() = 0;
            Collision_Object->Reward();
        }
        status = 0;
        break;
    }
    return;
}
