#include <iostream>

template <typename Type>

class Function {
public: 
	Type a;
	Type b;

	Function(Type a, Type b) : a(a), b(b) {}

	Type Min() {
		return static_cast<Type>(a - b);
	}
};



int main() {
	Function<int> subtractInt(10, 5);
	Function<float> subtractFloat(10.5f, 5.2f);
	Function<double> subtractDouble(11.53, 5.21);

	printf("Min of int: %d\n", subtractInt.Min());
	printf("Min of float: %f\n", subtractFloat.Min());
	printf("Min of double: %lf\n", subtractDouble.Min());

	return 0;
}