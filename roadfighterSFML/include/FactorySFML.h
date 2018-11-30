//
// Created by stijn on 29/11/18.
//

#ifndef PROJECTGP_FACTORY_SFML_H
#define PROJECTGP_FACTORY_SFML_H

#include "../../roadfighter/include/Factory.h"

namespace roadfighterSFML {
    class Factory : public roadfighter::Factory{
    public:
        virtual ~Factory();

        shared_ptr<roadfighter::Entity> createPlayerCar(shared_ptr<sf::RenderWindow> window) override;


    };
}

#endif //PROJECTGP_FACTORY_SFML_H
