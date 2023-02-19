#include "Sigma.h"
#include "GameWorld.h"
#include "HPRestore.h"
#include "Explosion.h"
Sigma::Sigma(int x, int y, int HP, int Speed, GameWorld* world) :Enemy(IMGID_SIGMATRON, x, y, HP, 0, Speed, 0, world) {}
void Sigma::Reward() {
	world->IncreaseScore(100);
	world->AddKilled();
	if (randInt(1, 5) == 1)
		world->AddObject(new HPRestore(GetX(), GetY(), world));
	world->AddObject(new Explosion(GetX(), GetY(), world));
}
void Sigma::Attack() {
	if (world->GetDistanceDawn(this, Options::Option_X)<=10) {
		Method = 1;
		MethodTime = WINDOW_HEIGHT;
		Speed = 10;
	}
	return;
}