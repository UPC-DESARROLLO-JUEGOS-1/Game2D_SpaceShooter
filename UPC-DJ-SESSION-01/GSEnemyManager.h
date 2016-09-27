#pragma once

#include <list>

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

	void Update(float dt);
	void Draw(float dt);

private:
	GSpaceshipMain* mMainGame;
	std::list<GSBaseEnemy*> mEnemies;
};
