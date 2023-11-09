#include <Novice.h>
#include "GameData/SceneManager/SceneManager.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	std::unique_ptr<SceneManager> sceneManager = std::make_unique<SceneManager>();
	sceneManager->Run();
	sceneManager.release();
	return 0;
}
