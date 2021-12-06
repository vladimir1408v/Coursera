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

using namespace std;

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

   // изменение имени
   void ChangeFirstName(int year, const string& first_name)
   {
      if(year < BirthYear)
         return;

      person_struct person;
      person.name = first_name;
      person.year = year;

      bool result = FillPersonByNewInfo(person);

      history;
      if(!result)
         SetPerson(person);
   }

   // изменение фамилии
   void ChangeLastName(int year, const string& last_name)
   {
      if(year < BirthYear)
         return;

      person_struct person;
      person.lastName = last_name;
      person.year = year;

      bool result = FillPersonByNewInfo(person);

      history;
      if(!result)
         SetPerson(person);
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

int main()
{
   Person person("Polina", "Sergeeva", 1960);
   for(int year : {1959, 1960})
   {
      cout << person.GetFullNameWithHistory(year) << endl;
   }

   person.ChangeFirstName(1965, "Appolinaria");
   person.ChangeLastName(1967, "Ivanova");
   for(int year : {1965, 1967})
   {
      cout << person.GetFullNameWithHistory(year) << endl;
   }

   system("PAUSE");
   return 0;
}

