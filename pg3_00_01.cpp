#include <iostream>
#include <cstdio>

template <typename Type, typename Type2>

class Function {
public: 
	
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
private:
	Type a;
	Type b;
};

int main() {
	Function<int, float> IntFloat(10, 5.2f);
	Function<int, double> IntDouble(10, 5.233);
	Function<float, int> FloatInt(11.5f, 5);
	Function<float, double> FloatDouble(2.8f, 4.52);
	Function<double, int> DoubleInt(22.32, 11);
	Function<double, float> DoubleFloat(1.111, 3.11f);

	printf("int(10)　と float(5.2) を比べて小さい数字を返す：%0.2f\n", IntFloat.Min());
	printf("int(10)　と doubl3(5.233) を比べて小さい数字を返す：%0.2lf\n", IntDouble.Min());
	printf("float(11.5)　と int(5) を比べて小さい数字を返す：%0.2f\n", FloatInt.Min());
	printf("float(2.8)　と double(4.52) を比べて小さい数字を返す：%0.2lf\n", FloatDouble.Min());
	printf("double(22.32)　と int(11) を比べて小さい数字を返す：%0.2lf\n", DoubleInt.Min());
	printf("double(1.111)　と float(3.11f) を比べて小さい数字を返す：%0.2lf\n", DoubleFloat.Min());

	return 0;
}