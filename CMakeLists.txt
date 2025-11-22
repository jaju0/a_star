cmake_minimum_required(VERSION 3.22)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()


set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

project(a_star)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/ProgramOptions.cpp
    src/Node.cpp
    src/Grid.cpp
    src/Renderer.cpp
)

target_link_libraries(${PROJECT_NAME}
    sfml-graphics
    sfml-window
    sfml-system
    boost_program_options
)