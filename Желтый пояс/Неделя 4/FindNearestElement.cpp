// FindNearestElement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border)
{
   auto first = numbers.lower_bound(border);

   // если первый то отдаем
   if(first != begin(numbers))
   {
      auto second = prev(first);

      // если последний то предыдущий
      if(first == end(numbers))
         return second;

      // иначе кратчайщий путь до бордера
      return  (*first - border) < (border - *second) ? first : second;

   } else
      return first;
}

int main()
{
   set<int> numbers = { 1, 4, 6 };
   cout <<
      *FindNearestElement(numbers, 0) << " " <<
      *FindNearestElement(numbers, 3) << " " <<
      *FindNearestElement(numbers, 5) << " " <<
      *FindNearestElement(numbers, 6) << " " <<
      *FindNearestElement(numbers, 100) << endl;

   set<int> empty_set;

   cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;

   system("PAUSE");
   return 0;
}

