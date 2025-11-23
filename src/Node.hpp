#ifndef A_STAR_NODE_HPP_
#define A_STAR_NODE_HPP_

#include <cstdint>
#include <memory>

namespace a_star {

class Node
{
public:
    using SharedPtr = std::shared_ptr<Node>;

private:
    uint32_t m_x;
    uint32_t m_y;
    bool m_walkable;
    bool m_isPartOfPath;
    bool m_isOpen;
    bool m_isClosed;
    float m_gCost;
    float m_hCost;
    float m_fCost;
    SharedPtr m_pParent;

public:
    Node();
    Node(uint32_t x, uint32_t y, bool walkable);
    Node(const Node&) = delete;

    bool operator==(const Node& b) const;
    bool operator!=(const Node& b) const;
    bool operator<(const Node& b) const;
    bool operator>(const Node& b) const;
    bool operator<=(const Node& b) const;
    bool operator>=(const Node& b) const;
    bool equalCoords(const Node& b) const;

    void setWalkable(bool walkable);
    void isPartOfPath(bool isPartOfPath);
    void isOpen(bool isOpen);
    void isClosed(bool isClosed);
    void setGCost(float gCost);
    void setHCost(float hCost);
    void setFCost(float fCost);
    void setParent(SharedPtr parent);

    uint32_t getX() const;
    uint32_t getY() const;
    bool isWalkable() const;
    bool isPartOfPath() const;
    bool isOpen() const;
    bool isClosed() const;
    float getGCost() const;
    float getHCost() const;
    float getFCost() const;
    SharedPtr getParent() const;
};

}

#endif