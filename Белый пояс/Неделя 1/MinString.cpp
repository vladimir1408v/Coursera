// coursera1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
   while(true)
   {
      string a, b, c;
      cin >> a >> b >> c;

      vector<string> l_vStr;
      l_vStr.push_back(a);
      l_vStr.push_back(b);
      l_vStr.push_back(c);

      sort(begin(l_vStr), end(l_vStr));
      
      cout << endl << l_vStr[0] << endl << endl;
   }

   system("PAUSE");
   return 0;
}

