cmake_minimum_required(VERSION 3.20)

project(
  Colisoes
  VERSION 1.0.0
  LANGUAGES CXX)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(main ./src/main.cpp)
add_library(ball ./include/Ball.cpp ./include/Ball.hpp)
add_library(constants ./include/Constants.hpp)
add_library(coordinate ./include/Coordinate.cpp ./include/Coordinate.hpp)

target_link_libraries(main PRIVATE sfml-graphics ball constants coordinate)
target_compile_features(main PRIVATE cxx_std_17)
