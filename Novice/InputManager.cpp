#include "InputManager.h"

InputManager* InputManager::GetInstance() { 
	static InputManager instance;

	return &instance;
}

void InputManager::Update() {
	preKeys_ = keys_;
	keys_ = KamataEngine::Input::GetInstance()->GetAllKey();

	preMouseNumber_ = mouseNumber_;
	mouseNumber_ = KamataEngine::Input::GetInstance()->GetAllMouse();
}

bool InputManager::isPress(GameAction action) { return IsPressedRaw(keys_, action); }

bool InputManager::IsPressMouse(GameAction action) { return IsPressedRawMouse(mouseNumber_, action) }

bool InputManager::IsTrigger(GameAction action) {
	bool nowKey = IsPressedRaw(keys_, action);
	bool preKey = IsPressedRaw(preKeys_, action);
	bool nowMouse = IsPressedRawMouse(mouseNumber_, action);
	bool preMouse = IsPressedRawMouse(preMouseNumber_, action);

	return nowKey && !preKey || nowMouse && !preMouse;
}

bool InputManager::IsRelease(GameAction action) { 
	bool nowKey = IsPressedRaw(keys_, action);
	bool preKey = IsPressedRaw(preKeys_, action);

	return !nowKey && preKey;
}

bool InputManager::IsPressedRaw(std::array<BYTE, 256> keys, GameAction action) {
	switch (action) {
	// ゲーム
	case GameAction::kMoveLeft:
		return keys[DIK_A];

	case GameAction::kMoveRight:
		return keys[DIK_D];
		/*
	case GameAction::kMoveUp:
		return keys[DIK_W];
		*/
	case GameAction::kMoveDown:
		return keys[DIK_S];

	case GameAction::kAttack:
		return keys[DIK_SPACE];

	//case GameAction::kJump:
	//	return keys[DIK_SPACE];
	//
	//	/*
	//case GameAction::kDash:
	//	return keys[DIK_LSHIFT];
	//	*/
	// UI
	//case GameAction::kUIUp:
	//	return keys[DIK_UP];
	//
	//case GameAction::kUIDown:
	//	return keys[DIK_DOWN];
	//
	//case GameAction::kUIRight:
	//	return keys[DIK_RIGHT];
	//
	//case GameAction::kUILeft:
	//	return keys[DIK_LEFT];

	default:
		return false;
	}
}

bool InputManager::IsPressedRawMouse(DIMOUSESTATE2 mouseButton, GameAction action) { 
	switch (action) {
		case GameAction::kAttack:
			return mouseButton.rgbButtons[0] & 0x80;

		default:
			return false;
	}
}
