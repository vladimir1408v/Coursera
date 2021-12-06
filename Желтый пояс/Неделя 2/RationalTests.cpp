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

int GetNOD(int a, int b)
{
   // защита от отрицательный чисел
   a = abs(a);
   b = abs(b);

   // чтобы всегда был порядок a < b
   if(a > b)
   {
      int a1 = a;
      int b1 = b;
      b = a1;
      a = b1;
   }

   int n = 1;
   for(int i = a; i >= 1; --i)
   {
      if(a % i == 0 && b % i == 0)
      {
         n = i;
         break;
      }
   }

   return n;
}

int GetNOK(int a, int b)
{
   // защита от отрицательный чисел
   a = abs(a);
   b = abs(b);

   int nod = GetNOD(a, b);

   return (a * b) / nod;
}

class Rational
{
public:
   Rational()
   {
      m_numerator = 0;
      m_denominator = 1;
   }

   Rational(int numerator, int denominator)
   {
      SetData(numerator, denominator);
   }

   int Numerator() const
   {
      return m_numerator;
   }

   int Denominator() const
   {
      return m_denominator;
   }

   void SetData(int numerator, int denominator)
   {
      if(denominator == 0)
      {
         throw invalid_argument("denominator == 0");
         return;
      }

      if(numerator == 0)
         denominator = 1;

      // получаю общий делитель
      int nod = GetNOD(numerator, denominator);

      m_numerator = numerator / nod;
      m_denominator = denominator / nod;

      // проверяю на поожительность
      double rational = (double)m_numerator / (double)m_denominator;

      // делаю положительными
      m_numerator = abs(m_numerator);
      m_denominator = abs(m_denominator);

      // если отрицательный, то числитель тоже отрицательный
      if(rational < 0)
         m_numerator = -m_numerator;
   }

private:
   int m_numerator;
   int m_denominator;
};

// оператор +
Rational operator+(const Rational& lhs, const Rational& rhs)
{
   int nok = GetNOK(lhs.Denominator(), rhs.Denominator());

   int firstNum = lhs.Numerator() * (nok / lhs.Denominator());
   int secondNum = rhs.Numerator() * (nok / rhs.Denominator());

   return Rational(firstNum + secondNum, nok);
}

// оператор -
Rational operator-(const Rational& lhs, const Rational& rhs)
{
   int nok = GetNOK(lhs.Denominator(), rhs.Denominator());

   int firstNum = lhs.Numerator() * (nok / lhs.Denominator());
   int secondNum = rhs.Numerator() * (nok / rhs.Denominator());

   return Rational(firstNum - secondNum, nok);
}

// оператор *
Rational operator*(const Rational& lhs, const Rational& rhs)
{
   return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

// оператор /
Rational operator/(const Rational& lhs, const Rational& rhs)
{
   int del = lhs.Denominator() * rhs.Numerator();
   if(del == 0)
      throw domain_error("del == 0");

   // перевернутая вторая дробь
   return Rational(lhs.Numerator() * rhs.Denominator(), del);
}

// оператор ==
bool operator==(const Rational& lhs, const Rational& rhs)
{
   if(lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator())
      return true;

   return false;
}

// оператор !=
bool operator!=(const Rational& lhs, const Rational& rhs)
{
   if(lhs.Numerator() != rhs.Numerator() || lhs.Denominator() != rhs.Denominator())
      return true;

   return false;
}

// оператор <
bool operator<(const Rational& lhs, const Rational& rhs)
{
   if(((double)lhs.Numerator() / (double)lhs.Denominator()) < ((double)rhs.Numerator() / (double)rhs.Denominator()))
      return true;

   return false;
}

// оператор >>
istream& operator >> (istream& stream, Rational& rational)
{
   int numerator = rational.Numerator();
   int denominator = rational.Denominator();

   stream >> numerator;
   stream.ignore(1);
   stream >> denominator;

   rational.SetData(numerator, denominator);

   return stream;
}

// оператор >>
ostream& operator<<(ostream& stream, const Rational& rational)
{
   stream << rational.Numerator() << "/" << rational.Denominator();
   return stream;
}


void Test()
{
   const Rational r(3, 10);
   AssertEqual(r.Denominator(), 10, "Denominator r 10");
   AssertEqual(r.Numerator(), 3, "Numerator r 3");

   const Rational r2(8, 12);
   AssertEqual(r2.Numerator(), 2, "Numerator r2 2");
   AssertEqual(r2.Denominator(), 3, "Denominator r2 3");

   const Rational r3(-4, 6);
   AssertEqual(r3.Numerator(), -2, "Numerator r3 -2");
   AssertEqual(r3.Denominator(), 3, "Denominator r3 10");

   const Rational r4(4, -6);
   AssertEqual(r4.Numerator(), -2, "Numerator r4 -2");
   AssertEqual(r4.Denominator(), 3, "Denominator r4 10");

   const Rational r5(0, 15);
   AssertEqual(r5.Numerator(), 0, "Numerator r5 0");
   AssertEqual(r5.Denominator(), 1, "Denominator r5 1");

   const Rational r6;
   AssertEqual(r6.Numerator(), 0, "Numerator r6 0");
   AssertEqual(r6.Denominator(), 1, "Denominator r6 1");

   const Rational r7(-2, -3);
   AssertEqual(r7.Numerator(), 2, "Numerator r7 2");
   AssertEqual(r7.Denominator(), 3, "Denominator r7 3");

   Rational r8(4, 6);
   Rational r9(2, 3);
   AssertEqual(true, r8 == r9, "r8 != r9");

   {
      Rational a(2, 3);
      Rational b(4, 3);
      Rational c = a + b;
      AssertEqual(c, Rational(2, 1), "c != Rational(2, 1)");
   }

   {
      Rational a(5, 7);
      Rational b(2, 9);
      Rational c = a - b;
      AssertEqual(c, Rational(31, 63), "c != Rational(31, 63)");
   }

   {
      Rational a(2, 3);
      Rational b(4, 3);
      Rational c = a * b;
      AssertEqual(c, Rational(8, 9), "c != Rational(8, 9)");
   }

   {
      Rational a(5, 4);
      Rational b(15, 8);
      Rational c = a / b;
      AssertEqual(c, Rational(2, 3), "c != Rational(2, 3)");
   }
}


int main()
{
   TestRunner runner;
   runner.RunTest(Test, "Test");

   system("PAUSE");
   return 0;
}