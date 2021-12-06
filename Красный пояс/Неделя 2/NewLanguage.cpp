// NewLanguage.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "profile.h"

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>

using namespace std;

class Learner {
private:

	// использую сет - сразу идет уникальнось, плюс поиск идет быстрее
	set<string> dict;

public:
	int Learn(const vector<string>& words) {
		LOG_DURATION("Learn");
		int newWords = 0;
		for (const auto& word : words) 
		{
			if (dict.count(word) == 0)
			{
				++newWords;
				dict.insert(word);
			}
		}
		return newWords;
	}

	vector<string> KnownWords() 
	{
		LOG_DURATION("KnownWords");
		vector<string> result;

		for (const auto& word : dict)
			result.push_back(word);

		return result;
	}
};

void Test()
{
	Learner learner;
	string line;
	while (getline(cin, line)) {
		vector<string> words;
		stringstream ss(line);
		string word;
		while (ss >> word) {
			words.push_back(word);
		}
		cout << learner.Learn(words) << "\n";
	}
	cout << "=== known words ===\n";
	for (auto word : learner.KnownWords()) {
		cout << word << "\n";
	}
}

int main() 
{
	Test();

	system("PAUSE");
	return 0;
}
