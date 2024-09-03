#include "MyRandom.hpp"
#include <random>

float randFloat(int min, int max) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> distr(min, max);

  return distr(gen);
}
