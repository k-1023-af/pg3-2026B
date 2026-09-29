#include <iostream>

int main() {
	//コンソールをUTF-8にする設定
	system("chcp 65001 > nul");
	char str[] = "今後もよろしく";

	printf("%s", str);

	return 0;
}