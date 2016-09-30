#include "GSEnemyManager.h"

#include "GSBaseEnemy.h"
#include "GSSimpleEnemy.h"

#include <stdlib.h>
#include <UPCFramework\NFramework.h>

void GSEnemyManager::Initialize()
{
	mTimeInterval.Initialize(0.5f, 1000);
	mTimeInterval.OnEndLoop = std::bind(&GSEnemyManager::OnEndLoop_Interval, this);
}

void GSEnemyManager::OnEndLoop_Interval()
{
	NWindow* window = NFramework::GET_FRAMEWORK()->GetWindow();
	
	int random = std::rand() % (window->GetScreenHeight() + 1);


	AddEnemy(window->GetScreenWidth(), random);
}

void GSEnemyManager::AddEnemy(int x, int y)
{
	GSSimpleEnemy* enemy = new GSSimpleEnemy();
	enemy->Initialize(this, x, y);

	mEnemies.push_back(enemy);
}

void GSEnemyManager::Update(float dt)
{
	mTimeInterval.Update(dt);

	std::list<GSBaseEnemy*>::iterator i = mEnemies.begin();
	while (i != mEnemies.end())
	{
		GSBaseEnemy* enemy = (*i);

		if (!enemy->IsDeleted) {
			enemy->Update(dt);
			++i;
		}
		else {
			// destruir el objecto enemy::: investigar como!!!!
			i = mEnemies.erase(i);
		}
	}
}

void GSEnemyManager::Draw(float dt)
{
	std::list<GSBaseEnemy*>::iterator i = mEnemies.begin();
	while (i != mEnemies.end())
	{
		GSBaseEnemy* enemy = (*i);

		if (!enemy->IsDeleted) {
			enemy->Draw(dt);
		}

		++i;
	}
}
