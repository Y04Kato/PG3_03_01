#pragma once
#include "Object.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Collisionfunc.h"
#include "Input.h"

class Player {
public:
	Player();
	~Player();

	void Update();

	void Draw();

	int GetEnemyDeadCount() { return enemyDeadCount; }

public:
	Object player;

	Bullet* bullet[32];

	Enemy* enemy;

	Input* input_ = nullptr;

	bool playerIsAlive;

	int enemyDeadCount;
};

