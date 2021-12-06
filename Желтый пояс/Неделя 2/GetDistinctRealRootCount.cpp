// Capital.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <random>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s)
{
   os << "{";
   bool first = true;
   for(const auto& x : s)
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
ostream& operator << (ostream& os, const set<T>& s)
{
   os << "{";
   bool first = true;
   for(const auto& x : s)
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
ostream& operator << (ostream& os, const map<K, V>& m)
{
   os << "{";
   bool first = true;
   for(const auto& kv : m)
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

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {})
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

void Assert(bool b, const string& hint)
{
   AssertEqual(b, true, hint);
}

class TestRunner
{
public:
   template <class TestFunc>
   void RunTest(TestFunc func, const string& test_name)
   {
      try
      {
         func();
         cerr << test_name << " OK" << endl;
      } catch(exception& e)
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

int GetDistinctRealRootCount(double a, double b, double c)
{
   int result = 0;

   int d = pow(b, 2) - (4 * a * c);

   // нет корней
   if(d < 0)
      result = 0;

   // один
   else if(d == 0)
      result = 1;

   // два
   else if(d > 0)
      result = 2;

   return result;
}

void TestNoRoots()
{
   AssertEqual(GetDistinctRealRootCount(1, 0, 1), 0,
      "x^2+1 = 0 has 0 real roots.");
   AssertEqual(GetDistinctRealRootCount(1, 3, 4), 0,
      "x^2+3x+4 = 0 has 0 real roots.");
   AssertEqual(GetDistinctRealRootCount(1, -2, 10), 0,
      "x^2-2x+10 = 0 has 0 real roots.");
}

void TestOneRoot()
{
   for(auto i = 0; i < 100; ++i)
   {
      const auto x_1 = i + 1;

      const auto p = x_1 + x_1;
      const auto q = x_1 * x_1;

      const auto count = GetDistinctRealRootCount(1, p, q);
      stringstream description;
      description << showpos << "x^2" << p << "x" << q
         << " = 0 has 1 real root.";

      AssertEqual(count, 1, description.str());
   }
}

void TestTwoRoots()
{
   for(auto i = 0; i < 100; ++i)
   {
      const auto a = i;
      const auto b = i + 1;
      const auto c = i + 2;

      const auto count = GetDistinctRealRootCount(a, b, c);

      Assert(count == 2,
         "Quadratic equation has only 2 real roots.");
   }
}

int main()
{
   TestRunner runner;
   runner.RunTest(TestNoRoots,   "TestNoRoot");
   runner.RunTest(TestOneRoot,   "TestOneRoot");
   runner.RunTest(TestTwoRoots,  "TestNoRoot");

   system("PAUSE");
   return 0;
}

