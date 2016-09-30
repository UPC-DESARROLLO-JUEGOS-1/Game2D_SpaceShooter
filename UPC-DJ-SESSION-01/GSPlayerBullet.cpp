#include "GSPlayerBullet.h"

#include "GSBulletManager.h"
#include "GSpaceshipMain.h"

void GSPlayerBullet::Initialize(GSBulletManager* manager, const std::string path,
	int x, int y, float speed)
{
	GSBaseBullet::Initialize(manager, path, x, y, speed);

	mBulletType = Player;

	mDx = 1.0f;
	mDy = 0.0f;
}

void GSPlayerBullet::CheckCollision()
{
	GSBaseEnemy* enemyCollided = mManager->GetMainGame()->GetEnemyManager()->SomeoneCollidedWith(this);

	if (enemyCollided != nullptr) {
		this->IsDeleted = true;
		enemyCollided->IsDeleted = true;
	}
}