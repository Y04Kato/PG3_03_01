#pragma once
#include "GameData/SceneManager/IScene.h"
#include "Input.h"
#include "GameData/GameObject/Player.h"

#include "GameData/GameObject/InputHandler.h"

class GamePlayScene :public Iscene {
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Finalize() override;

private:
	Input* input_ = nullptr;

	ICommand* command_ = nullptr;

	InputHandler* inputHandler_ = nullptr;

	Player* player_;
};