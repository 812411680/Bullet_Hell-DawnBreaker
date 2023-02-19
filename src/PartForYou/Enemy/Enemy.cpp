#include "Enemy.h"
#include "GameWorld.h"
#include "Explosion.h"

Enemy::Enemy(int imageID, int x, int y, int HP, int MP, int Speed, int ATK, GameWorld* world) : Method(0), MethodTime(0), HP(HP), MP(MP), Speed(Speed), ATK(ATK), GameObject(imageID, x, y, 180, 0, 1.0, world) {}
void Enemy::Update() {
    if (status == 0)return;
    if (GetY() < 0 || HP <= 0) {
        status = 0;
        return;
    }
    Collision();
    if (status == 0)return;
    Attack();
    Move();
    Collision();
    return;
}


void Enemy::Collision() {

    std::vector<GameObject*> Collision_Objects = world->CheckCollision(this);
    for (auto Collision_Object : Collision_Objects) {
        if (Collision_Object->GetID() == IMGID_METEOR && Collision_Object->GetStatus() == 1) {
            status = 0;
            Reward();
            return;
        }
        if (Collision_Object->GetID() == IMGID_BLUE_BULLET && Collision_Object->GetStatus() == 1) {
            Collision_Object->GetStatus() = 0;
            HP -= Collision_Object->GetDamage();
            if (HP <= 0) {
                status = 0;
                Reward();
                return;
            }
        }
    }
    if (world->OnCollisionDawn(this) && status == 1) {
        world->HPLose(20);
        status = 0;
        Reward();
        return;
    }
    return;
}
void Enemy::Move() {
    if (MethodTime == 0) {
        Method = randInt(1, 3);
        MethodTime = randInt(10, 50);
    }
    if (GetX() < 0) {
        Method = 3;
        MethodTime = randInt(10, 50);
    }
    if (GetX() >= WINDOW_WIDTH) {
        Method = 2;
        MethodTime = randInt(10, 50);
    }
    MethodTime--;
    if (Method == 1) {
        MoveTo(GetX(), GetY() - Speed);
    }
    else if (Method == 2) {
        MoveTo(GetX() - Speed, GetY() - Speed);
    }
    else if (Method == 3) {
        MoveTo(GetX() + Speed, GetY() - Speed);
    }

    return;
}

int& Enemy::GetHP() {
    return HP;
}

bool Enemy::GetExplosion() {
    return explode;
}