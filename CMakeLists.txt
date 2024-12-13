# Minimum version of CMAKE
cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(adventCode2024  VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# # Ajout de Catch2
# include(FetchContent)
# FetchContent_Declare(
#   Catch2
#   GIT_REPOSITORY https://github.com/catchorg/Catch2.git
#   GIT_TAG v3.4.0
# )
# FetchContent_MakeAvailable(Catch2)


# list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)


# Add sub project
add_subdirectory(day01)
add_subdirectory(day02)
add_subdirectory(day03)
# add_subdirectory(beerUnitTest)
# add_subdirectory(beerConsole)

# # Activer les tests
# enable_testing()
