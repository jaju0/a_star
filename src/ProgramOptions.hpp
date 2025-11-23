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

    const std::string& getPathToGridFile();
    uint32_t getNodeSize();

private:
    boost::program_options::options_description m_description;
    boost::program_options::variables_map m_varmap;

    std::string m_pathToGridFile;
    uint32_t m_nodeSize;
};

}

#endif