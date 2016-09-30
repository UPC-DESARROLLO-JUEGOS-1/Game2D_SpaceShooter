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
	NSprite* GetSprite() { return mSprite; }
	void virtual SetX(float value) { mX = value; }
	void virtual SetY(float value) { mY = value; }

	void virtual Initialize() {}

	bool virtual HitTest(GSActor* actor) {
		bool result = false;

		float thisX = mX;
		float thisY = mY;
		float otherX = actor->GetX();
		float otherY = actor->GetY();

		return thisX < otherX + actor->GetSprite()->GetVisibleWidth() && thisX + mSprite->GetVisibleWidth() > otherX &&
			thisY < otherY + actor->GetSprite()->GetVisibleHeight() && mSprite->GetVisibleHeight() + thisY > otherY;
	}

	void virtual Update(float dt) {}
	void virtual Draw(float dt) {}

protected:
	NSprite* mSprite;

	float mX;
	float mY;

	virtual void CheckCollision() {}
};

