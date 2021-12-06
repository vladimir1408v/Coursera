// coursera1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main()
{
   while(true)
   {
      cout << "Enter number:" << endl;
      int a;
      vector<int> numbers;

      cin >> a;

      cout << endl;

      while(a > 0)
      {
         if(a % 2 == 0)
         {
            a /= 2;
            numbers.push_back(0);
         }
            
         else if(a % 2 == 1)
         {
            a -= 1;
            a /= 2;
            numbers.push_back(1);
         }
      }

      for(int i = numbers.size() - 1; i >= 0; --i)
         cout << numbers[i];

      cout << endl;
   }

   system("PAUSE");
   return 0;
}