//
// Created by stijn on 29/11/18.
//

#ifndef PROJECTGP_FACTORY_H
#define PROJECTGP_FACTORY_H

#include <memory>
#include <SFML/Graphics.hpp>
#include "Entity.h"

namespace roadfighter {
    class Factory {
    public:
        virtual ~Factory();

        virtual std::shared_ptr<roadfighter::Entity> createPlayerCar(shared_ptr<sf::RenderWindow> window) = 0;
        virtual std::shared_ptr<roadfighter::Entity> createPassingCar(shared_ptr<sf::RenderWindow> window) = 0;

    };
}


#endif //PROJECTGP_FACTORY_H
