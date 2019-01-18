//
// Created by stijn on 15/11/18.
//

#include "../include/Random.h"
#include <ctime>
#include <random>

int Random::random(int begin, int end) { return std::rand() % (end - begin) + begin; }

Random::Random() { srand(static_cast<unsigned int>(time(nullptr))); }

bool Random::chance(double probability)
{
        auto result = std::rand() % 100;
        return probability * 100 > result;
}
