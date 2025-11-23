#ifndef A_STAR_APP_HPP_
#define A_STAR_APP_HPP_

#include "ProgramOptions.hpp"
#include "Grid.hpp"
#include "Renderer.hpp"

namespace a_star {

class App
{
private:
    ProgramOptions& m_programOptions;
    Grid::SharedPtr m_pGrid;
    Renderer::SharedPtr m_pRenderer;

    void init();
    void update();

    void loop();

public:
    App(ProgramOptions& programOptions);
    App(const App&) = delete;
    App& operator=(const App&) = delete;

    void start();
};

}

#endif 