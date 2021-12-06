// Class.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "phone_number.h"
#include <iostream>

void printPhone(const PhoneNumber& ph)
{      
   cout << ph.GetCountryCode() << " " << ph.GetCityCode() << " " << ph.GetLocalNumber() << endl;
   cout << ph.GetInternationalNumber() << endl << endl;
}

int main()
{
   {
      PhoneNumber ph1("+7-495-111-22-33");
      printPhone(ph1);
   }

   {
      PhoneNumber ph1("+7-495-1112233");
      printPhone(ph1);
   }

   {
      PhoneNumber ph1("+323-22-460002");
      printPhone(ph1);
   }

   {
      PhoneNumber ph1("+1-2-coursera-cpp");
      printPhone(ph1);
   }

   {
      PhoneNumber ph1("1-2-333");
      printPhone(ph1);
   }

   {
      PhoneNumber ph1("+7-1233");
      printPhone(ph1);
   }
  
   system("PAUSE");
   return 0;
}

