// coursera1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

typedef vector<int> vec_int;

void Print(const vec_int& source)
{
   for(const int& x : source)
      cout << x << " ";
}

int main()
{
   while(true)
   {
      int n;
      cout << "Enter:" << endl;
      cin >> n;

      if(n <= 0 || n >= 1000)
      {
         cout << "n <= 0 || n >= 1000" << endl << endl;
         continue;
      }

      vec_int vresult;
      while(n != 0)
      {
         int number;
         cin >> number;

         if(number <= -1000000 || n >= 1000000)
         {
            cout << "number <= -1000000 || n >= 1000000. Try again" << endl << endl;
            continue;
         }

         vresult.push_back(number);

         n--;
      }

      sort(vresult.begin(), vresult.end(), [](int first, int second)
      {
         if(abs(first) <= abs(second))
            return true;

         return false;
      });

      Print(vresult);
      cout << endl;
   }

   system("PAUSE");
   return 0;
}

