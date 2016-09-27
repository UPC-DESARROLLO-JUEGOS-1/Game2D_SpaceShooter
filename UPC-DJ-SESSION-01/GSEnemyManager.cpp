#include "GSEnemyManager.h"

#include "GSBaseEnemy.h"
#include "GSSimpleEnemy.h"

void GSEnemyManager::Initialize()
{
}

void GSEnemyManager::AddEnemy(int x, int y)
{
	GSSimpleEnemy* enemy = new GSSimpleEnemy();
	enemy->Initialize(this, x, y);

	mEnemies.push_back(enemy);
}

void GSEnemyManager::Update(float dt)
{
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
