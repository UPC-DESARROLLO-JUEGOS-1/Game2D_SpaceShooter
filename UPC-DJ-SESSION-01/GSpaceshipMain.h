#pragma once

#include <SDL\SDL.h>

#include "GSPlayer.h"
#include "GSBulletManager.h"
#include "GSEnemyManager.h"

class NFramework;

class GSpaceshipMain
{
public:
	GSpaceshipMain();
	~GSpaceshipMain();

	GSPlayer* GetPlayer() { return mPlayer; }
	GSBulletManager* GetBulletManager() { return mBulletManager; }
	GSEnemyManager* GetEnemyManager() { return mEnemyManager; }

	void Initialize();
	void ProcessInputs(SDL_Event evnt);

	void Update(float dt);
	void Draw(float dt);

private:
	GSPlayer* mPlayer;
	GSBulletManager* mBulletManager;
	GSEnemyManager* mEnemyManager;
};

