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

add_executable(main
./src/main.cpp
./src/Ball.cpp
./src/Vector.cpp
./src/Point.cpp)

target_include_directories(main PUBLIC ./include/)

target_link_libraries(main
PUBLIC
sfml-graphics)

target_compile_features(main PRIVATE cxx_std_17)
