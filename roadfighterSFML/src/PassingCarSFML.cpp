#include <utility>

//
// Created by stijn on 16/11/18.
//

#include "../include/PassingCarSFML.h"

roadfighterSFML::PassingCar::PassingCar(shared_ptr<sf::RenderWindow> window, shared_ptr<Observer> game)
{
        this->addObserver(std::move(game));
        this->window = std::move(window);
        this->texture.loadFromFile("../img/passing_car.png");
        sprite.setTexture(texture);
        sprite.scale(2.2f, 2.2f);
}

void roadfighterSFML::PassingCar::draw()
{
        pixloc = Transformation::getInstance()->to2DWorldSpace(bounds.tlLoc, this->window->getView().getSize().x,
                                                               this->window->getView().getSize().y);
        sprite.setPosition(static_cast<float>(pixloc.x), static_cast<float>(pixloc.y));
        window->draw(sprite);
}

void roadfighterSFML::PassingCar::update(float speed, vector<shared_ptr<Entity>> entities)
{
        roadfighter::PassingCar::update(speed, entities);
        movePassingCar();
}

roadfighterSFML::PassingCar::~PassingCar() {}

void roadfighterSFML::PassingCar::setDelete(bool del) { this->del = del; }

bool roadfighterSFML::PassingCar::playerNoRespawn() { return false; };
