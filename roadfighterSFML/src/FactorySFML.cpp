//
// Created by stijn on 29/11/18.
//

#include "../include/FactorySFML.h"
#include "../include/PlayerCarSFML.h"

roadfighterSFML::Factory::~Factory() {

}

shared_ptr<roadfighter::Entity> roadfighterSFML::Factory::createPlayerCar(shared_ptr<sf::RenderWindow> window) {
    return make_shared<roadfighterSFML::PlayerCar>(window);
}

shared_ptr<roadfighter::Entity> roadfighterSFML::Factory::createPassingCar(shared_ptr<sf::RenderWindow> window) {
    return shared_ptr<roadfighter::Entity>();
}
