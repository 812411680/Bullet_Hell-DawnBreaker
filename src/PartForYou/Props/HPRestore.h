#ifndef HPRESTORE_H__
#define HPRESTORE_H__

#include "Props.h"
class HPRestore :public Props {
public:
	HPRestore(int x,int y, GameWorld*);
	void Check();
};

#endif // !HPRESTORE_H__
