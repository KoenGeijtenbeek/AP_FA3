#include "include/Station.hpp"

Station::Station(std::string name):name(name){};
Station::Station(std::string name, int afstandTotBron):name(name), afstandTotBron(afstandTotBron){};

std::string Station::getName(){
    return this->name;
}

std::ostream &operator<<(std::ostream &os, Station& station){
    os << station.getName();
    return os;
}