#include <stdio.h>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

//template <typename Type>

typedef void (*PFunc)(int *);

void DisplayResult(int* s) {
	printf("%d\n", *s);
}

void SetTimeout(PFunc p, int second) {
	Sleep(second * 1000);

	p(&second);
}

void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll, int userGuess);

int main() {
	printf("start\n");

	PFunc p;
	p = DisplayResult;
	SetTimeout(p, 5);
	


	return 0;
}