#include "stdafx.h"
#include "query.h"
#include <map>

istream& operator>>(istream& is, Query& q)
{
   q.stops.clear();
   string type;

   map<string, QueryType> operations = {
      { "NEW_BUS",         QueryType::NewBus },
      { "BUSES_FOR_STOP",  QueryType::BusesForStop },
      { "STOPS_FOR_BUS",   QueryType::StopsForBus },
      { "ALL_BUSES",       QueryType::AllBuses }
   };

   is >> type;
   q.type = operations[type];

   switch(q.type)
   {
      case QueryType::NewBus:
      {
         int stop_count;
                                                   
         is >> q.bus;
         is >> stop_count;

         if(stop_count < 0)
            stop_count = 0;

         for(int i = 0; i < stop_count; ++i)
         {
            string stop;
            is >> stop;

            q.stops.push_back(stop);
         }
      }
      break;
      case QueryType::BusesForStop:
      {
         string stop;
         is >> q.stop;
      }
      break;
      case QueryType::StopsForBus:
      is >> q.bus;
      break;
      case QueryType::AllBuses:
      break;
   }

   return is;
}