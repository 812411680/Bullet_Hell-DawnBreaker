#ifndef ENEMY_H__
#define ENEMY_H__
#include "GameObjects.h"

class Enemy : public GameObject {
public:
    Enemy(int imageID, int x, int y, int HP, int MP, int Speed, int ATK, GameWorld* world);
    void Update();
    int GetDamage() { return 20; }
    bool IsEnemy() { return true; }
    bool IsFriend() { return false; }
    void Collision();
    int& GetHP();
    bool GetExplosion();
    virtual void Reward() = 0;
    virtual void Attack() = 0;
    virtual void Move();
protected:
    int HP;
    int MP;
    int Speed;
    int ATK;
    int MethodTime;
    int Method;
    bool explode = 1;
};

#endif // !ENEMY_H__
