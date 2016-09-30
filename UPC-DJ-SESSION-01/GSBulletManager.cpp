#include "GSBulletManager.h"
#include "GSPlayerBullet.h"
#include "GSEnemyBullet.h"

#include <iostream>

void GSBulletManager::Initialize()
{
}

void GSBulletManager::AddPlayerBullet(const std::string path,
	int x, int y, float speed)
{
	GSPlayerBullet* bullet = new GSPlayerBullet();
	bullet->Initialize(this, path, x, y, speed);

	mBullets.push_back(bullet);
}

void GSBulletManager::Update(float dt)
{
	std::list<GSBaseBullet*>::iterator i = mBullets.begin();
	while (i != mBullets.end())
	{
		GSBaseBullet* bullet = (*i);

		if (!bullet->IsDeleted) {
			bullet->Update(dt);
			++i;
		}
		else {
			// destruir el objecto bullet::: investigar como!!!!
 			i = mBullets.erase(i);
			std::cout << "erase bullet";
		}
	}
}

void GSBulletManager::Draw(float dt)
{
	std::list<GSBaseBullet*>::iterator i = mBullets.begin();
	while (i != mBullets.end())
	{
		GSBaseBullet* bullet = (*i);

		if (!bullet->IsDeleted) {
			bullet->Draw(dt);
		}

		++i;
	}
}
