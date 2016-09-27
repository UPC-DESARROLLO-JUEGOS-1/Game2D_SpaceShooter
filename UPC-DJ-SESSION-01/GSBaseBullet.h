#pragma once

#include <string>
#include <UPCFramework\NSprite.h>
#include <UPCFramework\NVector2D.h>

#include "GSActor.h"
#include "GSEnumBulletType.h"

class GSBulletManager;

class GSBaseBullet : public GSActor
{
public:
	GSBaseBullet() :
		mDx(0), mDy(0), mSpeed(0),
		IsDeleted(false),
		mBulletType(None) {}
	~GSBaseBullet();

	int GetDamage() { return mDamage; }

	bool IsDeleted;

	virtual void Initialize(GSBulletManager* manager, const std::string path,
		int x, int y, float speed);
	virtual void SetDirection(float dx, float dy);
	void Update(float dt);
	void Draw(float dt);

protected:
	float mDx, mDy;
	float mSpeed;

	int mDamage;
	GSEnumBulletType mBulletType;
	GSBulletManager* mManager;

	bool virtual IsOnScreen();
};

