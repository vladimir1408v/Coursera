// coursera1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

float GetDiscont(float n, float p)
{
   return (n * p) / 100;
}

int main()
{
   while(true)
   {
      cout << "Enter range:" << endl;
      int a, b;
      cin >> a >> b;

      cout << endl;
      if(a <= b && a >= 1 && b <= 30000)
      {
         for(int i = a; i <= b; ++i)
         {
            if(i % 2 == 0)
               cout << i << endl;
         }
         cout << endl;
      }

      else
         cout << "(A <= B, A >= 1, B <= 30000)" << endl << endl;
   }

   system("PAUSE");
   return 0;
}