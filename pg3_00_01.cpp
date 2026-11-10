
#include <iostream>

class Enemy {
public: 
	void Update();

	void Approach();
	void Attack();
	void Retreat();

	static void (Enemy::* spFuncTable[])();

private:
	int index = 0;
};

void Enemy::Approach(){ std::cout << "Enemy approaches!" << std::endl; }

void Enemy::Attack(){ std::cout << "Enemy attacks!" << std::endl; }

void Enemy::Retreat(){ std::cout << "Enemy retreats!" << std::endl; }

void Enemy::Update() {
	(this->*spFuncTable[index])();

	std::cout << "Press 0 for next phase\n";

	int input;
	std::cin >> input;

	if (input == 0) { index = (index + 1) % 3; }
}

void (Enemy::* Enemy::spFuncTable[])() = {
	&Enemy::Approach,	// index = 0
	&Enemy::Attack,		// index = 1
	&Enemy::Retreat		// index = 2
};


int main() {
	Enemy enemy;
	while (1) { enemy.Update(); }

	return 0;
}