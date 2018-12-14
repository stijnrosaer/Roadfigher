//
// Created by stijn on 16/11/18.
//

#include "../include/PlayerCarSFML.h"
#include <utility>


roadfighterSFML::PlayerCar::PlayerCar(shared_ptr<sf::RenderWindow> window) {
    this->window = std::move(window);
    this->texture.loadFromFile("../img/player_car.png");
    sprite.setTexture(texture);
    sprite.scale(2.2f, 2.2f);

}


void roadfighterSFML::PlayerCar::draw() {
    pixloc = Transformation::getInstance()->transformTo2DWorldSpace(tlLoc, this->window->getView().getSize().x, this->window->getView().getSize().y);
    sprite.setPosition(pixloc.first, pixloc.second);
    window->draw(sprite);
}

void roadfighterSFML::PlayerCar::update() {
    bool speedKeyPressed = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        speed += 5;
        if (speed > 400){
            speed = 400;
        }
        speedKeyPressed = true;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        speed -= 10;
        if (speed < 0){
            speed = 0;
        }
        speedKeyPressed = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        if (loc.first > -1.3) {
            this->setLoc({loc.first - 0.07, loc.second});
        }

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        if (loc.first < 1.1) {
            this->setLoc({loc.first + 0.07, loc.second});
        }

    }
    if (!speedKeyPressed){
        speed -= 3;
        if (speed < 0){
            speed = 0;
        }
    }
}
