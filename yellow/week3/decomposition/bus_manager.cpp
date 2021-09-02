#include "bus_manager.h"

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
    buses_to_stops[bus] = stops;
    for (const string& stop : stops) {
        stops_to_buses[stop].push_back(bus);
    }
}
 
BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
    BusesForStopResponse bfs;
    if (stops_to_buses.count(stop) != 0) {
        bfs.buses = stops_to_buses.at(stop);
    }
    return bfs;
  }

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
    StopsForBusResponse sfb;
    if (buses_to_stops.count(bus) != 0) {
        sfb.stops = buses_to_stops.at(bus);
    }
    sfb.stops_to_buses = stops_to_buses;
    sfb.bus = bus;
    return sfb;
}

AllBusesResponse BusManager::GetAllBuses() const {
    return {buses_to_stops, stops_to_buses};
}