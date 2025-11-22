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
    float m_gCost;
    float m_hCost;
    float m_fCost;
    SharedPtr m_pParent;

public:
    Node();
    Node(uint32_t x, uint32_t y, bool walkable);
    Node(const Node&) = delete;

    bool operator==(const Node& b) const;
    bool equalCoords(const Node& b) const;

    void setWalkable(bool walkable);

    uint32_t getX() const;
    uint32_t getY() const;
    bool isWalkable() const;
    float getGCost() const;
    float getHCost() const;
    float getFCost() const;
    SharedPtr getParent() const;
};

}

#endif