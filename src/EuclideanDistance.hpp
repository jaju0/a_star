#ifndef A_STAR_EUCLIDEAN_DISTANCE_HPP_
#define A_STAR_EUCLIDEAN_DISTANCE_HPP_

#include "HeuristicFunction.hpp"

namespace a_star {

class EuclideanDistance : public HeuristicFunction
{
public:
    using SharedPtr = std::shared_ptr<EuclideanDistance>;

public:
    virtual float calculate(float x1, float y1, float x2, float y2) override;
};

}

#endif