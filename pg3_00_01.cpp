#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <random> 
#include <ctime>

using namespace std;

//typedef void (*PFunc)(int *);
//
//void SetTimeout(PFunc p, int second) {
//	Sleep(second * 1000);
//
//	p(&second);
//}

//void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll, int userGuess);

typedef void (*Callback) (int result);

int roll_dice() {
	int min = 1;
	int max = 6;

	mt19937 gen(time(0));
	uniform_int_distribution<> distrib(min, max);

	int randNumber = distrib(gen);

	return randNumber;

	//cout << "サイコロの目は: " << randNumber << endl;
}

void judge_result(int result) {
	int input;

	scanf_s("%d", &input);
	printf("judging...\n");
	Sleep(3000);

	if ((result % 2 == 1 && input == 1) || (result % 2 == 0 && input == 0)) {
		printf("correct\n");
	}
	else { printf("incorrect\n"); }

	printf("dice result is %d\n", result);
}

int main() {
	printf("start\nguess if the result is odd (1) or even (0)\n" );
	
	srand((int)time(NULL));

	int dice_result = roll_dice();

	Callback callback = judge_result;

	callback(dice_result);

	return 0;
}