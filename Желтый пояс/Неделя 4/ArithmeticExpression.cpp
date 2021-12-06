
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool IsGreaterOp(const char& curOp, const char& lastOp)
{
   if((curOp == '*' || curOp == '/') && (lastOp == '-' || lastOp == '+'))
      return true;

   return false;
}

void addHooks(string& result)
{
   string temp = "(" + result + ")";
   result = temp;
}

void addNumber(string& result, const char& curOp, int number)
{
   result += " ";
   result.push_back(curOp);

   if(number > 0)
      result.append(" ");

   result.append(to_string(number));
}

void partOne(string& result, const char& curOp, const char& lastOp, int number)
{
   addHooks(result);
   addNumber(result, curOp, number);
}

void partTwo(string& result, const char& curOp, const char& lastOp, int number)
{
   bool isGreater = IsGreaterOp(curOp, lastOp);
   if(isGreater)
      addHooks(result);

   addNumber(result, curOp, number);
}

int main()
{

   int firstNumber = 0;
   cin >> firstNumber;

   int countOperation = 0;
   cin >> countOperation;

   string str = to_string(firstNumber);
   string str2(str);

   char operation = 0;
   char lastOperation = 0;
   int number = 0;

   for(int i = 0; i < countOperation; i++)
   {
      cin >> operation;
      cin >> number;

      partOne(str, operation, lastOperation, number);
      partTwo(str2, operation, lastOperation, number);

      lastOperation = operation;
   }

   cout << str << endl;
   cout << str2 << endl;

   system("PAUSE");
   return 0;
}
