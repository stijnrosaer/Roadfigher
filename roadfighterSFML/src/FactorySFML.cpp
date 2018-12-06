#include <utility>

//
// Created by stijn on 29/11/18.
//

#include "../include/FactorySFML.h"
#include "../include/PlayerCarSFML.h"

roadfighterSFML::Factory::~Factory() {

}

shared_ptr<roadfighter::Entity> roadfighterSFML::Factory::createPlayerCar() {
    return make_shared<roadfighterSFML::PlayerCar>(this->window);
}

shared_ptr<roadfighter::Entity> roadfighterSFML::Factory::createPassingCar() {
    //return shared_ptr<roadfighter::Entity>(this->window);
}

roadfighterSFML::Factory::Factory(shared_ptr<sf::RenderWindow> w) {
    this->window = std::move(w);
}
