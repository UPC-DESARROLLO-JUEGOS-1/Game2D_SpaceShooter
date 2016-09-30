#include "GSEnemyBullet.h"

void GSEnemyBullet::Initialize(GSBulletManager* manager, const std::string path,
	int x, int y, float speed, int targetX, int targetY)
{
	GSBaseBullet::Initialize(manager, path, x, y, speed);

	mBulletType = Enemy;
	mTargetX = targetX;
	mTargetY = targetY;

	NVector2D* thisObject = new NVector2D(x, y);
	NVector2D* otherObject = new NVector2D(targetX, targetY);
	NVector2D result = thisObject->Direction(*otherObject);

	mDx = result.X;
	mDy = result.Y;
}

void GSEnemyBullet::Update(float dt)
{
	GSBaseBullet::Update(dt);
}