// coursera1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int Factorial(int a)
{
   if(a < 0)
      return 1;
   
   if(a == 0)
      return a;

   int result = 1;
   for(int i = 1; i <= a; ++i)
      result *= i;

   return result;
}

int main()
{
   while(true)
   {
      cout << "Enter number:" << endl;
      int a;

      cin >> a;

      cout << endl;

      cout << Factorial(a) << endl;

      cout << endl;
   }

   system("PAUSE");
   return 0;
}