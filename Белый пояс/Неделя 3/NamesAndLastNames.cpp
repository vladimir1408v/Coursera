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
   string   name     = "";
   string   lastName = "";
   int      year     = 0;
};

class Person
{
public:
   void ChangeFirstName(int year, const string& first_name)
   {
      person_struct person;
      person.name = first_name;
      person.year = year;

      bool result = FillPersonByNewInfo(person);

      history;
      if(!result)
         SetPerson(person);
   }
   void ChangeLastName(int year, const string& last_name)
   {
      person_struct person;
      person.lastName = last_name;
      person.year = year;

      bool result = FillPersonByNewInfo(person);

      history;
      if(!result)
         SetPerson(person);
   }
   string GetFullName(int year)
   {
      string fullName = "";
      string name = GetNameByYearOrNear(year);
      string lastName = GetLastNameByYearOrNear(year);

      if(name.empty() && !lastName.empty())
         fullName = lastName + " with unknown first name";
      else if(!name.empty() && lastName.empty())
         fullName = name + " with unknown last name";
      else if(!name.empty() && !lastName.empty())
         fullName = name + " " + lastName;
      else
         fullName = "Incognito";

      return fullName;
   }
private:
   vector<person_struct> history;

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
};

int main()
{
   Person person;

   person.ChangeFirstName(1965, "Polina");
   person.ChangeFirstName(1965, "Anastasia");
   person.ChangeLastName(1967, "Sergeeva");
   for(int year : {1900, 1965, 1990})
   {
      cout << person.GetFullName(year) << endl;
   }

   person.ChangeFirstName(1970, "Appolinaria");
   for(int year : {1969, 1970})
   {
      cout << person.GetFullName(year) << endl;
   }

   person.ChangeLastName(1968, "Volkova");
   for(int year : {1969, 1970})
   {
      cout << person.GetFullName(year) << endl;
   }

   system("PAUSE");
   return 0;
}

