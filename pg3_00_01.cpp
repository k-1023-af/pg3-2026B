#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

template <typename Type>

Type Recursive(Type wage, Type hourly, Type standard) {
	if (wage >= standard) {
		printf("After %d hours has passed\n", hourly);
		return hourly;
	}
	printf("%d  %d\n", wage, standard);
	wage = wage * 2 - 50;

	return (Recursive(wage, ++hourly, standard += 1226));
}

int recursiveWage = 100;
int standardWage = 1226;
int hourlyIncrease = 0;

int main() {

	int result = Recursive(recursiveWage, hourlyIncrease, standardWage);

	return 0;
}