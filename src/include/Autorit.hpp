#include "Stap.hpp"

class Autorit : public Stap {
    
    public:
        Autorit(Station* start, Station* end, int distance);
        int getDistance(){return distance;}
        Station* getStart(){return start;}
        Station* getEnd(){return end;}
};