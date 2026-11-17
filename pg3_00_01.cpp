#include <cstdio>
#include <numbers>
#include <cmath>

class IShape {
public: 
	virtual void Size() = 0;
	virtual void Draw() = 0;

	float radius = 5.5f;
	float width = 4.0f;
	float height = 6.0f;
	float area;

	virtual ~IShape() = default;
};

class Circle : public IShape {
private:
	void Size() override {
		printf("〇の半径は%.02f\n", radius);
	}
	void Draw() override {
		area = powf(radius, 2) * std::numbers::pi_v<float>;
		printf("〇のサイズは%.08f\n", area);
	}
};

class Rectangle : public IShape {
private:
	void Size() override {
		printf("矩形の幅は%.02f!\n", width);
		printf("矩形の縦は%.02f!\n", height);
	}
	void Draw() override {
		area = width * height;
		printf("矩形のサイズは%.02f!\n", area);
	}
};

int main() {
	Circle circle;
	Rectangle rectangle;

	IShape* shape1 = &circle;
	IShape* shape2 = &rectangle;
	
	shape1->Size();
	shape1->Draw();
	shape2->Size();
	shape2->Draw();

	return 0;
}