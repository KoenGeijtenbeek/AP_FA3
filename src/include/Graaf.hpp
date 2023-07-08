#pragma once
#include <string>
#include <ostream>
#include <vector>
#include "Station.hpp"
#include "Stap.hpp"

class Graaf {
    private:
        
        std::vector<Stap*> connections;
    public:
        std::vector<Station*> stations;
        Graaf(std::vector<Station*> stations, std::vector<Stap*> connections);
        Stap* getConnection(Station* start, Station* end);
        int getDistance(std::vector<Station*> stations);
        std::vector<Station*> dijkstra(Graaf graaf, Station* startpunt, Station* eindpunt);
};