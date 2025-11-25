<h1 align="center">A* Algorithm</h1>
<div align="center">
    <img alt="preview" src="./images/preview.gif" align="center" />
</div>

<br />

<details open>
    <summary>Table of Contents</summary>
    <ol>
        <li>
            <a href="#about-the-project">About The Project</a>
        </li>
        <li>
            <a href="#getting-started">Getting Started</a>
            <ul>
                <li>
                    <a href="#prerequisites">Prerequisites</a>
                    <ul>
                        <li>
                            <a href="#linux">Linux</a>
                        </li>
                    </ul>
                </li>
                <li>
                    <a href="#building-the-project">Building the Project</a>
                    <ul>
                        <li>
                            <a href="#linux-1">Linux</a>
                        </li>
                    </ul>
                </li>
            </ul>
        </li>
        <li>
            <a href="#usage">Usage</a>
            <ul>
                <li>
                    <a href="#configuration">Configuration</a>
                </li>
                <li>
                    <a href="#run">Run</a>
                </li>
            </ul>
        </li>
    </ol>
</details>

## About The Project

The A* algorithm is a pathfinding algorithm that finds the optimal path between two points in a graph by visiting each predefined point. This project implements a simple A* algorithm visualizer. SFML is used for rendering and capturing user input.

### Built with

* [![C++][C++]](https://isocpp.org/)
* [![CMake][CMake]](https://cmake.org/)
* [![Boost][Boost]](https://www.boost.org/)
* [![SFML][sfml]](https://www.sfml-dev.org/)


## Getting Started

### Prerequisites

#### Linux

* A **cmake** version of **3.22** or greater is required.
* You need to have **boost 1.82 or later** installed on your system. You can find it [here](https://www.boost.org/).
* You also need to have **SFML** installed on your system. You can find it in your distro repos or [here](https://www.sfml-dev.org/download/sfml/2.6.1/).

### Building The Project

#### Linux

* Clone this repository to your local machine using `git clone https://github.com/jaju0/a_star.git`.
* Navigate to the project directory using `cd a_star`.
* Run the configure.sh script to call cmake and generate the necessary files for building the project. You can use `./configure.sh` or `sh configure.sh`.
* Run the build.sh script to build the project using make. You can use `./build.sh` or `sh build.sh`.
* You should see an `a_star` executable file in the dist directory. You can run it using `./run.sh` or `./dist/a_star`.

## Usage

### Configuration



[C++]: https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white
[CMake]: https://img.shields.io/badge/CMake-064F8C?style=for-the-badge&logo=cmake&logoColor=white
[Boost]: https://img.shields.io/badge/Boost.org-Boost-orange?style=for-the-badge&labelColor=orange&color=orange
[SFML]: https://img.shields.io/badge/SFML-8CC445?style=for-the-badge&logo=sfml&logoColor=white