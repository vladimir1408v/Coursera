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
      cout << "Enter n, a, b, x, y" << endl;
      float n, a, b, x, y;
      cin >> n >> a >> b >> x >> y;

      if(n > b)
         n -= GetDiscont(n, y);

      else if(n > a)
         n -= GetDiscont(n, x);

      cout << endl << n << endl << endl;
   }

   system("PAUSE");
   return 0;
}