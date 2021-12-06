// coursera1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool IsPalindrom(string& word)
{
   bool result = true;

   for(int i = 0; i < (word.size() / 2); ++i)
   {
      int firstIndex = i;
      int lastIndex = word.size() - (i + 1);

      if(word[firstIndex] != word[lastIndex])
      {
         result = false;
         break;
      }
   }

   return result;
}

int main()
{

   while(true)
   {
      cout << "Enter string:" << endl;
	  string word;
      cin >> word;
      cout << IsPalindrom(word) << endl;
	  cout << endl;
   }
   system("PAUSE");
    return 0;
}

