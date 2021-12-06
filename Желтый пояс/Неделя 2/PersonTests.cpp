// coursera1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <regex>
#include <cctype>
#include <stdexcept>
#include <set>
#include <sstream>

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



struct person_struct
{
   string   name = "";
   string   lastName = "";
   int      year = 0;
};

class Person
{
public:

   // конструктор
   Person(string first, string last, int year)
   {
      BirthYear = year;

      person_struct person;
      person.name = first;
      person.lastName = last;
      person.year = BirthYear;

      history.push_back(person);
   }

   Person() {}

   // изменение имени
   void ChangeFirstName(int year, const string& first_name)
   {
      Change(year, first_name, true);
   }

   // изменение фамилии
   void ChangeLastName(int year, const string& last_name)
   {
      Change(year, last_name, false);
   }

   // Полчение полного имени
   string GetFullName(int year)
   {
      if(year < BirthYear)
         return "No person";

      string name = GetNameByYearOrNear(year);
      string lastName = GetLastNameByYearOrNear(year);

      return FormFullName(name, lastName);
   }

   // Полчение имени с историей
   string GetFullNameWithHistory(int year)
   {
      if(year < BirthYear)
         return "No person";

      string name = GetAllNamesByYearOrNear(year);
      string lastName = GetAllLastNamesByYearOrNear(year);

      return FormFullName(name, lastName);
   }

protected:

   void Change(int year, const string& str, bool isName)
   {
      if(year < BirthYear)
         return;

      person_struct person;
      if(isName)
         person.name = str;
      else
         person.lastName = str;

      person.year = year;

      bool result = FillPersonByNewInfo(person);

      if(!result)
      {
         if(!history.size())
            BirthYear = year;

         SetPerson(person);
      }
   }

   // получение персоны по году
   bool FillPersonByNewInfo(const person_struct& person)
   {
      bool result = false;
      for(int i = 0; i < history.size(); ++i)
         if(history[i].year == person.year)
         {
            if(!person.name.empty())
               history[i].name = person.name;

            if(!person.lastName.empty())
               history[i].lastName = person.lastName;

            result = true;
         }

      return result;
   }

   // получение имени 
   string GetNameByYearOrNear(int year)
   {
      string name = "";
      for(int i = 0; i < history.size(); ++i)
         if(history[i].year <= year && !history[i].name.empty())
            name = history[i].name;

      return name;
   }

   // получение фамилии 
   string GetLastNameByYearOrNear(int year)
   {
      string lastName = "";
      for(int i = 0; i < history.size(); ++i)
         if(history[i].year <= year && !history[i].lastName.empty())
            lastName = history[i].lastName;

      return lastName;
   }

   // получение все имена 
   string GetAllNamesByYearOrNear(int year)
   {
      vector<string> vec;
      for(int i = history.size() - 1; i >= 0; --i)
      {
         if(history[i].year <= year && !history[i].name.empty())
            vec.push_back(history[i].name);
      }

      vec.erase(unique(vec.begin(), vec.end()), vec.end());
      return FormNamesString(vec);
   }

   // получение все фамилии 
   string GetAllLastNamesByYearOrNear(int year)
   {
      vector<string> vec;
      for(int i = history.size() - 1; i >= 0; --i)
      {
         if(history[i].year <= year && !history[i].lastName.empty())
            vec.push_back(history[i].lastName);
      }

      vec.erase(unique(vec.begin(), vec.end()), vec.end());
      return FormNamesString(vec);
   }

   // установка персоны
   void SetPerson(person_struct& person)
   {
      history.push_back(person);
      sort(history.begin(), history.end(), [](person_struct& first, person_struct& last)
      {
         if(first.year <= last.year)
            return true;

         return false;
      });
   }

   string FormNamesString(const vector<string>& src)
   {
      string result = "";

      for(int i = 0; i < src.size(); ++i)
      {
         if(result.empty())
            result = src[i];
         else if(i == 1)
            result += " (" + src[i];
         else
            result += ", " + src[i];
      }

      if(src.size() > 1)
         result += ")";

      return result;
   }

   string FormFullName(const string& first, const string& last)
   {
      string result = "";

      if(first.empty() && !last.empty())
         result = last + " with unknown first name";
      else if(!first.empty() && last.empty())
         result = first + " with unknown last name";
      else if(!first.empty() && !last.empty())
         result = first + " " + last;
      else
         result = "Incognito";

      return result;
   }

private:
   vector<person_struct> history;
   int BirthYear;

};

void TestGetFullName()
{
   Person p1("Kirill", "Kosolapov", 1993);

   p1.ChangeFirstName(1954, "Sergey");
   AssertEqual(p1.GetFullName(1964), "No person");

   p1.ChangeFirstName(1994, "Ivan");
   AssertEqual(p1.GetFullName(1992), "No person");
   AssertEqual(p1.GetFullName(1995), "Ivan Kosolapov");

   p1.ChangeLastName(1994, "");
   AssertEqual(p1.GetFullName(1993), "Kirill Kosolapov");
   AssertEqual(p1.GetFullName(1995), "Ivan Kosolapov");

   Person p2;
   p2.ChangeLastName(1955, "Kosolapov");
   AssertEqual(p2.GetFullName(1993), "Kosolapov with unknown first name");

   p2.ChangeFirstName(1956, "Sergey");
   AssertEqual(p2.GetFullName(1993), "Sergey Kosolapov");

   AssertEqual(p2.GetFullName(1954), "No person");
}

int main()
{
   TestRunner runner;
   runner.RunTest(TestGetFullName, "TestGetFullName");
   system("PAUSE");
   return 0;
}

