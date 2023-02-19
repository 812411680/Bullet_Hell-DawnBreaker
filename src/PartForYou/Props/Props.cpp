#include "Props.h"
Props::Props(int ID, int x, int y, GameWorld* world) :GameObject(ID, x, y, 0, 2, 0.5, world) {}
void Props::Move() {
	MoveTo(GetX(), GetY() - 2);
	return;
}
void Props::Update() {
	if (status == 0)return;
	if (GetY() < 0) {
		status = 0;
		return;
	}
	Check();
	if (status == 0)return;
	Move();
	Check();
	return;
}