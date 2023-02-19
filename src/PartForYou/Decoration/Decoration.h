#ifndef DECORATION_H__
#define DECORATION_H__

#include <GameObjects.h>
class Decoration : public GameObject {
public:
    using GameObject::GameObject;
    int GetDamage();
    bool IsEnemy();
    bool IsFriend();
};

#endif // !DECORATION_H__



