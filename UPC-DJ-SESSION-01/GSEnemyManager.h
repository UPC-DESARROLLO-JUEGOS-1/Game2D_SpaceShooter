#pragma once

#include <list>
#include <UPCFramework\NTimeInterval.h>

#include "GSBaseEnemy.h"

class GSpaceshipMain;

class GSEnemyManager
{
public:
	GSEnemyManager(GSpaceshipMain* mainGame) { mMainGame = mainGame; }
	~GSEnemyManager()
	{
		delete mMainGame;
	}

	void Initialize();
	void AddEnemy(int x, int y);
	GSBaseEnemy* SomeoneCollidedWith(GSActor* actor);

	void Update(float dt);
	void Draw(float dt);

private:
	NTimeInterval mTimeInterval;

	GSpaceshipMain* mMainGame;
	std::list<GSBaseEnemy*> mEnemies;

	void OnEndLoop_Interval();
};
