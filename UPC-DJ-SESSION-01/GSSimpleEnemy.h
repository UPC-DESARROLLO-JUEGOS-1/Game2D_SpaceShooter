#pragma once

#include "GSBaseEnemy.h"

class GSSimpleEnemy : public GSBaseEnemy
{
public:
	GSSimpleEnemy() {}
	~GSSimpleEnemy() {}

	void Initialize(GSEnemyManager * manager, int x, int y);
};

