# Minimum version of CMAKE
cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(adventCode2024  VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add sub project
add_subdirectory(day01)
add_subdirectory(day02)
add_subdirectory(day03)
add_subdirectory(day04)
add_subdirectory(day05)

# # Activer les tests
# enable_testing()
