#ifndef A_STAR_MANHATTAN_DISTANCE_HPP_
#define A_STAR_MANHATTAN_DISTANCE_HPP_

#include <memory>
#include "HeuristicFunction.hpp"

namespace a_star {

class ManhattanDistance : public HeuristicFunction
{
public:
    using SharedPtr = std::shared_ptr<ManhattanDistance>;

public:
    virtual float calculate(float x1, float y1, float x2, float y2) override;
};

}

#endif