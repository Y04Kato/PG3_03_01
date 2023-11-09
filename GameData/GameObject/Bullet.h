#pragma once
#include "Object.h"

class Bullet {
public:
	Bullet();
	~Bullet();

	void Update();
	void Draw();

public:
	Object bullet;

	bool bulletIsShot;
};