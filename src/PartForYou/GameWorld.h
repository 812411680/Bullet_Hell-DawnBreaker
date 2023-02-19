#ifndef GAMEWORLD_H__
#define GAMEWORLD_H__

#include <list>

#include "WorldBase.h"
#include "GameObjects.h"
#include "Enemy.h"
enum class Options {
    Option_S,
    Option_X,
    Option_Y
};
class _DawnBreaker;
class GameWorld : public WorldBase {
public:
    GameWorld();
    virtual ~GameWorld();

    virtual void Init() override;

    virtual LevelStatus Update() override;

    virtual void CleanUp() override;

    virtual bool IsGameOver() const override;

    void Generate_star();

    void AddKilled();

    void AddObject(GameObject*);

    void HPLose(int damage);

    int GetDistance(GameObject*, GameObject*);

    int GetDistanceDawn(GameObject*, Options);

    bool OnCollision(GameObject*, GameObject*);

    std::vector<GameObject*> CheckCollision(GameObject*);

    std::vector<Enemy*> CheckEnemy(GameObject*);

    bool OnCollisionDawn(GameObject*);

    void GenerateEnemy();

    void BulletUpgrade();

    void AddMeteor();

    int GetHP();


private:
    std::list<GameObject*> GameObjects;
    _DawnBreaker* DawnBreaker;
    int Hearts;
    int killed;
    int onScreen;
    int required;
    int maxOnScreen;
    int toDestroy, allowed;
};

#endif // !GAMEWORLD_H__
