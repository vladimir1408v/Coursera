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
      cout << "Enter string:" << endl;
      string a;
      cin >> a;

      cout << endl;

      int counter = 0;
      int index = 0;
      for(int i = 0; i < a.size(); ++i)
      {
         if(a[i] == 'f')
         {
            if(counter == 1)
               index = i;

            counter++;    
         }
      }

      if(index)
         cout << index << endl << endl;

      else if (counter == 1)
         cout << -1 << endl << endl;

      else if(counter == 0)
         cout << -2 << endl << endl;
   }

   system("PAUSE");
   return 0;
}