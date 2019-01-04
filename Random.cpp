//
// Created by stijn on 15/11/18.
//

#include "Random.h"
#include <ctime>
#include <random>

int Random::random(int begin, int end) { return std::rand() % (end - begin) + begin; }

Random::Random() { srand(static_cast<unsigned int>(time(nullptr))); }
