// UNIQ_ID.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define UNIQ_ID_LINE2(line) var_name_##line		// поэтому передаем посредником уже известный номер строки и делаем конкатенацию
#define UNIQ_ID_LINE(line) UNIQ_ID_LINE2(line)	// посредник для передачи номера строки, так как имя должно быть уникальным и имя не может состоять из цифр если брать только line (будет нужен идентификатор)
#define UNIQ_ID UNIQ_ID_LINE(__LINE__)				// передача номера строки

int main() {
	int UNIQ_ID = 0;												// var_name_18
	string UNIQ_ID = "hello";									// var_name_19
	vector<string> UNIQ_ID = { "hello", "world" };		// ...
	vector<int> UNIQ_ID = { 1, 2, 3, 4 };

	system("PAUSE");
	return 0;
}