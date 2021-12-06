#include "stdafx.h"
#include "responses.h"

ostream& operator << (ostream& os, const BusesForStopResponse& r)
{
   if(r.buses.size())
   {
      for(const string& bus : r.buses)
         os << bus << " ";
      os << endl;
   }

   else
      os << "No stop" << endl;

   return os;
}

ostream& operator << (ostream& os, const StopsForBusResponse& r)
{
   if(r.stops.size())
   {
      for(const auto& stop : r.stops)
      {
         os << "Stop " << stop.first << ": ";
         if(stop.second.size() == 1)
            os << "no interchange";

         else
         {
            for(const string& bus : stop.second)
               if(r.bus != bus)
                  os << bus << " ";
         }

         os << endl;
      }
   }

   else
      os << "No bus" << endl;

   return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r)
{
   if(r.buses.size())
   {
      for(const auto& bus : r.buses)
      {
         os << "Bus " << bus.first << ": ";
         for(const string& stop : bus.second)
            os << stop << " ";
         os << endl;
      }
   }

   else
      os << "No buses" << endl;

   return os;
}                                  