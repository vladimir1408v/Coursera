// coursera1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cstdint>
#include <map>
#include <tuple>
#include <set>
#include <utility>
#include <algorithm>

typedef uint8_t   u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t   s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

using namespace std;

template<typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& m, Key k)
{
   if(m.count(k) != 0)
   {
      return m[k];
   } else
      throw runtime_error("no element");
}

int main()
{
   try
   {
      map<int, string> m = { { 0, "value" } };
      string& item = GetRefStrict(m, 0);
      item = "newvalue";
      cout << m[0] << endl; // выведет newvalue
   } 
   
   catch(exception& e)
   {
      cout << e.what() << endl;
   }

   system("PAUSE");
   return 0;
}

