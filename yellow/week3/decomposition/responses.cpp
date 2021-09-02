#include "responses.h"

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  if (r.buses.size() == 0) {
      os << "No stop";
  }
  else {
      for (const string& b : r.buses) {
          cout << b << ' ';
      }
  }
  return os;
}

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    if (r.stops.empty()) {
        os << "No bus";
        return os;
    }
    for (size_t i = 0; i < r.stops.size(); ++i) { //(const string& stop : r.stops) {
        os << "Stop " << r.stops[i] << ": ";
        if (r.stops_to_buses.at(r.stops[i]).size() == 1) {
            os << "no interchange";
        } 
        else {
            for (const string& other_bus : r.stops_to_buses.at(r.stops[i])) {
                if (r.bus != other_bus) {
                    os << other_bus << " ";
                }
            }
         }
        if (i != r.stops.size() - 1) {
            os << endl;
        }
    }
    return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    if (r.buses_to_stops.empty()) {
        os << "No buses";
        return os;
    } 
    size_t i = r.buses_to_stops.size();
    for (const auto& bus_item : r.buses_to_stops) {
        os << "Bus " << bus_item.first << ": ";
        for (const string& stop : bus_item.second) {
            os << stop << " ";
        }
        
        if (i != 1) {
            cout << endl;
        }
        --i;
    }
    return os;
}