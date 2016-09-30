#pragma once

#include <UPCFramework\NSprite.h>

class GSActor
{
public:
	GSActor() : mX(0), mY(0) {}
	~GSActor() {
		delete mSprite;
	}

	float virtual GetX() { return mX; }
	float virtual GetY() { return mY; }
	void virtual SetX(float value) { mX = value; }
	void virtual SetY(float value) { mY = value; }

	void virtual Initialize() {}
	void virtual Update(float dt) {}
	void virtual Draw(float dt) {}

protected:
	NSprite* mSprite;

	float mX;
	float mY;
};

