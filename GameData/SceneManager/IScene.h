#pragma once

enum SCENE {
	TITLE_SCENE,
	GAME_SCENE,
	CLEAR_SCENE,
	SCENE_MAX
};

class Iscene {
public:
	virtual void Initialize() = 0;

	virtual void Update() = 0;

	virtual void Draw() = 0;

	virtual void Finalize() = 0;

	virtual ~Iscene() {};

	int GetSceneNo();

protected:
	static int sceneNo_;
};
