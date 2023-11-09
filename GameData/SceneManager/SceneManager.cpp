#include "SceneManager.h"
#include <Novice.h>

void SceneManager::Run() {
	Initialize();
	Update();
	Finalize();
}

void SceneManager::Initialize() {
	const char kWindowTitle[] = "LE2A_05_カトウ";
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	//Input
	input_ = Input::GetInstance();

	//Scene
	scene_[TITLE_SCENE] = std::make_unique<GameTitleScene>();
	scene_[GAME_SCENE] = std::make_unique<GamePlayScene>();
	scene_[CLEAR_SCENE] = std::make_unique<GameClearScene>();
	for (int i = 0; i < SCENE_MAX; i++) {
		scene_[i]->Initialize();
	}
}


void SceneManager::Update() {
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();
		///
		/// ↓更新処理ここから
		///
		currentSceneNo_ = scene_[currentSceneNo_]->GetSceneNo();
		scene_[currentSceneNo_]->Update();
		scene_[currentSceneNo_]->Draw();
		///
		/// ↑更新処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		//// ESCキーが押されたらループを抜ける
		if (input_->TriggerKey(DIK_ESCAPE)) {
			break;
		}
	}
}

//void SceneManager::Draw() {
//
//}

void SceneManager::Finalize() {
	for (int i = 0; i < SCENE_MAX; i++) {
		scene_[i]->Finalize();
	}
	CoUninitialize();

	// ライブラリの終了
	Novice::Finalize();
}