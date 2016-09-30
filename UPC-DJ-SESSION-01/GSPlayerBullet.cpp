#include "GSPlayerBullet.h"

void GSPlayerBullet::Initialize(GSBulletManager* manager, const std::string path,
	int x, int y, float speed)
{
	GSBaseBullet::Initialize(manager, path, x, y, speed);

	mBulletType = Player;

	mDx = 1.0f;
	mDy = 0.0f;
}