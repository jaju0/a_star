#include <iostream>
#include "Grid.hpp"

namespace a_star {

Grid::Grid(uint32_t width, uint32_t height)
    : m_width(width)
    , m_height(height)
    , m_nodes(width * height)
{
}

void Grid::resetGrid()
{
    m_nodes.clear();

    for(uint32_t y = 0; y < m_height; ++y)
    {
        for(uint32_t x = 0; x < m_width; ++x)
        {
            m_nodes.push_back(std::make_shared<Node>(x, y, true));
        }
    }
}

void Grid::setObstacle(uint32_t x, uint32_t y)
{
    uint32_t pos = y * m_width + x;
    if(pos > m_width * m_height)
    {
        std::cerr << "tried to make a non existing Node outside the grid an obstacle at " << "x: " << x << " y: " << y << "!" << std::endl;
        return;
    }

    auto node = m_nodes.at(y * m_width + x);
    node->setWalkable(false);
}

Node::SharedPtr Grid::getNode(uint32_t x, uint32_t y) const
{
    uint32_t pos = y * m_width + x;
    if(pos > m_width * m_height)
    {
        std::cerr << "tried to access a non existing Node outside the grid at " << "x: " << x << " y: " << y << "!" << std::endl;
        return nullptr;
    }

    return m_nodes.at(pos);
}

Grid::NeighbourArray Grid::getNeighbours(int32_t x, int32_t y) const
{
    bool xOutOfBounds = x < 0 || x >= static_cast<int32_t>(m_width);
    bool yOutOfBounds = y < 0 || y >= static_cast<int32_t>(m_height);
    if(xOutOfBounds || yOutOfBounds)
    {
        std::cerr << "tried to get the neighbours of a non existing Node outside the grid at " << "x: " << x << " y: " << y << "!" << std::endl;
        return Grid::NeighbourArray();
    }

    int32_t posTopLeft[] = {x - 1, y - 1};
    int32_t posTop[] = {x, y - 1};
    int32_t posTopRight[] = {x + 1, y - 1};
    int32_t posRight[] = {x + 1, y};
    int32_t posBottomRight[] = {x + 1, y + 1};
    int32_t posBottom[] = {x, y + 1};
    int32_t posBottomLeft[] = {x - 1, y + 1};
    int32_t posLeft[] = {x - 1, y};

    auto getNeighbour = [this](int32_t coord[2], uint8_t index, NeighbourArray& neighbours) {
        if(isInGrid(coord[0], coord[1]))
        {
            neighbours[index] = getNode(coord[0], coord[1]);
        }
    };

    auto neighbours = NeighbourArray();
    getNeighbour(posTopLeft, TopLeftNeighbourIndex, neighbours);
    getNeighbour(posTop, TopNeighbourIndex, neighbours);
    getNeighbour(posTopRight, TopRightNeighbourIndex, neighbours);
    getNeighbour(posRight, RightNeighbourIndex, neighbours);
    getNeighbour(posBottomRight, BottomRightNeighbourIndex, neighbours);
    getNeighbour(posBottom, BottomNeighbourIndex, neighbours);
    getNeighbour(posBottomLeft, BottomLeftNeighbourIndex, neighbours);
    getNeighbour(posLeft, LeftNeighbourIndex, neighbours);

    return neighbours;
}

Grid::NeighbourArray Grid::getNeighbours(uint32_t x, uint32_t y) const
{
    return getNeighbours(static_cast<int32_t>(x), static_cast<int32_t>(y));
}

Grid::NeighbourArray Grid::getNeighbours(Node::SharedPtr node) const
{
    return getNeighbours(node->getX(), node->getY());
}

bool Grid::isInGrid(int32_t x, int32_t y) const
{
    return x >= 0 && x < static_cast<int32_t>(m_width) && y >= 0 && y < static_cast<int32_t>(m_height);
}

bool Grid::isInGrid(uint32_t x, uint32_t y) const
{
    return isInGrid(static_cast<int32_t>(x), static_cast<int32_t>(y));
}

}