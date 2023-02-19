#include "PowerUp.h"
#include "GameWorld.h"
PowerUp::PowerUp(int x, int y, GameWorld* world) :Props(IMGID_POWERUP_GOODIE, x, y, world) {}
void PowerUp::Check() {
	if (world->OnCollisionDawn(this)) {
		world->BulletUpgrade();
		world->IncreaseScore(20);
		status = 0;
	}
	return;
}