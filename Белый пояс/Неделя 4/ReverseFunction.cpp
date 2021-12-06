// ReverseFunction.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class FunctionPart
{
public:
   FunctionPart(char new_operation, double new_x)
   {
      operation = new_operation;
      x = new_x;
   }
   double Apply(double source_value) const
   {
      if(operation == '+')
      {
         return source_value + x;
      } else if(operation == '-')
      {
         return source_value - x;
      } else if(operation == '*')
      {
         return source_value * x;
      } else if(operation == '/')
      {
         return source_value / x;
      }
   }
   void Invert()
   {
      if(operation == '+')
      {
         operation = '-';
      } else if(operation == '-')
      {
         operation = '+';
      } else if(operation == '*')
      {
         operation = '/';
      } else if(operation == '/')
      {
         operation = '*';
      }
   }
private:
   char operation;
   double x;
};

class Function
{
public:
   void AddPart(char operation, double x)
   {
      parts.push_back({ operation, x });
   }

   double Apply(double value) const
   {
      for(const FunctionPart& part : parts)
         value = part.Apply(value);

      return value;
   }

   void Invert()
   {
      for(FunctionPart& part : parts)
         part.Invert();

      reverse(begin(parts), end(parts));
   }
private:
   vector<FunctionPart> parts;
};

struct Image
{
   double quality;
   double freshness;
   double rating;
};

struct Params
{
   double a;
   double b;
   double c;
};

Function MakeWeightFunction(const Params& params, const Image& image)
{
   Function function;
   function.AddPart('*', params.a);
   function.AddPart('-', image.freshness * params.b);
   function.AddPart('+', image.rating * params.c);
   return function;
}

double ComputeImageWeight(const Params& params, const Image& image)
{
   Function function = MakeWeightFunction(params, image);
   return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params, const Image& image, double weight)
{
   Function function = MakeWeightFunction(params, image);
   function.Invert();
   return function.Apply(weight);
}

int main()
{
   Image image = { 10, 2, 6 };
   Params params = { 4, 2, 6 };
   cout << ComputeImageWeight(params, image) << endl;
   cout << ComputeQualityByWeight(params, image, 52) << endl;

   system("PAUSE");
   return 0;
}



