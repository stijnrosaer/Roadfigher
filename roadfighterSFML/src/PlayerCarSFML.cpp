#include <utility>

//
// Created by stijn on 16/11/18.
//

#include "../include/PlayerCarSFML.h"
#include <utility>

roadfighterSFML::PlayerCar::PlayerCar(shared_ptr<sf::RenderWindow> window, shared_ptr<Observer> game)
{
        this->window = std::move(window);
        sf::Texture car;
        sf::Texture exp0;
        sf::Texture exp1;
        sf::Texture exp2;
        sf::Texture exp3;
        car.loadFromFile("../img/player_car.png");
        exp0.loadFromFile("../img/explosion0.png");
        exp1.loadFromFile("../img/explosion1.png");
        exp2.loadFromFile("../img/explosion2.png");
        exp3.loadFromFile("../img/explosion3.png");

        this->textures.emplace_back(car);
        this->textures.emplace_back(exp0);
        this->textures.emplace_back(exp1);
        this->textures.emplace_back(exp2);
        this->textures.emplace_back(exp3);

        sprite.setTexture(textures[0]);
        sprite.scale(2.2f, 2.2f);

        this->addObserver(std::move(game));
}

void roadfighterSFML::PlayerCar::draw()
{
        pixloc = Transformation::getInstance()->to2DWorldSpace(bounds.tlLoc, this->window->getView().getSize().x,
                                                               this->window->getView().getSize().y);
        sprite.setPosition(pixloc.x, pixloc.y);
        window->draw(sprite);
}

void roadfighterSFML::PlayerCar::update(float speed, vector<shared_ptr<Entity>> entities)
{
        roadfighter::PlayerCar::update(speed, entities);

        if (exploding <= 50 && exploding > 0) {
                if (exploding == 3) {
                        sprite.setTexture(textures[1]);
                        return;
                } else if (exploding == 6) {
                        sprite.setTexture(textures[2]);
                        return;
                } else if (exploding == 9) {
                        sprite.setTexture(textures[3]);
                        return;
                } else if (exploding == 12) {
                        sprite.setTexture(textures[3]);
                        return;
                } else if (exploding == 50) {
                        sprite.setTexture(textures[0]);
                        return;
                }
                return;
        }

        bool speedKeyPressed = false;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                movePlayerCar(up);

                speedKeyPressed = true;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                movePlayerCar(down);
                speedKeyPressed = true;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                movePlayerCar(left);

        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                movePlayerCar(right);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                if (waitForShoot == 0) {
                        callObserver(shoot);
                        reload();
                }
        }
        if (!speedKeyPressed) {
                movePlayerCar(slow);
        }

        callObserver(mv);
}
