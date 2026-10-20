#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

template <typename Type>

Type Min(Type a, Type b) {
	if (a > b) {
		return static_cast<Type>(b);
	}
	else {
		return static_cast<Type>(a);
	}
}

int main() {

	printf("%d\n", Min<int>(128, 256));
	printf("%0.1f\n", Min<float>(52.5f, 55.0f));
	printf("%lf\n", Min<double>(3.14159265, 2.7182818281));

	return 0;
}