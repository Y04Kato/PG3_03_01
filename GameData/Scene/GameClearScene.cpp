#include"GameClearScene.h"
#include "ImGuiManager.h"

void GameClearScene::Initialize() {
	input_ = Input::GetInstance();
}

void GameClearScene::Update() {
	ImGui::Begin("GameClearScene");
	ImGui::Text("SceneNo:%d", sceneNo_);
	ImGui::End();
}

void GameClearScene::Draw() {

}

void GameClearScene::Finalize() {

}