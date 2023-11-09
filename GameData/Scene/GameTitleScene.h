#pragma once
#include "GameData/SceneManager/IScene.h"
#include "Input.h"

class GameTitleScene :public Iscene {
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Finalize() override;

private:
	Input* input_ = nullptr;
};