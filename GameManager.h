#pragma once
#include <memory>	//std::unique_ptr
#include "IScene.h"
#include "StageScene.h"
#include "TitleScene.h"
#include "ClearScene.h"

class GameManager
{
private:
	std::unique_ptr<IScene> sceneArr_[3];

	int currentSceneNo_;
	int prevSceneNo_;

public:
	GameManager();
	~GameManager();

	int Run();	//call game loop

};

