#include "GSPlayerControl.h"
#include "GSPlayer.h"

GSPlayerControl::~GSPlayerControl()
{
}

void GSPlayerControl::Initialize()
{
}

void GSPlayerControl::ProcessInputs(SDL_Event evnt)
{
	switch (evnt.type) {
	case SDL_MOUSEMOTION:
		mPlayer->SetX((float)evnt.motion.x);
		mPlayer->SetY((float)evnt.motion.y);
		break;
	case SDL_KEYDOWN:
		switch (evnt.key.keysym.sym) {
		case SDLK_SPACE:
			mPlayer->CreateBullet();
			break;
		}
		break;
	}
}

void GSPlayerControl::Update(float dt)
{
}
