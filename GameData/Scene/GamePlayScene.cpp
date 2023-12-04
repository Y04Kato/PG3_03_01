#include"GamePlayScene.h"
#include "ImGuiManager.h"

void GamePlayScene::Initialize() {
	input_ = Input::GetInstance();

	inputHandler_ = new InputHandler();

	inputHandler_->AssignMoveRightCommand2PressKeyD();
	inputHandler_->AssignMoveLeftCommand2PressKeyA();

	player_ = new Player();
}

void GamePlayScene::Update() {
	ImGui::Begin("GamePlayScene");
	ImGui::Text("SceneNo:%d", sceneNo);
	ImGui::Text("Move:AD");
	ImGui::Text("NextScene:Space");
	ImGui::End();

	command_ = inputHandler_->HandleInput();

	if (this->command_) {
		command_->Exec(*player_);
	}

	player_->Update();

	if (input_->TriggerKey(DIK_SPACE)) {
		sceneNo = CLEAR_SCENE;
	}
}

void GamePlayScene::Draw() {
	player_->Draw();
}

void GamePlayScene::Finalize() {
	delete player_;
	delete inputHandler_;
}