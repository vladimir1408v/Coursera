#include "stdafx.h"
#include "phone_number.h"
#include <sstream>
#include <exception>
#include <iostream>
     
// проверка на существование строки
bool checkString(const string& str, const string& number = "")
{
   if(str.empty())
   {
      string error(number);
      error.append(" does not match this format: +XXX-YYY-ZZZZZZ");
      throw invalid_argument(error);
   }

   return true;
}

// конструктор
PhoneNumber::PhoneNumber(const string& international_number)
{
   string copy(international_number);

   try
   {
      // проверка на существование
      if(checkString(copy, international_number))
      {
         // проверка что в начале +
         char first = copy.at(0);
         if(first == '+')
         {
            // удаляем +
            copy.erase(copy.begin());

            // пробегаемся по разделитеям
            stringstream ss(copy);
            getline(ss, country_code_, '-');
            checkString(country_code_, international_number);
            getline(ss, city_code_, '-');
            checkString(city_code_, international_number);

            // остальная часть в local_number_
            ss >> local_number_;
            checkString(local_number_, international_number);
         } 
         else
            checkString("", international_number);
      }
   } catch(const invalid_argument& ia)
   {
      cout << ia.what() << endl;

      country_code_  = "";
      city_code_     = "";
      local_number_  = "";
   }
}

string PhoneNumber::GetCountryCode() const
{
   return country_code_;
}

string PhoneNumber::GetCityCode() const
{
   return city_code_;
}

string PhoneNumber::GetLocalNumber() const
{
   return local_number_;
}

string PhoneNumber::GetInternationalNumber() const
{
   string result = "";
   if(!country_code_.empty() ||
      !city_code_.empty() ||
      !local_number_.empty())
   {
      result.append("+" + country_code_ + "-");
      result.append(city_code_ + "-");
      result.append(local_number_);
   }

   return result;
}

