//
// Created by stijn on 16/11/18.
//

#include "../include/RacingCarSFML.h"
#include <utility>

roadfighterSFML::RacingCar::RacingCar(shared_ptr<sf::RenderWindow> window) {
    this->window = std::move(window);
    //this->texture.loadFromFile();
    sprite.setTexture(texture);
}

void roadfighterSFML::RacingCar::draw() {
    pixloc = Transformation::getInstance()->transformTo2DWorldSpace(loc, window->getView().getSize().x, window->getView().getSize().y);
    sprite.setPosition(pixloc.first, pixloc.second);
    window->draw(sprite);
}
