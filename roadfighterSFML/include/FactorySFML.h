//
// Created by stijn on 29/11/18.
//

#ifndef PROJECTGP_FACTORY_SFML_H
#define PROJECTGP_FACTORY_SFML_H

#include "Factory.h"

namespace roadfighterSFML {
    class Factory : public roadfighter::Factory{
    private:
        shared_ptr<sf::RenderWindow> window;

    public:
        Factory(shared_ptr<sf::RenderWindow> window);

        virtual ~Factory();

        shared_ptr<roadfighter::Entity> createPlayerCar() override;
        shared_ptr<roadfighter::Entity> createPassingCar() override;


    };
}

#endif //PROJECTGP_FACTORY_SFML_H
