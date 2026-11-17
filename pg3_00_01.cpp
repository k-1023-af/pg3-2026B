#include <iostream>

template <typename Type>

class Function {
public: 
	Type a;
	Type b;

	Function(Type a, Type b) : a(a), b(b) {}

	Type Min() {
		if (a > b) {
			return static_cast<Type>(b);
		}
		if (a < b) {
			return static_cast<Type>(a);
		}
		if (a == b) {
			return static_cast<Type>(a);
		}
	}
};

int main() {
	Function<int> Int(10, 5);
	Function<float> Float(10.5f, 5.2f);
	Function<double> Double(11.53, 5.21);
	Function<int> IntFloat(2, 4.5f);
	Function<float> FloatDouble(22.3f, 11.25);
	Function<double> DoubleInt(1, 3.11);

	printf("Min of (10, 5) : %d\n", Int.Min());
	printf("Min of (10.5, 5.2) : %f\n", Float.Min());
	printf("Min of (11.53, 5.21) : %lf\n", Double.Min());
	printf("Min of (2, 4.5) : %d\n", IntFloat.Min());
	printf("Min of (22.3, 11.25) : %f\n", FloatDouble.Min());
	printf("Min of (1, 3.11) : %lf\n", DoubleInt.Min());


	return 0;
}