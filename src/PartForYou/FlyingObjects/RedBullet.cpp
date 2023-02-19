#include "RedBullet.h"
#include "GameWorld.h"

RedBullet::RedBullet(int damage, int x, int y, int direction, GameWorld* world) :FlyingObjects(IMGID_RED_BULLET, x, y, direction, 0.5, world, damage) {}

void RedBullet::Collision() {
	if (world->OnCollisionDawn(this)) {
		world->HPLose(GetDamage());
		status = 0;
		return;
	}
	return;
}

void RedBullet::Move() {
	Collision();
	if (status == 0)return;
	if (GetDirection() == 180) {
		MoveTo(GetX(), GetY() - 6);
	}
	else if (GetDirection() == 162) {
		MoveTo(GetX() + 2, GetY() - 6);
	}
	else{
		MoveTo(GetX() - 2, GetY() - 6);
	}
	Collision();
	//if (status == 0)return;
	return;
}