#include"GamePlayScene.h"
#include "ImGuiManager.h"

void GamePlayScene::Initialize() {
	input_ = Input::GetInstance();
	player_ = new Player();
}

void GamePlayScene::Update() {

	player_->Update();
	if (player_->GetEnemyDeadCount() >= 5) {
		sceneNo_ = CLEAR_SCENE;
	}
}

void GamePlayScene::Draw() {
	player_->Draw();
}

void GamePlayScene::Finalize() {
	delete player_;
}