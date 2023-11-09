#include "GameTitleScene.h"
#include "ImGuiManager.h"

void GameTitleScene::Initialize() {
	input_ = Input::GetInstance();
}

void GameTitleScene::Update() {
	ImGui::Begin("GameTitleScene");
	ImGui::Text("SceneNo:%d", sceneNo);
	ImGui::Text("GameStartKey : Space");
	ImGui::End();

	if (input_->TriggerKey(DIK_SPACE)) {
		sceneNo = GAME_SCENE;
	}
}

void GameTitleScene::Draw() {

}

void GameTitleScene::Finalize() {

}