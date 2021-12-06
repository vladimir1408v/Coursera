// coursera1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int GetNOD(int a, int b)
{
   // защита от отрицательный чисел
   a = abs(a);
   b = abs(b);

   // чтобы всегда был порядок a < b
   if(a > b)
   {
      int a1 = a;
      int b1 = b;
      b = a1;
      a = b1;
   }

   int n = 1;
   for(int i = a; i >= 1; --i)
   {
      if(a % i == 0 && b % i == 0)
      {
         n = i;
         break;
      }
   }

   return n;
}

int main()
{
   while(true)
   {
      cout << "Enter numbers:" << endl;
      int a, b;
      cin >> a >> b;

      cout << endl;

      int nod = GetNOD(a, b);

      if(nod == 0)
         cout << "no nod" << endl << endl;

      else
         cout << nod << endl << endl;

   }

   system("PAUSE");
   return 0;
}