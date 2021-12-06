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
      cout << "Enter a, b and c" << endl;
      int a, b, c;
      cin >> a >> b >> c;

      if(a == 0)
      {
         cout << "a can't be zero" << endl << endl;
         continue;
      }

      int d = pow(b, 2) - (4 * a * c);

      // нет корней
      if(d < 0)
         cout << "" << endl << endl;

      // 2 корня 
      else
      {
         float x1 = ((-b + sqrt(d)) / (2 * a));
         float x2 = ((-b - sqrt(d)) / (2 * a));

         cout << x1 << " " << x2 << endl << endl;
      }
   }

   system("PAUSE");
   return 0;
}