#pragma once
#include "Object.h"
#include "Input.h"

class Player {
public:
	Player();
	~Player();

	void Update();

	void Draw();

	void MoveRight();
	void MoveLeft();

public:
	Object player;

	Input* input_ = nullptr;

	bool playerIsAlive;
};

