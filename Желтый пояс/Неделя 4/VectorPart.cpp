// Example program
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void PrintVectorPart(const vector<int>& numbers)
{
	auto negativeIt = find_if(begin(numbers), end(numbers), [](const int& num) {return num < 0;});
	
    for (auto it = --negativeIt; it != begin(numbers); --it) 
        cout << *it << " ";
}

int main()
{
	PrintVectorPart({6, 1, 8, -5, 4});
	cout << endl;
	PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
	cout << endl;
	PrintVectorPart({6, 1, 8, 5, 4});
	cout << endl;
	PrintVectorPart({});
	cout << endl;
	
	return 0;
}