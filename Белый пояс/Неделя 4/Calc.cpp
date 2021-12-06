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
         throw invalid_argument("Invalid argument");

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
      throw invalid_argument("Division by zero");

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

int main()
{
   while(true)
   {
      string first;
      string second;
      string operation;

      cout << "Enter:" << endl << endl;
      cin >> first >> operation >> second;

      try
      {
         istringstream inputFirst(first);
         istringstream inputSecond(second);

         Rational f;
         inputFirst >> f;

         Rational s;
         inputSecond >> s;

         Rational rresult;
         if(operation == "+")
            rresult = f + s;
         else if(operation == "-")
            rresult = f - s;
         else if(operation == "*")
            rresult = f * s;
         else if(operation == "/")
            rresult = f / s;

         ostringstream output;
         output << rresult;

         cout << output.str() << endl << endl;

      } catch(invalid_argument& ia)
      {
         cout << ia.what() << endl << endl;
      }
   }

   system("PAUSE");
   return 0;
}