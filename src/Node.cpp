#include "Node.hpp"

namespace a_star {

Node::Node()
    : m_x(0)
    , m_y(0)
    , m_walkable(true)
    , m_gCost(0.0f)
    , m_hCost(0.0f)
    , m_fCost(0.0f)
{

}

Node::Node(uint32_t x, uint32_t y, bool walkable)
    : m_x(x)
    , m_y(y)
    , m_walkable(walkable)
    , m_gCost(0.0f)
    , m_hCost(0.0f)
    , m_fCost(0.0f)
{

}

bool Node::operator==(const Node& b) const
{
    return m_x == b.m_x && m_y == b.m_y;
}

bool Node::equalCoords(const Node& b) const
{
    return m_x == b.m_x && m_y == b.m_y;
}

void Node::setWalkable(bool walkable)
{
    m_walkable = walkable;
}

uint32_t Node::getX() const
{
    return m_x;
}

uint32_t Node::getY() const
{
    return m_y;
}

bool Node::isWalkable() const
{
    return m_walkable;
}

float Node::getGCost() const
{
    return m_gCost;
}

float Node::getHCost() const
{
    return m_hCost;
}

float Node::getFCost() const
{
    return m_fCost;
}

Node::SharedPtr Node::getParent() const
{
    return m_pParent;
}

}