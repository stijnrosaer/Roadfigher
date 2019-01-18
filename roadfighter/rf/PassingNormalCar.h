//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_PASSINGNORMALCAR_H
#define PROJECTGP_PASSINGNORMALCAR_H

#include "PassingCar.h"

namespace roadfighter {
class PassingNormalCar : public roadfighter::PassingCar
{
public:
        // constructor
        /**
         * deflaut constructor van passing car
         */
        PassingNormalCar();

        // functions
        /**
         * teken de passing car
         */
        void draw() override = 0;
        /**
         * update de passingCar
         * @param speed snelheid van de player
         * @param entities entities waarmee rekening te houden
         */

        bool playerNoRespawn() override;
};
} // namespace roadfighter

#endif // PROJECTGP_PASSINGNORMALCAR_H
