//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_PASSINGPOINTSCAR_H
#define PROJECTGP_PASSINGPOINTSCAR_H

#include "Observable.h"
#include "PassingCar.h"

namespace roadfighter {
class PassingPointsCar : public roadfighter::PassingCar, public Observable
{
public:
        // constructor
        /**
         * deflaut constructor van passing car
         */
        PassingPointsCar();
        /**
         * destructor van PassingCar
         */
        ~PassingPointsCar() override;

        // functions
        /**
         * teken de passing car
         */
        void draw() override = 0;

        /**
         * voer actie uit wanneer een speler niet opnieuw moet beginnen
         * @return true als speler niet opnieuw moet beginnen
         */
        bool playerNoRespawn() override;
};
} // namespace roadfighter

#endif // PROJECTGP_PASSINGPOINTSCAR_H
