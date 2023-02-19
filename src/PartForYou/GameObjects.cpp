#include "GameObjects.h"
#include "GameWorld.h"

GameObject :: GameObject(int imageID, int x, int y, int direction, int layer, double size, GameWorld *world):world(world),ObjectBase(imageID, x, y, direction, layer, size){}
int& GameObject::GetStatus() {
    return status;
}
int GameObject::GetID() {
    return ID;
}

GameObject :: ~GameObject(){}

