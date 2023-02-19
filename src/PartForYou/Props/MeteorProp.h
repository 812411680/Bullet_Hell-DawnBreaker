#ifndef METEORPROP_H__
#define METEORPROP_H__

#include "Props.h"
class MeteorProp :public Props {
public:
	MeteorProp(int x,int y, GameWorld*);
	void Check();
};

#endif // !HPRESTORE_H__
