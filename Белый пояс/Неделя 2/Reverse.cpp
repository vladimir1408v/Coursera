// coursera1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef vector<int> vec_int;

void Reverse(vec_int& source)
{
   reverse(begin(source), end(source));
}

void Print(const vec_int& source)
{
   for(auto x : source)
      cout << x << endl;
}

int main()
{
   vec_int numbers = { 1, 5, 3, 4, 2 };
   Reverse(numbers);

   Print(numbers);

   cout << endl;

   system("PAUSE");
   return 0;
}

