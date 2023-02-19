#ifndef GAMEOBJECTS_H__
#define GAMEOBJECTS_H__

#include "ObjectBase.h"

class GameWorld;
class GameObject : public ObjectBase {
public:
    GameObject(int imageID, int x, int y, int direction, int layer, double size, GameWorld *);
    virtual ~GameObject();
    int& GetStatus();
    int GetID();
    virtual int GetDamage()=0;
    virtual bool IsEnemy()=0;
    virtual bool IsFriend() = 0;
    virtual void Update() = 0;
protected:
    int status=1;
    int ID;
    GameWorld* world;
};


#endif // GAMEOBJECTS_H__