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

        virtual std::shared_ptr<roadfighter::Entity> createPlayerCar() = 0;
        virtual std::shared_ptr<roadfighter::Entity> createPassingCar() = 0;

    };
}


#endif //PROJECTGP_FACTORY_H
