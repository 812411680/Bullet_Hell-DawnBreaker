#include "GameWorld.h"


#ifndef A_
#define A_
#include <algorithm>
#endif

#include "Star.h"
#include "Explosion.h"
#include "Alpha.h"
#include "Sigma.h"
#include "Omega.h"
#include "BlueBullet.h"
#include "Meteor.h"
#include "_DawnBreaker.h"


GameWorld::GameWorld(): WorldBase(),Hearts(3),killed(0),DawnBreaker(nullptr) {

}

GameWorld::~GameWorld() {
  
}

void GameWorld::Init() {
    killed = 0;
    onScreen = 0;
    required = 3 * GetLevel();
    maxOnScreen = (int)((5 + GetLevel()) / 2);
    toDestroy = required;
    DawnBreaker = new _DawnBreaker(this);
    Generate_star();
    return;
}

LevelStatus GameWorld::Update() {
    if (randInt(1, 30) == 11)AddObject(new Star(randInt(0, WINDOW_WIDTH - 1), WINDOW_HEIGHT - 1, randInt(10, 40) / 100.0, this));
    GenerateEnemy();
    DawnBreaker->Update();
    for (auto Object : GameObjects) {
        Object->Update();
    }
    if (DawnBreaker->GetHP() <= 0) {
        Hearts -= 1;
        return LevelStatus::DAWNBREAKER_DESTROYED;
    }
    if (killed >= 3 * GetLevel()) return LevelStatus::LEVEL_CLEARED;
    std::list<GameObject*> ToRemove;
    for (auto Object : GameObjects) {
        if (Object->GetStatus() == 0) {
            if (Object->IsEnemy() && Object->IsFriend() == false) {
                onScreen--;
                //if(((Enemy*)Object)->GetExplosion())AddObject(new Explosion(Object->GetX(), Object->GetY(), this));
            }
            delete Object;
            ToRemove.push_back(Object);
        }
    }
    for (auto Object : ToRemove) {
        GameObjects.remove(Object);
    }
    
    std::string HP_S = std::string("HP: ")+std::to_string(DawnBreaker->GetHP()) + std::string("/100   ");
    std::string Meteor_S = std::string("Meteors: ") + std::to_string(DawnBreaker->GetMeteor()) + std::string("   ");
    std::string Lives_S = std::string("Lives: ") + std::to_string(Hearts) + std::string("   ");
    std::string Level_S=std::string("Level: ") + std::to_string(GetLevel()) + std::string("   ");
    std::string Enemies_S = std::string("Enemies: ") + std::to_string(killed) + std::string("/")+ std::to_string(required) +std::string("   ");
    std::string Score_S = std::string("Score: ") + std::to_string(GetScore())+std::string("\n");
    SetStatusBarMessage(HP_S + Meteor_S + Lives_S + Level_S + Enemies_S + Score_S);
    return LevelStatus::ONGOING;
}

void GameWorld::CleanUp() {
    for (auto Object : GameObjects) {
        delete Object;
    }
    GameObjects.clear();
    delete DawnBreaker;
    return;
}


bool GameWorld::IsGameOver() const {
    //std::cout << "Hearts" << Hearts << std::endl;
    if (Hearts == 0) {
        return true;
    }
    return false;
}

void GameWorld::Generate_star() {
    int x, y;
    double size;
    for (int i = 0; i < 30; i++) {
        x = randInt(0, WINDOW_WIDTH - 1);
        y = randInt(0, WINDOW_HEIGHT - 1);
        size = randInt(10, 40) / 100.0;
        AddObject(new Star(x, y, size,this));
    }
    return;
}

void GameWorld::AddKilled() {
    killed++;
}

void GameWorld::AddObject(GameObject *New_Object) {
    this->GameObjects.push_back(New_Object);
}

void GameWorld::HPLose(int damage) {
    DawnBreaker->GetHP() -= damage;
    if (DawnBreaker->GetHP() > 100)DawnBreaker->GetHP() = 100;
    return;
}

int GameWorld::GetDistance(GameObject* Object_a, GameObject* Object_b) {
    double distance = sqrt(pow((Object_a->GetX() - Object_b->GetX()), 2) + pow((Object_a->GetY() - Object_b->GetY()), 2));
    return distance;
}

int GameWorld::GetDistanceDawn(GameObject* Object, Options option) {
    if(option==Options::Option_S) return GetDistance(Object, DawnBreaker);
    else if (option == Options::Option_X) return abs(Object->GetX() - DawnBreaker->GetX());
    else if (option == Options::Option_Y) return abs(Object->GetY() - DawnBreaker->GetY());
    else return 0;
}

bool GameWorld::OnCollision(GameObject *Object_a, GameObject *Object_b) {
    double distance = GetDistance(Object_a, Object_b);
    if (distance < 30.0 * ( Object_a->GetSize() + Object_b->GetSize()) ) {
        return true;
    }
    return false;
}

bool GameWorld::OnCollisionDawn(GameObject *Object) {
    return OnCollision(Object, DawnBreaker);
}

std::vector<GameObject*> GameWorld::CheckCollision(GameObject* Object_a) {
    std::vector<GameObject*> CoObjects;
    for (auto Object : GameObjects) {
        if (Object == Object_a || Object->IsEnemy()==Object_a->IsEnemy() && Object->IsFriend()==Object_a->IsFriend()) {
            continue;
        }
        if (OnCollision(Object_a, Object)) {
            CoObjects.push_back(Object);
        }
    }
    return CoObjects;
}

std::vector<Enemy*> GameWorld:: CheckEnemy(GameObject* Object_a) {
    std::vector<Enemy*> CoObjects;
    for (auto Object : GameObjects) {
        if (Object == Object_a || Object->IsEnemy() == false || Object->IsFriend() == true) {
            continue;
        }
        if (OnCollision(Object_a, Object)) {
            CoObjects.push_back((Enemy*)Object);
        }
    }
    return CoObjects;
}

void GameWorld::GenerateEnemy() {
    int P1 = 6, P2 = 2 * std::max(GetLevel() - 1, 0), P3 = 3 * std::max(GetLevel() - 2, 0);
    int RandN;
    toDestroy = required - killed;
    allowed = std::min(toDestroy, maxOnScreen);
    //std::cout << required<<" " << allowed << " " << maxOnScreen << " " << onScreen << std::endl;
    if (allowed > onScreen) {
        if (randInt(1, 100) <= allowed - onScreen) {
            RandN = randInt(1, P1 + P2 + P3);
            onScreen++;
            if (RandN <= P1) {
                GameObjects.push_back(new Alpha(randInt(0, WINDOW_WIDTH - 1), WINDOW_HEIGHT - 1, 20 + 2 * GetLevel(), 2 + (int)(GetLevel() / 5), 4 + GetLevel(), this));
            }
            else if (RandN > P1 && RandN <= P1 + P2) {
                GameObjects.push_back(new Sigma(randInt(0, WINDOW_WIDTH - 1), WINDOW_HEIGHT - 1, 25 + 5 * GetLevel(), 2 + (int)(GetLevel() / 5), this));
            }
            else {
                GameObjects.push_back(new Omega(randInt(0, WINDOW_WIDTH - 1), WINDOW_HEIGHT - 1, 20 + GetLevel(), 3 + (int)(GetLevel() / 4), 2 + 2 * GetLevel(), this));
            }
        }
    }
}
void GameWorld::BulletUpgrade() {
    DawnBreaker->GetUpgrade()++;
}
void GameWorld::AddMeteor() {
    DawnBreaker->GetMeteor()++;
}

int GameWorld::GetHP() {
    return DawnBreaker->GetHP();
}