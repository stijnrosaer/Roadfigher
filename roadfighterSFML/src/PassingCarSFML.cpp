//
// Created by stijn on 16/11/18.
//

#include "../include/PassingCarSFML.h"

roadfighterSFML::PassingCar::PassingCar(shared_ptr<sf::RenderWindow> window) {
    this->window = std::move(window);
    this->texture.loadFromFile("../img/passing_car.png");
    sprite.setTexture(texture);
    sprite.scale(2.2f, 2.2f);

}

void roadfighterSFML::PassingCar::draw() {
    pixloc = Transformation::getInstance()->transformTo2DWorldSpace(loc, this->window->getView().getSize().x, this->window->getView().getSize().y);
    sprite.setPosition(pixloc.first, pixloc.second);
    window->draw(sprite);
}

void roadfighterSFML::PassingCar::update(float speed, vector<shared_ptr<Entity>> entities) {
    roadfighter::PassingCar::update(speed, entities);
    loc = Transformation::getInstance()->transformToPixelSpace({pixloc.first, pixloc.second - (15*this->relativeSpeed)/400}, window->getView().getSize().x, window->getView().getSize().y);

    if (loc.second < -3){
        cout << "";
//        shared_from_this().reset();

    }
}

roadfighterSFML::PassingCar::~PassingCar(){

};
