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

// оператор <
bool operator<(const Rational& lhs, const Rational& rhs)
{
   if(((double)lhs.Numerator() / (double)lhs.Denominator()) < ((double)rhs.Numerator() / (double)rhs.Denominator()))
      return true;

   return false;
}

// оператор >>
istream& operator>>(istream& stream, Rational& rational)
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
   {
      const Rational r(3, 10);
      if(r.Numerator() != 3 || r.Denominator() != 10)
      {
         cout << "Rational(3, 10) != 3/10" << endl;
         //return 1;
      }
   }

   {
      const Rational r(8, 12);
      if(r.Numerator() != 2 || r.Denominator() != 3)
      {
         cout << "Rational(8, 12) != 2/3" << endl;
         //return 2;
      }
   }

   {
      const Rational r(-4, 6);
      if(r.Numerator() != -2 || r.Denominator() != 3)
      {
         cout << "Rational(-4, 6) != -2/3" << endl;
         //return 3;
      }
   }

   {
      const Rational r(4, -6);
      if(r.Numerator() != -2 || r.Denominator() != 3)
      {
         cout << "Rational(4, -6) != -2/3" << endl;
         //return 3;
      }
   }

   {
      const Rational r(0, 15);
      if(r.Numerator() != 0 || r.Denominator() != 1)
      {
         cout << "Rational(0, 15) != 0/1" << endl;
         //return 4;
      }
   }

   {
      const Rational defaultConstructed;
      if(defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1)
      {
         cout << "Rational() != 0/1" << endl;
         //return 5;
      }
   }

   {
      const Rational r(-2, -3);
      if(r.Numerator() != 2 || r.Denominator() != 3)
      {
         cout << "Rational(0, 15) != 0/1" << endl;
         //return 4;
      }
   }

   {
      Rational r1(4, 6);
      Rational r2(2, 3);
      bool equal = r1 == r2;
      if(!equal)
      {
         cout << "4/6 != 2/3" << endl;
         //return 1;
      }
   }

   {
      Rational a(2, 3);
      Rational b(4, 3);
      Rational c = a + b;
      bool equal = c == Rational(2, 1);
      if(!equal)
      {
         cout << "2/3 + 4/3 != 2" << endl;
         //return 2;
      }
   }

   {
      Rational a(5, 7);
      Rational b(2, 9);
      Rational c = a - b;
      bool equal = c == Rational(31, 63);
      if(!equal)
      {
         cout << "5/7 - 2/9 != 31/63" << endl;
         //return 3;
      }
   }

   {
      Rational a(2, 3);
      Rational b(4, 3);
      Rational c = a * b;
      bool equal = c == Rational(8, 9);
      if(!equal)
      {
         cout << "2/3 * 4/3 != 8/9" << endl;
         //return 1;
      }
   }

   {
      Rational a(5, 4);
      Rational b(15, 8);
      Rational c = a / b;
      bool equal = c == Rational(2, 3);
      if(!equal)
      {
         cout << "5/4 / 15/8 != 2/3" << endl;
         //return 2;
      }
   }

   {
      ostringstream output;
      output << Rational(-6, 8);
      if(output.str() != "-3/4")
      {
         cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
         //return 1;
      }
   }

   {
      istringstream input("5/7");
      Rational r;
      input >> r;
      bool equal = r == Rational(5, 7);
      if(!equal)
      {
         cout << "5/7 is incorrectly read as " << r << endl;
         //return 2;
      }
   }

   {
      istringstream input("5/7 10/8");
      Rational r1, r2;
      input >> r1 >> r2;
      bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
      if(!correct)
      {
         cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
         //return 3;
      }

      input >> r1;
      input >> r2;
      correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
      if(!correct)
      {
         cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
         //return 4;
      }
   }

   {
      const set<Rational> rs = { { 1, 2 },{ 1, 25 },{ 3, 4 },{ 3, 4 },{ 1, 2 } };
      if(rs.size() != 3)
      {
         cout << "Wrong amount of items in the set" << endl;
         //return 1;
      }

      vector<Rational> v;
      for(auto x : rs)
      {
         v.push_back(x);
      }

      if(v != vector<Rational>{
         {
            1, 25
         }, { 1, 2 }, { 3, 4 }})
      {
         cout << "Rationals comparison works incorrectly" << endl;
         //return 2;
      }
   }

   {
      map<Rational, int> count;
      ++count[{1, 2}];
      ++count[{1, 2}];

      ++count[{2, 3}];

      if(count.size() != 2)
      {
         cout << "Wrong amount of items in the map" << endl;
         //return 3;
      }
   }

   try
   {
      Rational r(1, 0);
      cout << "Doesn't throw in case of zero denominator" << endl;
      //return 1;
   } catch(invalid_argument& ia)
   {
      cout << ia.what() << endl;
   }

   try
   {
      auto x = Rational(1, 2) / Rational(0, 1);
      cout << "Doesn't throw in case of division by zero" << endl;
      //return 2;
   } catch(domain_error& de)
   {
      cout << de.what() << endl;
   }


   cout << "OK" << endl;

   system("PAUSE");
   return 0;
}