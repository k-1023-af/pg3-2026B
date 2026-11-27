#pragma once
#include "KamataEngine.h"

enum class GameAction {
	// Control Character
	kMoveLeft,
	kMoveRight,
	kMoveUp,
	kMoveDown,
	kAttack,
	//kJump,
	//kDash,

	// UI / Camera / Settings

};



class InputManager {
public:
	static InputManager* GetInstance();

	void Update();

	bool isPress(GameAction action);            // Pressing
	bool IsPressMouse(GameAction action);       // Pressing
	bool IsTrigger(GameAction action);          // Only 1 input then release
	bool IsRelease(GameAction action);          // Let go

	const std::array<BYTE, 256>& GetKeys() const { return keys_; }
	const std::array<BYTE, 256>& GetPreKeys() const { return preKeys_; }

	InputManager(const InputManager&) = delete;
	InputManager& operator=(const InputManager&) = delete;

private:
	std::array<BYTE, 256> keys_{};
	std::array<BYTE, 256> preKeys_{};

	DIMOUSESTATE2 mouseNumber_{};
	DIMOUSESTATE2 preMouseNumber_{};

	InputManager() = default;
	~InputManager() = default;

	bool IsPressedRaw(std::array<BYTE, 256> keys, GameAction action);
	bool IsPressedRawMouse(DIMOUSESTATE2 mouseButton, GameAction action);

};
