#ifndef A_STAR_GRID_HPP_
#define A_STAR_GRID_HPP_

#include <memory>
#include <vector>
#include <array>
#include <string>

#include "Node.hpp"

namespace a_star {

class Grid
{
public:
    using SharedPtr = std::shared_ptr<Grid>;
    using NeighbourArray = std::array<Node::SharedPtr, 8>;
    static constexpr const uint8_t TopLeftNeighbourIndex = 0;
    static constexpr const uint8_t TopNeighbourIndex = 1;
    static constexpr const uint8_t TopRightNeighbourIndex = 2;
    static constexpr const uint8_t RightNeighbourIndex = 3;
    static constexpr const uint8_t BottomRightNeighbourIndex = 4;
    static constexpr const uint8_t BottomNeighbourIndex = 5;
    static constexpr const uint8_t BottomLeftNeighbourIndex = 6;
    static constexpr const uint8_t LeftNeighbourIndex = 7;

private:
    uint32_t m_width;
    uint32_t m_height;
    Node::SharedPtr m_pStartNode;
    Node::SharedPtr m_pTargetNode;
    std::vector<Node::SharedPtr> m_nodes;

public:
    Grid(uint32_t width, uint32_t height);
    Grid(const Grid&) = delete;
    Grid& operator=(const Grid&) = delete;

    void resetGrid();
    void setStartNode(uint32_t x, uint32_t y);
    void setTargetNode(uint32_t x, uint32_t y);
    void setObstacle(uint32_t x, uint32_t y);

    uint32_t getWidth() const;
    uint32_t getHeight() const;
    Node::SharedPtr getStartNode() const;
    Node::SharedPtr getTargetNode() const;
    Node::SharedPtr getNode(uint32_t x, uint32_t y) const;
    NeighbourArray getNeighbours(int32_t x, int32_t y) const;
    NeighbourArray getNeighbours(uint32_t x, uint32_t y) const;
    NeighbourArray getNeighbours(Node::SharedPtr node) const;

    bool isInGrid(int32_t x, int32_t y) const;
    bool isInGrid(uint32_t x, uint32_t y) const;

    static SharedPtr loadFromImageFile(const std::string& path);
};

}

#endif