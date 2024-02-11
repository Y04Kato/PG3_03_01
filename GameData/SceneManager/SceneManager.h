#pragma once
#include "Iscene.h"
#include "Input.h"
#include <memory>

#include "GameData/Scene/GameTitleScene.h"
#include "GameData/Scene/GamePlayScene.h"
#include "GameData/Scene/GameClearScene.h"

class SceneManager {
public:

	void Run();

	void Initialize();
	void Update();
	//void Draw();
	void Finalize();

private:
	std::unique_ptr<Iscene>scene_[SCENE_MAX];

	Input* input_ = nullptr;

	int currentSceneNo_;
	int previousSceneNo_;
};