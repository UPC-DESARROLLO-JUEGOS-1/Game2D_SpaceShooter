#include "GSPlayer.h"
#include "GSpaceshipMain.h"

#include <UPCFramework\NFramework.h>

GSPlayer::GSPlayer(GSpaceshipMain* mainGame)
{
	mMainGame = mainGame;
}


GSPlayer::~GSPlayer()
{
	delete mControl;
}

void GSPlayer::Initialize()
{
	mControl = new GSPlayerControl(this);
	mControl->Initialize();

	mSprite = new NSprite();
	mSprite->Initialize(mX, mY, "Sprites/spaceship.png");
	mSprite->SetRenderCamera(NFramework::GET_FRAMEWORK()->GetCamera());
	mSprite->SetScaleX(0.5f);
	mSprite->SetScaleY(0.5f);
}

void GSPlayer::CreateBullet()
{
	mMainGame->GetBulletManager()->AddPlayerBullet("Sprites/spPlayerBullet.png",
		mX, mY, 240.0f);
}

void GSPlayer::Update(float dt)
{
	int hWidth = -mSprite->GetVisibleWidth() / 2;
	int hHeight = -mSprite->GetVisibleHeight() / 2;

	mSprite->SetX(mX + hWidth);
	mSprite->SetY(mY + hHeight);
	mSprite->Update(dt);
}

void GSPlayer::Draw(float dt)
{
	mSprite->Draw(dt);
}
