#include "NFramework.h"
#include "NCamera2D.h"
#include "NCamera3D.h"

#include <GL/glew.h>

NFramework* NFramework::M_FRAMEWORK;
NFramework* NFramework::GET_FRAMEWORK() { return M_FRAMEWORK; }

NFramework::NFramework() :
	mFrameworkState(NEnumFrameworkState::Running),
	mContentManagment(this),
	mShaderManagment(this)
{
	NFramework::M_FRAMEWORK = this;
} 

NFramework::~NFramework()
{
}

void NFramework::Initialize(const std::string windowName, 
	int screenWidth, int screenHeight, 
	unsigned int windowFlags)
{
	mWindow.Create(windowName, screenWidth, screenHeight, windowFlags);
	mWindow.AddInputListener(std::bind(&NFramework::OnListenInputFromWindow,
		this, std::placeholders::_1));

	mCamera = (NBaseCamera*)(new NCamera2D());
	mCamera->Initialize(screenWidth, screenHeight);
	
	mContentManagment.Initialize();
	mShaderManagment.Initialize();

	// Initialization
	//ALCdevice* device = alcOpenDevice(NULL); // select the "preferred device"

	//if (device) {
	//	ALCcontext* context = alcCreateContext(device, NULL);
	//	alcMakeContextCurrent(context);
	//}

	//// Check for EAX 2.0 support
	//ALboolean g_bEAX = alIsExtensionPresent("EAX2.0");

	//ALsizei NUM_BUFFERS = 1;
	//ALuint* g_Buffers = 0;
	//ALenum error;

	//// Generate Buffers
	//alGetError(); // clear error code
	//alGenBuffers(NUM_BUFFERS, g_Buffers);
	//if ((error = alGetError()) != AL_NO_ERROR)
	//{
	//	FatalError("alGenBuffers :" + std::to_string(error));
	//	return;
	//}
}

void NFramework::DoGameLoop(std::function<void(float)> onUpdate, std::function<void(float)> onDraw)
{
	mOnUpdate = onUpdate;
	mOnDraw = onDraw;

	while (mFrameworkState != NEnumFrameworkState::Exit) {
		float deltaTime = ComputeDeltaTime();

		mWindow.Update(deltaTime);
		Update(deltaTime);
		Draw(deltaTime);
	}
}

float NFramework::ComputeDeltaTime()
{
	float deltaTime = 0.0f;

	static float previousTick = SDL_GetTicks();
	float currenTick = SDL_GetTicks();

	deltaTime = currenTick - previousTick;
	previousTick = currenTick;

	return deltaTime / 1000.0f;
}

void NFramework::OnListenInputFromWindow(SDL_Event evnt)
{
	if (mOnInput != NULL) {
		mOnInput(evnt);
	}

	switch (evnt.type)
	{
	case SDL_QUIT:
		mFrameworkState = NEnumFrameworkState::Exit;
		break;
	}
}

void NFramework::Update(float dt)
{
	mCamera->Update(dt);
	mOnUpdate(dt);
}

void NFramework::Draw(float dt)
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	mOnDraw(dt);

	mWindow.Present();
}
