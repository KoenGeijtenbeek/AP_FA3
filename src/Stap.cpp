#include "include/Stap.hpp"

std::ostream &operator<<(std::ostream &os, Stap& stap){
    os << stap.start->getName() << " naar " << stap.end->getName() << ": " << stap.getDistance() << std::endl;
    return os;
}