#include <stdio.h>
#include <list>
#include <iostream>

using namespace std;

int main() {
	
	//Yamanote Line train station names list

	//1970 (Showa 45) station list
	list <const char*> eki_list{
		"Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno", "Uguisudani", "Nippori",
		"Tabata", "Komagome", "Sugamo", "Otsuka", "Ikebukuro", "Mejiro", "Takadanobaba",
		"Shin-Okubo", "Shinjuku", "Yoyogi", "Harajuku", "Shibuya", "Ebisu", "Meguro",
		"Gotanda", "Osaki", "Shinagawa", "Tamachi", "Hamamatsucho", "Shimbashi", "Yurakucho"
	};

	printf("1970年リスト \n");	//Showa 45
	for (list<const char*>::iterator it_f = eki_list.begin(); it_f != eki_list.end(); it_f++) {
		std::cout << *it_f << endl;
	}

	printf("\n2019年リスト \n");	//Reiwa 1
	list<const char*>::iterator it_f;
	for (list<const char*>::iterator it_f = eki_list.begin(); it_f != eki_list.end(); it_f++) {
		if (*it_f == "Tabata") {
			it_f = eki_list.insert(it_f, "Nishi-Nippori");
			std::cout << *it_f << endl;
			++it_f;
		}
		std::cout << *it_f << endl;
	}
	
	printf("\n2022年リスト \n");	//Reiwa 4
	for (list<const char*>::iterator it_f = eki_list.begin(); it_f != eki_list.end(); it_f++) {
		if (*it_f == "Tamachi") {
			it_f = eki_list.insert(it_f, "Takanawa Gateway");
			std::cout << *it_f << endl;
			++it_f;
		}
		std::cout << *it_f << endl;
	}


	return 0;
}