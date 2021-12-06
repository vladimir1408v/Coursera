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

template <typename T> // ключевое слово для объявления типа T
T Sqr(T x)
{
   return x * x; // нам нужно, чтобы элемент x поддерживал операцию умножения
}

template <typename T>
vector<T> operator*(const vector<T>& lhs, const vector<T>& rhs)
{
   vector<T> result;

   size_t size = min(lhs.size(), rhs.size());
   for(size_t i = 0; i < size; ++i)
      result.push_back(lhs[i] * rhs[i]);

   return result;
}

template <typename Key, typename Value>
map<Key, Value> operator*(const map<Key, Value>& lhs, const map<Key, Value>& rhs)
{
   map<Key, Value> result;

   for(const auto& pair : lhs)
   {
      if(rhs.count(pair.first) != 0)
         result[pair.first] = pair.second * rhs.at(pair.first);
   }

   return result;
}

template <typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second>& p1, const pair<First, Second>& p2)
{
   First f = p1.first * p2.first;
   Second s = p1.second * p2.second;

   return{ f, s };
}

int main()
{
   // Пример вызова функции
   vector<int> v = { 1, 2, 3 };
   cout << "vector:";
   for(int x : Sqr(v))
   {
      cout << ' ' << x;
   }
   cout << endl;

   map<int, pair<int, int>> map_of_pairs = {
      { 4,{ 2, 2 } },
      { 7,{ 4, 3 } }
   };
   cout << "map of pairs:" << endl;
   for(const auto& x : Sqr(map_of_pairs))
   {
      cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
   }

   system("PAUSE");
   return 0;
}

