#include "NGameApplication.h"
#include <UPCFramework\NEnumWindowFlags.h>
#include <GL/glew.h>

#include <iostream>

NGameApplication::NGameApplication()
{
}

NGameApplication::~NGameApplication()
{
}

void NGameApplication::Start()
{
	// Initialize the Game
	Initialize();
}

void NGameApplication::Initialize()
{
	// Initialize Framework
	mFramework = new NFramework();
	mFramework->Initialize("UPC Framework", 800, 600, NEnumWindowFlags::Windowed);
	mFramework->OnInput(std::bind(&NGameApplication::ProcessInputs, this, std::placeholders::_1));

	mCube.Initialize(0, 0, 0, 20.0f, 20.0f, 20.0f);
	mCube.SetZ(-8.0f);
	mCube.SetRenderCamera(mFramework->GetCamera());

	mGame01.Initialize();

	//// Initialize Primitive Quad
	//mQuad.Initialize(10.0f, 200.0f, 200, 200);
	//mQuad.SetRenderCamera(mFramework->GetCamera());
	//
	//std::string imagePath = "Sprites/sonic.png";
	//std::string imageBumpPath = "Sprites/bump_map.png";
	//
	////// Initialize Sprite
	//mSprite.Initialize(100.0f, 100.0f, 200, 200, imagePath);
	//mSprite.SetRenderCamera(mFramework->GetCamera());
	//
	////// Initialize MultiSprite
	//mMultiSprite.Initialize(400.0f, 120.0f, 200, 200, imagePath, imageBumpPath);
	//mMultiSprite.SetRenderCamera(mFramework->GetCamera());
	//
	//// Initialize Primitive Circumference
	//mCircumference.Initialize(600, 120, 80, 12);
	//mCircumference.SetRenderCamera(mFramework->GetCamera());

	// Start Game Loop
	mFramework->DoGameLoop(
		std::bind(&NGameApplication::Update, this, std::placeholders::_1),
		std::bind(&NGameApplication::Draw, this, std::placeholders::_1));
}

void NGameApplication::ProcessInputs(SDL_Event evnt)
{
	mGame01.ProcessInputs(evnt);
}

void NGameApplication::Update(float dt) {
	//float ro = mSprite.GetRotationZ();
	//ro += 0.01f;
	//mSprite.SetRotationZ(ro);
	//
	//mQuad.Update(dt);
	//mSprite.Update(dt);
	//mMultiSprite.Update(dt);
	//mCircumference.Update(dt);

	mGame01.Update(dt);
	//mCube.Update(dt);
}

void NGameApplication::Draw(float dt) {
	//mQuad.Draw(dt);
	//mSprite.Draw(dt);
	//mMultiSprite.Draw(dt);
	//mCircumference.Draw(dt);

	mGame01.Draw(dt);
	//mCube.Draw(dt);
}
