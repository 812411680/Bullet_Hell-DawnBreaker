#ifndef _DAWNBREAKER_H__
#define _DAWNBREAKER_H__

#include "GameObjects.h"

class _DawnBreaker : public GameObject {
public:
    _DawnBreaker(GameWorld*);
    ~_DawnBreaker();
    //bool operator==(const ObjectBase& other);
    void Update();
    int& GetHP();
    int GetDamage();
    int& GetMeteor();
    int& GetUpgrade();
    bool IsEnemy() { return false; }
    bool IsFriend() { return true; }
private:
    int HP;
    int MP;
    int N_Meteor;
    int Upgrade;
};

#endif