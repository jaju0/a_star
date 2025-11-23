#ifndef A_STAR_HEURISTIC_FUNCTION_HPP_
#define A_STAR_HEURISTIC_FUNCTION_HPP_

#include <memory>

namespace a_star {

class HeuristicFunction
{
public:
    using SharedPtr = std::shared_ptr<HeuristicFunction>;

public:
    virtual float calculate(float x1, float y1, float x2, float y2) = 0;
};

}

#endif