#ifndef A_STAR_PROGRAM_OPTIONS_HPP_
#define A_STAR_PROGRAM_OPTIONS_HPP_

#include <string>
#include <cstdint>
#include <boost/program_options.hpp>

namespace a_star {

class ProgramOptions
{
public:
    ProgramOptions();
    ProgramOptions(const ProgramOptions&) = delete;
    void operator=(const ProgramOptions&) = delete;

    static ProgramOptions& getInst();

    void loadFromConfigFile(const std::string& path);

    uint32_t getNodeSize();
    uint32_t getStepTime();
    bool diagonalNeighboursUsed();
    const std::string& getDistanceFunction();
    uint32_t getGridObstacleNodeColor();
    uint32_t getGridEmptyNodeColor();
    uint32_t getGridStartNodeColor();
    uint32_t getGridTargetNodeColor();
    uint32_t getGridOpenNodeColor();
    uint32_t getGridClosedNodeColor();
    uint32_t getGridPathNodeColor();
    uint32_t getGridOutlineColor();
    uint32_t getGridOutlineThickness();

    const std::string& getPathToGridFile();
    uint32_t getImageObstacleNodeColor();
    uint32_t getImageEmptyNodeColor();
    uint32_t getImageStartNodeColor();
    uint32_t getImageTargetNodeColor();

private:
    boost::program_options::options_description m_description;
    boost::program_options::variables_map m_varmap;

    uint32_t m_nodeSize;
    uint32_t m_stepTime;
    bool m_useDiagonalNeighbours;
    std::string m_distanceFunction;
    uint32_t m_gridObstacleNodeColor;
    uint32_t m_gridEmptyNodeColor;
    uint32_t m_gridStartNodeColor;
    uint32_t m_gridTargetNodeColor;
    uint32_t m_gridOpenNodeColor;
    uint32_t m_gridClosedNodeColor;
    uint32_t m_gridPathNodeColor;
    uint32_t m_gridOutlineColor;
    uint32_t m_gridOutlineThickness;

    std::string m_pathToGridFile;
    uint32_t m_imageObstacleNodeColor;
    uint32_t m_imageEmptyNodeColor;
    uint32_t m_imageStartNodeColor;
    uint32_t m_imageTargetNodeColor;
};

}

#endif