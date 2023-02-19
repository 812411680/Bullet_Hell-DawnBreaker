#include "_DawnBreaker.h"
#include "GameWorld.h"
#include "FlyingObjects/BlueBullet.h"
#include "FlyingObjects/Meteor.h"


_DawnBreaker::_DawnBreaker(GameWorld* world) :GameObject(IMGID_DAWNBREAKER, 300, 100, 0, 0, 1.0, world), HP(100), MP(10), N_Meteor(0), Upgrade(0) { ID = IMGID_DAWNBREAKER; }
_DawnBreaker :: ~_DawnBreaker() {}
void _DawnBreaker::Update() {
    int new_x = GetX(), new_y = GetY();
    if (HP <= 0)return;
    if (world->GetKey(KeyCode::UP)) {
        //std::cout << "up";
        new_y += 4;
    }
    if (world->GetKey(KeyCode::DOWN)) {
        new_y -= 4;
    }
    if (world->GetKey(KeyCode::LEFT)) {
        new_x -= 4;
    }
    if (world->GetKey(KeyCode::RIGHT)) {
        new_x += 4;
    }
    if (new_x >= 0 && new_x <= WINDOW_WIDTH - 1 && new_y >= 50 && new_y <= WINDOW_HEIGHT - 1) {
        MoveTo(new_x, new_y);
    }
    if (world->GetKey(KeyCode::FIRE1) && MP >= 10) {
        int damage = 5 + Upgrade * 3;
        double size = 0.5 + Upgrade * 0.1;
        world->AddObject(new Blue_Bullet(damage, GetX(), GetY() + 50, size, world));
        MP -= 10;
    }
    if (world->GetKeyDown(KeyCode::FIRE2) && N_Meteor) {
        world->AddObject(new Meteor(GetX(), GetY() + 100, world));
        N_Meteor--;
    }
    if (MP < 10)MP++;
    return;
}
int& _DawnBreaker::GetHP() {
    return HP;
}
int _DawnBreaker::GetDamage() { return 999999999; }
int& _DawnBreaker::GetMeteor() { return N_Meteor; }
int& _DawnBreaker::GetUpgrade() { return Upgrade; }