#ifndef A_STAR_APP_HPP_
#define A_STAR_APP_HPP_

#include "ProgramOptions.hpp"
#include "Grid.hpp"
#include "AStar.hpp"
#include "Renderer.hpp"
#include "Keyboard.hpp"

namespace a_star {

class App
{
private:
    Grid::SharedPtr m_pGrid;
    AStar::SharedPtr m_pAStar;
    Renderer::SharedPtr m_pRenderer;
    Keyboard m_keyboard;

    void init();
    void update();

    void loop();

public:
    App();
    App(const App&) = delete;
    App& operator=(const App&) = delete;

    void start();
};

}

#endif 