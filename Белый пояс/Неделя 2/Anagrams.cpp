// coursera1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

typedef vector<int> vec_int;

map<char, int> BuildCharCounters(const string& str)
{
   map<char, int> count;
   for(char symbol : str)
      count[symbol]++;

   return count;
}

int main()
{
   int n;
   cout << "Enter count" << endl;
   cin >> n;

   for(int i = 0; i < n; ++i)
   {
      string first, second;
      cin >> first >> second;
      if(BuildCharCounters(first) == BuildCharCounters(second))
         cout << "YES" << endl;
      
      else
         cout << "NO" << endl;
   }

   system("PAUSE");
   return 0;
}

