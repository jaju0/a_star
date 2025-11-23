#ifndef A_STAR_ASTAR_HPP_
#define A_STAR_ASTAR_HPP_

#include <memory>
#include <list>

#include "HeuristicFunction.hpp"
#include "Node.hpp"
#include "Grid.hpp"

namespace a_star {

class AStar
{
public:
    using SharedPtr = std::shared_ptr<AStar>;

private:
    Grid::SharedPtr m_pGrid;
    HeuristicFunction::SharedPtr m_pHeuristicFunction;
    std::list<Node::SharedPtr> m_openList;
    std::list<Node::SharedPtr> m_closedList;

    Node::SharedPtr m_pCurrentNode;
    bool m_isPathReconstructed;

    void moveNodeToOpenList(Node::SharedPtr node);
    void moveNodeToClosedList(Node::SharedPtr node);
    void reconstructPath();

public:
    AStar(Grid::SharedPtr pGrid, HeuristicFunction::SharedPtr pHeuristicFunction);

    void init();
    void update();
};

}

#endif