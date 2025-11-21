#ifndef A_STAR_PROGRAM_OPTIONS_HPP_
#define A_STAR_PROGRAM_OPTIONS_HPP_

#include <string>
#include <cstdint>
#include <boost/program_options.hpp>

namespace a_star {

class ProgramOptions
{
public:
    ProgramOptions(const std::string& configFile);

    uint32_t getWindowWidth();
    uint32_t getWindowHeight();
    bool isFullscreen();

private:
    boost::program_options::options_description m_description;
    boost::program_options::variables_map m_varmap;

    uint32_t m_windowWidth;
    uint32_t m_windowHeight;
    bool m_fullscreen;
};

}

#endif