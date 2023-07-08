#include "Stap.hpp"

class Vlucht : public Stap {
    
    public:
        Vlucht(Station* start, Station* end, int distance);
        int getDistance(){return distance;}
        Station* getStart(){return start;}
        Station* getEnd(){return end;}
};