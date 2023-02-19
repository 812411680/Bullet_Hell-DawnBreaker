#include "Meteor.h"
#include "Enemy.h"
#include "GameWorld.h"

Meteor::Meteor(int x, int y, GameWorld* world) : FlyingObjects(IMGID_METEOR, x, y, 0, 2.0, world, 999999) { ID = IMGID_METEOR; }
void Meteor::Move() {
    Collision();
    MoveTo(GetX(), GetY() + 2);
    SetDirection(GetDirection() + 5);
    Collision();
    return;
}
void Meteor::Collision() {
    std::vector<Enemy*> Collision_Objects = world->CheckEnemy(this);
    for (Enemy* Collision_Object : Collision_Objects) {
        if (Collision_Object->GetStatus() == 0)continue;
        Collision_Object->GetStatus() = 0;
        Collision_Object->Reward();
    }
    return;

}