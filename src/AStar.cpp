#include <algorithm>
#include "AStar.hpp"
#include "ProgramOptions.hpp"

namespace a_star {

AStar::AStar(Grid::SharedPtr pGrid, HeuristicFunction::SharedPtr pHeuristicFunction)
    : m_pGrid(pGrid)
    , m_pHeuristicFunction(pHeuristicFunction)
    , m_isPathReconstructed(false)
{
}


void AStar::init()
{
    m_openList.clear();
    m_closedList.clear();
    m_path.clear();

    auto startNode = m_pGrid->getStartNode();
    auto targetNode = m_pGrid->getTargetNode();

    startNode->setGCost(0);
    startNode->setHCost(m_pHeuristicFunction->calculate(startNode->getX(), startNode->getY(), targetNode->getX(), targetNode->getY()));
    startNode->setFCost(startNode->getGCost() + startNode->getHCost());
    startNode->setParent(nullptr);

    moveNodeToOpenList(startNode);
    m_pCurrentNode = startNode;
}

void AStar::update()
{
    int32_t stepTime = static_cast<int32_t>(ProgramOptions::getInst().getStepTime());
    if(m_clock.getElapsedTime().asMilliseconds() < stepTime)
        return;

    auto targetNode = m_pGrid->getTargetNode();

    bool foundPath = m_pCurrentNode->equalCoords(*targetNode);
    bool isFinished = foundPath || !m_openList.size();

    if(foundPath)
    {
        if(!m_isPathReconstructed)
        {
            reconstructPath();
            return;
        }

        if(m_path.size() > 0)
        {
            m_path.front()->isPartOfPath(true);
            m_path.pop_front();
        }
    }

    if(isFinished)
        return;

    m_pCurrentNode = *std::min_element(m_openList.begin(), m_openList.end(), [](Node::SharedPtr a, Node::SharedPtr b) {
        return (*a) < (*b);
    });

    moveNodeToClosedList(m_pCurrentNode);

    auto neighbours = m_pGrid->getNeighbours(m_pCurrentNode);
    for(auto neighbour : neighbours)
    {
        if(!neighbour)
            continue;
        
        if(!neighbour->isWalkable())
            continue;

        bool neighbourFoundInClosedList = std::find(m_closedList.begin(), m_closedList.end(), neighbour) != m_closedList.end();
        if(neighbourFoundInClosedList)
            continue;
        
        float distance = m_pHeuristicFunction->calculate(m_pCurrentNode->getX(), m_pCurrentNode->getY(), neighbour->getX(), neighbour->getY());
        float tentativeG = m_pCurrentNode->getGCost() + distance;

        bool neighbourFoundInOpenList = std::find(m_openList.begin(), m_openList.end(), neighbour) != m_openList.end();
        if(!neighbourFoundInOpenList)
            moveNodeToOpenList(neighbour);
        else if(tentativeG >= neighbour->getGCost())
            continue;
        
        float hCost = m_pHeuristicFunction->calculate(neighbour->getX(), neighbour->getY(), targetNode->getX(), targetNode->getY());
        neighbour->setParent(m_pCurrentNode);
        neighbour->setGCost(tentativeG);
        neighbour->setHCost(hCost);
        neighbour->setFCost(neighbour->getGCost() + neighbour->getHCost());
    }

    m_clock.restart();
}

void AStar::moveNodeToOpenList(Node::SharedPtr node)
{
    node->isOpen(true);
    node->isClosed(false);
    m_openList.push_back(node);
}

void AStar::moveNodeToClosedList(Node::SharedPtr node)
{
    node->isOpen(false);
    node->isClosed(true);
    m_openList.remove(node);
    m_closedList.push_back(node);
}

void AStar::reconstructPath()
{
    for(auto node = m_pCurrentNode; node != nullptr; node = node->getParent())
    {
        m_path.push_front(node);
    }

    m_isPathReconstructed = true;
}

}