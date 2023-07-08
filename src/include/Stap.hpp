#pragma once
#include <string>
#include <ostream>
#include "Station.hpp"

class Stap {
    protected:
        Station* start;
        Station* end;
        int distance;
    public:
        
        virtual int getDistance() = 0;
        virtual Station* getStart() = 0;
        virtual Station* getEnd() = 0;
        virtual ~Stap() {} 
        friend std::ostream &operator<<(std::ostream& os, Stap& stap); 
          
};
