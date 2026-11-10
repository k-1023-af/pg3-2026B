#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

typedef void (*Callback) (int roll, int userGuess);

int roll_dice() {
	int min = 1;
	int max = 6;

	int randNumber = (rand() % (max - min + 1)) + min;

	return randNumber;

	//cout << "サイコロの目は: " << randNumber << endl;
}

void show_result(int roll, int userGuess) {

	if ((roll % 2 == 1 && userGuess == 1) || (roll % 2 == 0 && userGuess == 0)) {
		printf("正解\n");
	}
	else { printf("不正解\n"); }

	printf("サイコロの目は %d\n", roll);
}

int user_guess() {
	int input;

	printf("サイコロの出目が奇数(1)か偶数(0)か入力：\n");
	scanf_s("%d", &input);

	return input;
}

void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll, int userGuess) {

	printf("判定中．．．\n");
	Sleep(delayMs);
	fn(roll, userGuess);
}

int main() {

	srand((int)time(NULL));

	int userGuess = user_guess();

	int diceResult = roll_dice();

	Callback callback = show_result;

	DelayReveal(callback, 3000, diceResult, userGuess);

	return 0;
}