cmake_minimum_required(VERSION 3.20)

project(
  Colisoes
  LANGUAGES CXX)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
fetchcontent_declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 2.6.x)
fetchcontent_makeavailable(SFML)

add_library(ball
  STATIC
  ./src/Ball.cpp
  ./include/Ball.hpp)
target_include_directories(ball PUBLIC include)
target_compile_features(ball PUBLIC cxx_std_17)

add_library(coordinate
  STATIC
  ./src/Coordinate.cpp
  ./include/Coordinate.hpp)
target_include_directories(coordinate PUBLIC include)
target_compile_features(coordinate PUBLIC cxx_std_17)

add_library(constants
  STATIC
  ./include/Constants.hpp)
target_include_directories(constants PUBLIC include)
target_compile_features(constants PUBLIC cxx_std_17)

add_library(myrandom
  STATIC
  ./include/MyRandom.hpp
  ./src/MyRandom.cpp)
target_include_directories(myrandom PUBLIC include)
target_compile_features(myrandom PUBLIC cxx_std_17)

set_target_properties(ball coordinate constants myrandom
  PROPERTIES LINKER_LANGUAGE CXX)

add_executable(main ./src/main.cpp)

target_link_libraries(main
PRIVATE
sfml-graphics
ball
coordinate
constants
myrandom)

target_compile_features(main PRIVATE cxx_std_17)
