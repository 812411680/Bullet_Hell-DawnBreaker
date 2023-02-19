#include "MeteorProp.h"
#include "GameWorld.h"
MeteorProp::MeteorProp(int x, int y, GameWorld* world) :Props(IMGID_METEOR_GOODIE, x, y, world) {}
void MeteorProp::Check() {
	if (world->OnCollisionDawn(this)) {
		world->AddMeteor();
		world->IncreaseScore(20);
		status = 0;
	}
	return;
}