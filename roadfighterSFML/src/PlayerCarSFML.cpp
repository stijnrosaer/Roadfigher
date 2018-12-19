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
    pixloc = Transformation::getInstance()->transformTo2DWorldSpace(bounds.tlLoc, this->window->getView().getSize().x, this->window->getView().getSize().y);
    sprite.setPosition(pixloc.first, pixloc.second);
    window->draw(sprite);
}

void roadfighterSFML::PlayerCar::update(float speed, vector<shared_ptr<Entity>> entities) {
    bool speedKeyPressed = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        this->speed += 5;
        if (this->speed > 400){
            this->speed = 400;
        }
        speedKeyPressed = true;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        this->speed -= 10;
        if (this->speed < 0){
            this->speed = 0;
        }
        speedKeyPressed = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        if (bounds.loc.first > -1.3) {
            this->setLoc({bounds.loc.first - 0.07, bounds.loc.second});
        }

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        if (bounds.loc.first < 1.1) {
            this->setLoc({bounds.loc.first + 0.07, bounds.loc.second});
        }

    }
    if (!speedKeyPressed) {
        this->speed -= 3;
        if (this->speed < 0) {
            this->speed = 0;
        }
    }
}
