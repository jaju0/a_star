#include <cmath>
#include "ManhattanDistance.hpp"

namespace a_star {

float ManhattanDistance::calculate(float x1, float y1, float x2, float y2)
{
    return std::fabs(x1 - x2) + std::fabs(y1 - y2);
}

}