// Capital.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& map)
{
   set<string> values;
   for(const auto& value : map)
      values.insert(value.second);

   return values;
}

int main()
{
   set<string> values = BuildMapValuesSet({
      { 1, "odd" },
      { 2, "even" },
      { 3, "odd" },
      { 4, "even" },
      { 5, "odd" }
   });

   for(const string& value : values)
   {
      cout << value << endl;
   }

   system("PAUSE");
   return 0;
}

