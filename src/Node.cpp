#include "Node.hpp"

namespace a_star {

Node::Node()
    : m_x(0)
    , m_y(0)
    , m_walkable(true)
    , m_isPartOfPath(false)
    , m_isOpen(false)
    , m_isClosed(false)
    , m_gCost(0.0f)
    , m_hCost(0.0f)
    , m_fCost(0.0f)
{

}

Node::Node(uint32_t x, uint32_t y, bool walkable)
    : m_x(x)
    , m_y(y)
    , m_walkable(walkable)
    , m_isPartOfPath(false)
    , m_isOpen(false)
    , m_isClosed(false)
    , m_gCost(0.0f)
    , m_hCost(0.0f)
    , m_fCost(0.0f)
{

}

bool Node::operator==(const Node& b) const
{
    return m_fCost == b.m_fCost;
}

bool Node::operator!=(const Node& b) const
{
    return m_fCost != b.m_fCost;
}

bool Node::operator<(const Node& b) const
{
    return m_fCost == b.m_fCost ? m_hCost < b.m_hCost : m_fCost < b.m_fCost;
}

bool Node::operator>(const Node& b) const
{
    return m_fCost == b.m_fCost ? m_hCost > b.m_hCost : m_fCost > b.m_fCost;
}

bool Node::operator<=(const Node& b) const
{
    return m_fCost <= b.m_fCost;
}

bool Node::operator>=(const Node& b) const
{
    return m_fCost >= b.m_fCost;
}

bool Node::equalCoords(const Node& b) const
{
    return m_x == b.m_x && m_y == b.m_y;
}

void Node::setWalkable(bool walkable)
{
    m_walkable = walkable;
}

void Node::isPartOfPath(bool isPartOfPath)
{
    m_isPartOfPath = isPartOfPath;
}

void Node::isOpen(bool isOpen)
{
    m_isOpen = isOpen;
}

void Node::isClosed(bool isClosed)
{
    m_isClosed = isClosed;
}

void Node::setGCost(float gCost)
{
    m_gCost = gCost;
}

void Node::setHCost(float hCost)
{
    m_hCost = hCost;
}

void Node::setFCost(float fCost)
{
    m_fCost = fCost;
}

void Node::setParent(SharedPtr parent)
{
    m_pParent = parent;
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

bool Node::isPartOfPath() const
{
    return m_isPartOfPath;
}

bool Node::isOpen() const
{
    return m_isOpen;
}

bool Node::isClosed() const
{
    return m_isClosed;
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