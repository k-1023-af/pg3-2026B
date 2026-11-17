#include <cstdio>

class Weapon {
public: 
	virtual void attack() const {
		printf("一撃!\n");
	}

	virtual ~Weapon() = default;
};

class Sword : public Weapon {
public:
	void attack() const override {
		printf("剣の一振り!\n");
	}
};

class Spear : public Weapon {
public:
	void attack() const override {
		printf("前方ウへの突き!\n");
	}
};

class Axe : public Weapon {
public:
	void attack() const override {
		printf("斧を振り下ろせ!\n");
	}
};

int main() {
	
	Weapon weapon;
	Sword sword;
	Spear spear;
	Axe axe;

	Weapon* weapon1 = &weapon;
	Weapon* weapon2 = &sword;
	Weapon* weapon3 = &spear;
	Weapon* weapon4 = &axe;

	weapon1->attack();
	weapon2->attack();
	weapon3->attack();
	weapon4->attack();

	return 0;
}