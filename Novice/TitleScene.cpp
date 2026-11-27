#include "TitleScene.h"

void TitleScene::Init() {

}

void TitleScene::Update() {
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE]) {
		sceneNo = STAGE;
	}

}

void TitleScene::Draw() {}
