#pragma once

#include "GSBaseBullet.h"

class GSBulletManager;

class GSPlayerBullet : public GSBaseBullet
{
public:
	GSPlayerBullet() { }
	~GSPlayerBullet() { GSBaseBullet::~GSBaseBullet(); }

	void Initialize(GSBulletManager* manager, const std::string path,
		int x, int y, float speed);

protected:
	void CheckCollision();
};

