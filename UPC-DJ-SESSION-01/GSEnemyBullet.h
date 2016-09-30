#pragma once


#include "GSBaseBullet.h"

class GSEnemyBullet : public GSBaseBullet
{
public:
	GSEnemyBullet() { GSBaseBullet::GSBaseBullet(); }
	~GSEnemyBullet() { GSBaseBullet::~GSBaseBullet(); }

	void Initialize(GSBulletManager* manager, const std::string path,
		int x, int y, float speed, int targetX, int targetY);
	void Update(float dt);

private:
	float mTargetX;
	float mTargetY;
};
