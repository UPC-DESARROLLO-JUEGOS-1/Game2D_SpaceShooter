#pragma once

#include <SDL\SDL.h>

class GSPlayer;

class GSPlayerControl
{
public:
	GSPlayerControl(GSPlayer* player) {
		mPlayer = player;
	}

	~GSPlayerControl();

	void Initialize();
	void ProcessInputs(SDL_Event evnt);

	void Update(float dt);

private:
	GSPlayer* mPlayer;
};

