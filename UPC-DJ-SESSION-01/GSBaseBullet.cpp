#include "GSBaseBullet.h"

#include <UPCFramework\NFramework.h>

GSBaseBullet::~GSBaseBullet()
{
	delete mManager;
}

void GSBaseBullet::Initialize(GSBulletManager* manager, const std::string path,
	int x, int y, float speed)
{
	GSActor::Initialize();

	mManager = manager;
	mX = x;
	mY = y;
	mSpeed = speed;

	mSprite = new NSprite();
	mSprite->Initialize(mX, mY, path);
	mSprite->SetRenderCamera(NFramework::GET_FRAMEWORK()->GetCamera());
}

void GSBaseBullet::SetDirection(float dx, float dy) {
	mDx = dx;
	mDy = dy;
}

bool GSBaseBullet::IsOnScreen() {
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

void GSBaseBullet::Update(float dt)
{
	mX += mDx * (mSpeed * dt);
	mY += mDy * (mSpeed * dt);

	mSprite->SetX(mX);
	mSprite->SetY(mY);
	mSprite->Update(dt);

	this->IsDeleted = !IsOnScreen();

	CheckCollision();
}

void GSBaseBullet::Draw(float dt) {
	mSprite->Draw(dt);
}
