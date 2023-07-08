#include "Stap.hpp"

class Treinrit : public Stap {
    
        
    public:
        Treinrit(Station* start, Station* end, int distance);
        int getDistance(){return distance;}
        Station* getStart(){return start;}
        Station* getEnd(){return end;}
};