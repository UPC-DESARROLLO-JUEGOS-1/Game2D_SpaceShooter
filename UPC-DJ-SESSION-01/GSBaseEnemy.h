#pragma once

#include "GSActor.h"

class GSEnemyManager;

class GSBaseEnemy : public GSActor
{
public:
	GSBaseEnemy() :
		mDx(0), mDy(0), mSpeed(0),
		IsDeleted(false) {}
	~GSBaseEnemy();

	int GetDamage() { return mDamage; }

	bool IsDeleted;

	void virtual Initialize(GSEnemyManager* manager, int x, int y);
	void virtual SetDirection(float dx, float dy);

	void Update(float dt);
	void Draw(float dt);

protected:
	float mDx, mDy;
	float mSpeed;

	int mDamage;
	GSEnemyManager* mManager;

	bool virtual IsOnScreen();
};

