#pragma once

#include "NSprite.h"

class NMultiSprite : public NSprite
{
public:
	NMultiSprite() { NSprite::NSprite(); }
	~NMultiSprite() { NSprite::~NSprite(); }

	void Initialize(float x, float y, const std::string path, 
		const std::string bumpPath);
	void Draw(float dt);

private:
	NImageContent* mBumpTexture;
};

