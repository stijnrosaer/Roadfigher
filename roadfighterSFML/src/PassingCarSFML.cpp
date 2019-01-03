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
    pixloc = Transformation::getInstance()->to2DWorldSpace(bounds.tlLoc, this->window->getView().getSize().x,
                                                           this->window->getView().getSize().y);
    sprite.setPosition(pixloc.x, pixloc.y);
    window->draw(sprite);
}

void roadfighterSFML::PassingCar::update(float speed, vector<shared_ptr<Entity>> entities) {
    roadfighter::PassingCar::update(speed, entities);
    setLoc(Transformation::getInstance()->toPixelSpace({pixloc.x, pixloc.y - (15 * this->relativeSpeed) / 400},
                                                       window->getView().getSize().x, window->getView().getSize().y));

}

roadfighterSFML::PassingCar::~PassingCar(){

};
