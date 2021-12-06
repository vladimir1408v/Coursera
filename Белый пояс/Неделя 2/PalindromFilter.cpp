// coursera1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<string> vec_string;

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

vec_string PalindromFilter(vec_string& words, int minLength)
{
   vec_string result;

   for(auto x : words)
   {
      if(x.size() >= minLength && IsPalindrom(x))
         result.push_back(x);
   }
   
   return result;
}

int main()
{
   vec_string words = { "murdrum", "malayalam", "kayak", "cdc", "degged", "adinida", "abcdefg"};
   vec_string result = PalindromFilter(words, 6);

   for(auto x : result)
      cout << x << endl;

   cout << endl;

   system("PAUSE");
   return 0;
}

