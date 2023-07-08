#pragma once
#include <string>
#include <ostream>
#include <vector>



class Stap;


class Station {
    private:
        std::string name;
    public:
        int afstandTotBron;
        Station* vorigStation;
        std::vector<Stap*> connections;
        Station(std::string name);
        Station(std::string name, int afstandTotBron);
        std::string getName();
        friend std::ostream &operator<<(std::ostream& os, Station& station);
        friend bool operator>(const Station& lhs, const Station& rhs){
            return lhs.afstandTotBron > rhs.afstandTotBron;
        }
        friend bool operator<(const Station& lhs, const Station& rhs){
            return lhs.afstandTotBron < rhs.afstandTotBron;
        }
};