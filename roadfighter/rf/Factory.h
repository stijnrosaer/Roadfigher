//
// Created by stijn on 29/11/18.
//

#ifndef PROJECTGP_FACTORY_H
#define PROJECTGP_FACTORY_H

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <memory>

namespace roadfighter {
class Factory
{
public:
        /**
         * maak een playerCar aan
         * @return shared entity pointer naar een playerCar
         */
        virtual std::shared_ptr<roadfighter::Entity> createPlayerCar() = 0;
        /**
         * maak een passingCar aan
         * @return shared entity pointer naar een passingCar
         */
        virtual std::shared_ptr<roadfighter::Entity> createPassingCar() = 0;
        /**
         * maak een passingPointsCar aan
         * @return shared entity pointer naar een passingPointsCar
         */
        virtual std::shared_ptr<roadfighter::Entity> createPassingPointsCar() = 0;
        /**
         * maak een bullet aan op een specifieke locatie
         * @param loc locatie waar de bullet aangemaakt moet worden
         * @return shared entity pointer naar een bullet
         */
        virtual std::shared_ptr<roadfighter::Entity> createBullet(location loc) = 0;
        /**
         * maak een racingCar aan
         * @return shared entity pointer naar een racingCar
         */
        virtual std::shared_ptr<roadfighter::Entity> createRacingCar() = 0;
};
} // namespace roadfighter

#endif // PROJECTGP_FACTORY_H
