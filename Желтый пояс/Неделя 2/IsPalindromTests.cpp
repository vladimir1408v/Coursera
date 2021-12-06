#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <stdexcept>

using namespace std;

template <class T>
ostream &operator<<(ostream &os, const vector<T> &s)
{
   os << "{";
   bool first = true;
   for(const auto &x : s)
   {
      if(!first)
      {
         os << ", ";
      }
      first = false;
      os << x;
   }
   return os << "}";
}

template <class T>
ostream &operator<<(ostream &os, const set<T> &s)
{
   os << "{";
   bool first = true;
   for(const auto &x : s)
   {
      if(!first)
      {
         os << ", ";
      }
      first = false;
      os << x;
   }
   return os << "}";
}

template <class K, class V>
ostream &operator<<(ostream &os, const map<K, V> &m)
{
   os << "{";
   bool first = true;
   for(const auto &kv : m)
   {
      if(!first)
      {
         os << ", ";
      }
      first = false;
      os << kv.first << ": " << kv.second;
   }
   return os << "}";
}

template <class T, class U>
void AssertEqual(const T &t, const U &u, const string &hint = {})
{
   if(t != u)
   {
      ostringstream os;
      os << "Assertion failed: " << t << " != " << u;
      if(!hint.empty())
      {
         os << " hint: " << hint;
      }
      throw runtime_error(os.str());
   }
}

void Assert(bool b, const string &hint)
{
   AssertEqual(b, true, hint);
}

class TestRunner
{
public:
   template <class TestFunc>
   void RunTest(TestFunc func, const string &test_name)
   {
      try
      {
         func();
         cerr << test_name << " OK" << endl;
      } catch(exception &e)
      {
         ++fail_count;
         cerr << test_name << " fail: " << e.what() << endl;
      } catch(...)
      {
         ++fail_count;
         cerr << "Unknown exception caught" << endl;
      }
   }

   ~TestRunner()
   {
      if(fail_count > 0)
      {
         cerr << fail_count << " unit tests failed. Terminate" << endl;
         exit(1);
      }
   }

private:
   int fail_count = 0;
};

bool IsPalindrom(const string& word)
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

void Test()
{
   AssertEqual(IsPalindrom(""), true, "empty");
   AssertEqual(IsPalindrom("a"), true, "one symbol");
   AssertEqual(IsPalindrom("madam"), true, "odd number");
   AssertEqual(IsPalindrom("maam"), true, "even number");
   AssertEqual(IsPalindrom("qwerty"), false, "random");
   AssertEqual(IsPalindrom("ma d am"), true, "palindrom with space");
   AssertEqual(IsPalindrom("ma dam"), false, "not palindrom with space");
}

int main()
{
   TestRunner runner;
   runner.RunTest(Test, "Test");

   system("PAUSE");
   return 0;
}