// coursera1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void UpdateIfGreater(const int& first, int& second)
{
   if(first > second)
      second = first;
}

int main()
{
   while(true)
   {
      cout << "Enter numbers:" << endl;
      int a, b;
      cin >> a >> b;

      UpdateIfGreater(a, b);

      cout << endl;

      cout << b << endl;

      cout << endl;
   }

   system("PAUSE");
   return 0;
}

