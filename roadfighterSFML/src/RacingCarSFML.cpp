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
    pixloc = Transformation::getInstance()->to2DWorldSpace(bounds.tlLoc, window->getView().getSize().x,
                                                           window->getView().getSize().y);
    sprite.setPosition(static_cast<float>(pixloc.x), static_cast<float>(pixloc.y));
    window->draw(sprite);
}

void roadfighterSFML::RacingCar::update(float speed, vector<shared_ptr<Entity>> entities) {
//    RacingCar::update();
}
