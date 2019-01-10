//
// Created by stijn on 29/11/18.
//

#ifndef PROJECTGP_FACTORY_SFML_H
#define PROJECTGP_FACTORY_SFML_H

#include "../../Game.h"
#include "rf/Factory.h"

namespace roadfighterSFML {
class Factory : public roadfighter::Factory
{
private:
        shared_ptr<sf::RenderWindow> window;
        shared_ptr<Observer> game;

public:
        Factory(shared_ptr<sf::RenderWindow> window, shared_ptr<Observer> game);

        virtual ~Factory();

        shared_ptr<roadfighter::Entity> createPlayerCar() override;
        shared_ptr<roadfighter::Entity> createPassingCar() override;
        shared_ptr<roadfighter::Entity> createBullet(location loc) override;
    shared_ptr<roadfighter::Entity> createRacingCar() override;
};
} // namespace roadfighterSFML

#endif // PROJECTGP_FACTORY_SFML_H
