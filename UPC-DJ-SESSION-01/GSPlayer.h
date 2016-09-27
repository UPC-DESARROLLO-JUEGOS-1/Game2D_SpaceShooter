#pragma once

#include "GSPlayerControl.h"
#include "GSActor.h"
#include <UPCFramework\NSprite.h>

class GSpaceshipMain;

class GSPlayer : public GSActor
{
public:
	GSPlayer(GSpaceshipMain* mainGame);
	~GSPlayer();

	GSPlayerControl* GetPlayerControl() { return mControl; }

	void Initialize();
	void CreateBullet();

	void Update(float dt);
	void Draw(float dt);
private:
	GSpaceshipMain* mMainGame;
	GSPlayerControl* mControl;
};

