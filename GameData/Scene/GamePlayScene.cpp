#include"GamePlayScene.h"
#include "ImGuiManager.h"

void GamePlayScene::Initialize() {
	input_ = Input::GetInstance();
}

void GamePlayScene::Update() {
	ImGui::Begin("GamePlayScene");
	ImGui::Text("SceneNo:%d", sceneNo);
	ImGui::Text("Clear when 5 enemies are defeated");
	ImGui::Text("KillCount:%d", player->GetEnemyDeadCount());
	ImGui::Text("Move:WASD");
	ImGui::Text("Shot:Space");
	ImGui::End();

	player->Update();
	if (player->GetEnemyDeadCount() >= 5) {
		sceneNo = CLEAR_SCENE;
	}
}

void GamePlayScene::Draw() {
	player->Draw();
}

void GamePlayScene::Finalize() {
	delete player;
}