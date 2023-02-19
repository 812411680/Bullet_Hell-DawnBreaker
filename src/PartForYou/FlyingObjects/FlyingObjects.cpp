#include "FlyingObjects.h"

FlyingObjects::FlyingObjects(int ID, int x, int y, int direction, double size, GameWorld* world, int damage) :damage(damage), GameObject(ID, x, y, direction, 1, size, world) {}

int FlyingObjects::GetDamage() {
	return damage;
}

void FlyingObjects::Update() {
	if (status == 0)return;
	if (GetY() >= WINDOW_HEIGHT || GetY() < 0 ) {
		status = 0;
		return;
	}
	Move();
	return;
}