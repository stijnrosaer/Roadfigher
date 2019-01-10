//
// Created by stijn on 29/11/18.
//

#include "../include/FactorySFML.h"
#include "../include/BulletSFML.h"
#include "../include/PassingCarSFML.h"
#include "../include/PlayerCarSFML.h"
#include "../include/RacingCarSFML.h"

roadfighterSFML::Factory::~Factory() {}

shared_ptr<roadfighter::Entity> roadfighterSFML::Factory::createPlayerCar()
{
        return make_shared<roadfighterSFML::PlayerCar>(this->window, this->game);
}

shared_ptr<roadfighter::Entity> roadfighterSFML::Factory::createPassingCar()
{
        return make_shared<roadfighterSFML::PassingCar>(this->window);
}

roadfighterSFML::Factory::Factory(shared_ptr<sf::RenderWindow> w, shared_ptr<Observer> g)
{
        this->window = std::move(w);
        this->game = std::move(g);
}

shared_ptr<roadfighter::Entity> roadfighterSFML::Factory::createBullet(location loc)
{
        return make_shared<roadfighterSFML::Bullet>(this->window, loc, this->game);
}

shared_ptr<roadfighter::Entity> roadfighterSFML::Factory::createRacingCar() {
    return make_shared<roadfighterSFML::RacingCar>(this->window);
}
