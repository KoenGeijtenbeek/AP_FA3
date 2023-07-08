#include "Station.hpp"

struct StationGreaterThan {
    bool operator()(const Station* lhs, const Station* rhs) const;
};