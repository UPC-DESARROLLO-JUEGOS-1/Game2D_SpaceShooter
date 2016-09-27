#pragma once

#include <list>

#include "GSBaseBullet.h"
#include "GSEnumBulletType.h"

class GSpaceshipMain;

class GSBulletManager
{
public:
	GSBulletManager(GSpaceshipMain* mainGame) { mMainGame = mainGame; }
	~GSBulletManager() 
	{
		delete mMainGame;
	}

	void Initialize();
	void AddPlayerBullet(std::string path,
		int x, int y, float speed);

	void Update(float dt);
	void Draw(float dt);

private:
	GSpaceshipMain* mMainGame;
	std::list<GSBaseBullet*> mBullets;
};

