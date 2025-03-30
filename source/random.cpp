#include "../include/random.hpp"

#include <SFML/System/Vector2.hpp>
#include <cassert>
#include <chrono>
#include <cmath>
#include <random>

#include "../include/constants.hpp"

//////////////////////////////////////////////////////////////////////////////////////////
// SEED

std::default_random_engine rng(static_cast<size_t>(
    std::chrono::steady_clock::now().time_since_epoch().count()));

//////////////////////////////////////////////////////////////////////////////////////////
// Generate a RANDOM INTEGER (SIZE_T) in the RANGE [min, max], inclusive

size_t randomInt(size_t min, size_t max) {
  std::uniform_int_distribution dist(min, max);
  return dist(rng);
}

//////////////////////////////////////////////////////////////////////////////////////////
// Generate a random FLOAT in the range (min, max]

float randomFloat(float min, float max) {
  std::uniform_real_distribution dist(min, max);
  return dist(rng);
}
