// coursera1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
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
      cout << "Enter day count:" << endl << endl;
      cin >> n;
      
      if(n < 0)
      {
         cout << "n < 0. Try again" << endl << endl;
         continue;
      }

      vec_int vtemp(n);
      int sum = 0;
      cout << endl << "Enter temp numbers:" << endl << endl;
      for(int& temp : vtemp)
      {
         cin >> temp;
         sum += temp;
      }

      vec_int result;
      int ave = sum / n;

      for(size_t i = 0; i < vtemp.size(); ++i)
      {
         if(vtemp[i] > ave)
            result.push_back(i);
      }

      cout << endl << result.size() << endl;

      Print(result);

      cout << endl << endl;
   }

   system("PAUSE");
   return 0;
}

