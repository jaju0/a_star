#include <cmath>
#include "EuclideanDistance.hpp"

namespace a_star {

float EuclideanDistance::calculate(float x1, float y1, float x2, float y2)
{
    float xDiff = x1 - x2;
    float yDiff = y1 - y2;

    return std::sqrt(xDiff * xDiff + yDiff * yDiff);
}

}