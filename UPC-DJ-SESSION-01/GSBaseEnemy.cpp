#include "GSBaseEnemy.h"

#include <UPCFramework\NFramework.h>

GSBaseEnemy::~GSBaseEnemy()
{
	delete mManager;
}

void GSBaseEnemy::Initialize(GSEnemyManager * manager, int x, int y)
{
	GSActor::Initialize();

	mManager = manager;
	mX = x;
	mY = y;
}

void GSBaseEnemy::SetDirection(float dx, float dy) {
	mDx = dx;
	mDy = dy;
}

bool GSBaseEnemy::IsOnScreen()
{
	bool result = true;

	NFramework* frk = NFramework::GET_FRAMEWORK();

	if ((mX + mSprite->GetVisibleWidth()) < 0 ||    // left
		mX > frk->GetWindow()->GetScreenWidth() ||  // right
		(mY + mSprite->GetVisibleHeight()) < 0 ||   // up
		mY > frk->GetWindow()->GetScreenHeight()) { // down

		result = false;
	}

	return result;
}

void GSBaseEnemy::Update(float dt)
{
	mX += mDx * (mSpeed * dt);
	mY += mDy * (mSpeed * dt);

	mSprite->SetX(mX);
	mSprite->SetY(mY);
	mSprite->Update(dt);

	this->IsDeleted = !IsOnScreen();
}

void GSBaseEnemy::Draw(float dt)
{
	mSprite->Draw(dt);
}

