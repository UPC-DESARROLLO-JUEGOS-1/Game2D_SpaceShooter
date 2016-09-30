#include "GSSimpleEnemy.h"

#include <UPCFramework\NFramework.h>

void GSSimpleEnemy::Initialize(GSEnemyManager * manager, int x, int y)
{
	GSBaseEnemy::Initialize(manager, x, y);

	mSpeed = 160.0f;

	this->SetDirection(-1.0f, 0.0f);

	const std::string imagePath = "Sprites/spEnemySimple.png";

	mSprite = new NSprite();
	mSprite->Initialize(mX, mY, imagePath);
	mSprite->SetScaleX(0.45f);
	mSprite->SetScaleY(0.45f);
	mSprite->SetRenderCamera(NFramework::GET_FRAMEWORK()->GetCamera());
}
