#pragma once
#include "IScene.h"

class GameOverScene : public IScene {
public:
	void Init() override;
	void Update() override;
	void Draw() override;

};
