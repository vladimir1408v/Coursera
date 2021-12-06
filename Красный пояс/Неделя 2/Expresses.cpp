// Expresses.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "profile.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;

class RouteManager {
public:
	void AddRoute(int start, int finish) 
	{
		reachable_lists_[start].insert(finish);
		reachable_lists_[finish].insert(start);
	}
	int FindNearestFinish(int start, int finish) const 
	{
		int result = abs(start - finish);
		if (reachable_lists_.count(start) < 1) {
			return result;
		}

		const set<int>& reachable_stations = reachable_lists_.at(start);
		if (!reachable_stations.empty()) 
		{
			auto& it = reachable_stations.lower_bound(finish);
			
			// если больше finish не нашлось
			if (it == end(reachable_stations))
				result = min(result, abs(finish - *prev(it)));

			// если нашлось, но вставка пошла в начало
			else if(it == begin(reachable_stations))
				result = min(result, abs(*it - finish));

			// или проверка на ближайщий
			else
			{
				int first = abs(finish - *prev(it));
				int second = abs(*it - finish);

				result = min(result, first < second ? first : second);
			}
		}
		return result;
	}
private:
	map<int, set<int>> reachable_lists_;
};

int random(int min, int max)
{
	srand(time(NULL) + rand());

	int temp = max - min;

	if (temp == 0)
		temp = 1;

	int value = rand() % temp + min;
	return value;
}

void Test()
{
	LOG_DURATION("FindNearestFinish");

	RouteManager routes;
	/*routes.AddRoute(-2, 5);
	routes.AddRoute(10, 4);
	//routes.AddRoute(4, -1);
	routes.AddRoute(5, 8);

	cout << routes.FindNearestFinish(4, 10) << "\n";
	cout << routes.FindNearestFinish(4, -2) << "\n";
	cout << routes.FindNearestFinish(5, 0) << "\n";
	cout << routes.FindNearestFinish(5, 100) << "\n";*/
	for(size_t i = 0; i < pow(10, 2); i++)
		routes.AddRoute(random(-50, 1003), random(-50, 1003));

	for (size_t i = 0; i < pow(10, 3); i++)
		routes.FindNearestFinish(random(-50, 1003), random(-50, 1003));
}

int main() {
	Test();

	/*RouteManager routes;

	int query_count;
	cin >> query_count;

	for (int query_id = 0; query_id < query_count; ++query_id) {
		string query_type;
		cin >> query_type;
		int start, finish;
		cin >> start >> finish;
		if (query_type == "ADD") {
			routes.AddRoute(start, finish);
		}
		else if (query_type == "GO") {
			cout << routes.FindNearestFinish(start, finish) << "\n";
		}
	}*/

	system("PAUSE");
	return 0;
}