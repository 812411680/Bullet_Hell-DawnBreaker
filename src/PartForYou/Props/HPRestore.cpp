#include "HPRestore.h"
#include "GameWorld.h"
HPRestore::HPRestore(int x, int y, GameWorld* world) :Props(IMGID_HP_RESTORE_GOODIE, x, y, world) {}
void HPRestore::Check() {
	if (world->OnCollisionDawn(this)) {
		world->HPLose(-50);
		world->IncreaseScore(20);
		status = 0;
	}
}