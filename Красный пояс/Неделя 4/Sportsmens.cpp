// Sportsmens.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {

	int sportmens_count;
	cin >> sportmens_count;

	list<int> sporsmensList;
	vector<list<int>::iterator> positionList(100000 + 1, sporsmensList.end());

	for (size_t i = 0; i < sportmens_count; i++) {
		int sportsmen, nsportsmen;
		cin >> sportsmen >> nsportsmen;
		
		positionList[sportsmen] = sporsmensList.insert(positionList[nsportsmen], sportsmen);
	}

	for (int sportsmen : sporsmensList) {
		cout << sportsmen << '\n';
	}
	return 0;
}

