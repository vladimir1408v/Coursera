// coursera1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef vector<int> vec_int;

vec_int Reverse(const vec_int& source)
{
   vec_int copy(source);
   reverse(begin(copy), end(copy));
   
   return copy;
}

void Print(const vec_int& source)
{
   for(auto x : source)
      cout << x << endl;
}

int main()
{
   vec_int numbers = { 1, 5, 3, 4, 2 };
   vec_int copy = Reverse(numbers);

   Print(copy);

   cout << endl;

   system("PAUSE");
   return 0;
}

