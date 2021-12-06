// coursera1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

typedef uint8_t   u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t   s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

using namespace std;

typedef vector<s32> vec_int;

void Print(const vec_int& source)
{
   for(const int& x : source)
      cout << x << " ";
}

int main()
{
   while(true)
   {
      s32 n;
      cout << "Enter day count:" << endl << endl;
      cin >> n;

      if(n < 0)
      {
         cout << "n < 0. Try again" << endl << endl;
         continue;
      }

      vec_int vtemp(n);
      s32 sum = 0;
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

