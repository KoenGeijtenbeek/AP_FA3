#include "include/StationGreaterThan.hpp"

bool StationGreaterThan::operator()(const Station* lhs, const Station* rhs) const{
    return *lhs > *rhs;
}