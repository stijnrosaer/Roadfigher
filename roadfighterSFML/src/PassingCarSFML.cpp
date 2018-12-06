//
// Created by stijn on 16/11/18.
//

#include "../include/PassingCarSFML.h"
#include <utility>

roadfighterSFML::PassingCar::PassingCar(shared_ptr<sf::RenderWindow> window) {
    this->window = std::move(window);
    //this->texture.loadFromFile();
    sprite.setTexture(texture);

}

void roadfighterSFML::PassingCar::draw() {
    pixloc = Transformation::Instance()->transformTo2DWorldSpace(loc, window->getView().getSize().x, window->getView().getSize().y);
    sprite.setPosition(pixloc.first, pixloc.second);
    window->draw(sprite);
}
