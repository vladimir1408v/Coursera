// UNIQ_ID.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"


#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define UNIQ_ID_LINE2(line) var_name_##line		// ������� �������� ����������� ��� ��������� ����� ������ � ������ ������������
#define UNIQ_ID_LINE(line) UNIQ_ID_LINE2(line)	// ��������� ��� �������� ������ ������, ��� ��� ��� ������ ���� ���������� � ��� �� ����� �������� �� ���� ���� ����� ������ line (����� ����� �������������)
#define UNIQ_ID UNIQ_ID_LINE(__LINE__)				// �������� ������ ������

int main() {
	int UNIQ_ID = 0;												// var_name_18
	string UNIQ_ID = "hello";									// var_name_19
	vector<string> UNIQ_ID = { "hello", "world" };		// ...
	vector<int> UNIQ_ID = { 1, 2, 3, 4 };

	system("PAUSE");
	return 0;
}