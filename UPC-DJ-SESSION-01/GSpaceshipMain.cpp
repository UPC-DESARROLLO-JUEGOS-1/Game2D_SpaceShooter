#include "GSpaceshipMain.h"


GSpaceshipMain::GSpaceshipMain()
{
}

GSpaceshipMain::~GSpaceshipMain()
{
	delete mPlayer;
	delete mBulletManager;
	delete mEnemyManager;
}

void GSpaceshipMain::Initialize()
{
	mEnemyManager = new GSEnemyManager(this);
	mEnemyManager->Initialize();
	mEnemyManager->AddEnemy(700, 200);

	mBulletManager = new GSBulletManager(this);
	mBulletManager->Initialize();

	mPlayer = new GSPlayer(this);
	mPlayer->Initialize();
}

void GSpaceshipMain::ProcessInputs(SDL_Event evnt)
{
	mPlayer->GetPlayerControl()->ProcessInputs(evnt);
}

void GSpaceshipMain::Update(float dt)
{
	mEnemyManager->Update(dt);
	mBulletManager->Update(dt);
	mPlayer->Update(dt);
}

void GSpaceshipMain::Draw(float dt)
{
	mEnemyManager->Draw(dt);
	mBulletManager->Draw(dt);
	mPlayer->Draw(dt);
}
