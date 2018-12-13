//
// Created by stijn on 16/11/18.
//

#include "../include/PlayerCarSFML.h"
#include <utility>


roadfighterSFML::PlayerCar::PlayerCar(shared_ptr<sf::RenderWindow> window) {
    this->window = std::move(window);
    this->texture.loadFromFile("../img/player_car.png");
    sprite.setTexture(texture);
    sprite.scale(2.0f, 2.0f);

    pixloc = Transformation::getInstance()->transformTo2DWorldSpace(loc, this->window->getView().getSize().x, this->window->getView().getSize().y);

}


void roadfighterSFML::PlayerCar::draw() {
    sprite.setPosition(pixloc.first, pixloc.second);
    window->draw(sprite);
}

void roadfighterSFML::PlayerCar::update() {
    PlayerCar::update();
}
