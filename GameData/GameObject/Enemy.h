#pragma once
#include "Object.h"

class Enemy {
public:
	Enemy();
	~Enemy();

	void Update();

	void Draw();

public:
	Object enemy;

	bool enemyIsAlive;

	int enemySpawnTimer;
};
