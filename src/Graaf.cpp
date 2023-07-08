#include "include/Graaf.hpp"
#include "include/StationGreaterThan.hpp"
#include <algorithm>
#include <limits>
#include <queue>

Graaf::Graaf(std::vector<Station*> stations, std::vector<Stap*> connections) : stations(stations), connections(connections){};

Stap* Graaf::getConnection(Station* start, Station* end){
    for(Stap* connection : start->connections){
        if(connection->getEnd() == end){
            return connection;
        }
    }
    return nullptr;
}


int Graaf::getDistance(std::vector<Station*> stations){
    int totalDistance = 0;
    for(int i = 0; i < stations.size() - 1; i++){
        totalDistance += getConnection(stations[i], stations[i+1])->getDistance();
    }
    return totalDistance;
}

std::vector<Station*> Graaf::dijkstra(Graaf graaf, Station* startpunt, Station* eindpunt){
    std::priority_queue<Station*, std::vector<Station*>, StationGreaterThan> pq;

    for(Station* station : graaf.stations){
        station->afstandTotBron = std::numeric_limits<int>::max();
        station->vorigStation = nullptr;
        pq.push(station);
    }
    startpunt->afstandTotBron = 0;
    

    while(pq.size() != 0){
        Station* closest_station = pq.top();
        pq.pop();

        std::vector<Stap*> connections = closest_station->connections;
        std::vector<Station*> neighbours = {};

        for(Stap* connection : connections){
            neighbours.push_back(connection->getEnd());
        }
        int dist = 0;
        
        for(Station* neighbour : neighbours){
            std::priority_queue<Station*, std::vector<Station*>, StationGreaterThan> pqtemp = pq;
            for(int i = 0; i < pq.size(); i++){
                if(pqtemp.top() == neighbour){
                    Stap* connection = graaf.getConnection(closest_station, neighbour);
                    dist = closest_station->afstandTotBron + connection->getDistance();
                    if(neighbour->afstandTotBron > dist){
                        pq.push(neighbour);
                        neighbour->afstandTotBron = dist;
                        neighbour->vorigStation = closest_station;
                    }
                }else{
                    pqtemp.pop();
                }
            }
        }
    
    }

    std::vector<Station*> result = {};
    Station* path = eindpunt;
    if(path->vorigStation != nullptr || path == startpunt){
        while(path!=nullptr){
            result.insert(result.begin(), path);
            path = path->vorigStation;
        }
    }else{
        return {};
    }
    return result;

}

