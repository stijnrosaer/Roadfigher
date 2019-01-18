//
// Created by stijn on 29/11/18.
//

#ifndef PROJECTGP_FACTORY_SFML_H
#define PROJECTGP_FACTORY_SFML_H

#include "../../game/include/Game.h"
#include "rf/Factory.h"

namespace roadfighterSFML {
class Factory : public roadfighter::Factory
{
private:
        shared_ptr<sf::RenderWindow> window;
        shared_ptr<Observer> game;

public:
        /**
         * maak een sfml object factory aan
         * @param window window waar de objecten op moeten tekenen
         * @param game game waaruit dat wordt opgeroepen
         */
        Factory(shared_ptr<sf::RenderWindow> window, shared_ptr<Observer> game);
        /**
         * destructor van factory
         */
        virtual ~Factory();
        /**
         * maak een playerCar aan
         * @return shared entity pointer naar een sfml playerCar
         */
        shared_ptr<roadfighter::Entity> createPlayerCar() override;
        /**
         * maake een passingCar aan
         * @return shared entity pointer naar een sfml passingCar
         */
        shared_ptr<roadfighter::Entity> createPassingNormalCar() override;
        /**
         * maak een passingPointsCar aan
         * @return shared entity pointer naar een sfml passingPointsCar
         */
        shared_ptr<roadfighter::Entity> createPassingPointsCar() override;
        /**
         * maak een bullet aan
         * @param loc locatie waar de bullet moet komen
         * @return shared entity pointer naar een sfml bullet
         */
        shared_ptr<roadfighter::Entity> createBullet(location loc) override;
        /**
         * maak een racingCar aan
         * @return shared entity pointer naar een sfml racingCar
         */
        shared_ptr<roadfighter::Entity> createRacingCar() override;
};
} // namespace roadfighterSFML

#endif // PROJECTGP_FACTORY_SFML_H
