//
// Created by stijn on 15/11/18.
//

#ifndef PROJECTGP_RANDOM_H
#define PROJECTGP_RANDOM_H

#include "Singleton.h"

class Random : public Singleton<Random>
{
private:
        /**
         * constructor voor Random
         */
        Random();

public:
        /**
         * genereer een random nummer tussen twee waarden
         * @param begin beginwaarde
         * @param end eindwaarde
         * @return random waarde
         */
        int random(int begin = 0, int end = 100);
};

#endif // PROJECTGP_RANDOM_H
