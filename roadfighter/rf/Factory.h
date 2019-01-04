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
        virtual ~Factory();

        virtual std::shared_ptr<roadfighter::Entity> createPlayerCar() = 0;
        virtual std::shared_ptr<roadfighter::Entity> createPassingCar() = 0;
        virtual std::shared_ptr<roadfighter::Entity> createBullet(location loc) = 0;
};
} // namespace roadfighter

#endif // PROJECTGP_FACTORY_H
