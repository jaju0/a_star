#include <algorithm>
#include "App.hpp"
#include "EuclideanDistance.hpp"
#include "ManhattanDistance.hpp"

namespace a_star {

App::App()
{
}

void App::start()
{
    init();
    loop();
}

void App::loop()
{
    while(m_pRenderer->isOpen())
    {
        update();
        m_pRenderer->render();
    }
}

void App::init()
{
    auto& programOptions = ProgramOptions::getInst();

    HeuristicFunction::SharedPtr heuristicFunction;

    if(programOptions.getDistanceFunction() == "manhattan")
        heuristicFunction = std::make_shared<ManhattanDistance>();
    else
        heuristicFunction = std::make_shared<EuclideanDistance>();

    m_pGrid = Grid::loadFromImageFile(ProgramOptions::getInst().getPathToGridFile());
    m_pAStar = std::make_shared<AStar>(m_pGrid, heuristicFunction);
    m_pRenderer = std::make_shared<Renderer>(m_pGrid);

    m_pAStar->init();
    m_pRenderer->init();
}

void App::update()
{
    m_keyboard.update();
    m_mouse.update();
    m_pRenderer->update(m_keyboard, m_mouse);

    if(m_keyboard.isKeyReleased(Keyboard::Q))
        m_pRenderer->close();
    if(m_keyboard.isKeyReleased(Keyboard::SPACE))
        m_pAStar->reset();
    if(m_keyboard.isKeyReleased(Keyboard::S))
        m_pAStar->stop();
    if(m_keyboard.isKeyReleased(Keyboard::R))
        m_pAStar->resume();

    int32_t nodeSize = static_cast<int32_t>(ProgramOptions::getInst().getNodeSize());
    int32_t gridWidth = static_cast<int32_t>(m_pGrid->getWidth());
    int32_t gridHeight = static_cast<int32_t>(m_pGrid->getHeight());
    int32_t mousePosX = m_mouse.getPosition().at(0);
    int32_t mousePosY = m_mouse.getPosition().at(1);
    uint32_t selectedNodeX = static_cast<uint32_t>(std::clamp(mousePosX / nodeSize, 0, gridWidth-1));
    uint32_t selectedNodeY = static_cast<uint32_t>(std::clamp(mousePosY / nodeSize, 0, gridHeight-1));
    auto selectedNode = m_pGrid->getNode(selectedNodeX, selectedNodeY);

    if(m_keyboard.isKeyPressed(Keyboard::Y))
    {
        if(m_mouse.isKeyReleased(Mouse::LEFT))
        {
            m_pGrid->setStartNode(selectedNodeX, selectedNodeY);
            m_pAStar->reset();
        }
    }
    else if(m_keyboard.isKeyPressed(Keyboard::X))
    {
        if(m_mouse.isKeyReleased(Mouse::LEFT))
        {
            m_pGrid->setTargetNode(selectedNodeX, selectedNodeY);
            m_pAStar->reset();
        }
    }
    else if(m_keyboard.isKeyPressed(Keyboard::C))
    {
        if(m_mouse.isKeyPressed(Mouse::LEFT))
            selectedNode->setWalkable(true);
    }
    else if(m_mouse.isKeyPressed(Mouse::LEFT))
        selectedNode->setWalkable(false);

    m_pAStar->update();
}

}