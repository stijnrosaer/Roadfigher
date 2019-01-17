//
// Created by stijn on 13/12/18.
//

#include "Background.h"
#include <iostream>

Background::Background(std::shared_ptr<sf::RenderWindow> window)
{
        bgTexture1.loadFromFile("../img/background.png");
        bgTexture1.setRepeated(true);

        bgSprite1.setTexture(bgTexture1);
        bgSprite1.scale(window->getView().getSize().x / bgTexture1.getSize().x,
                        window->getView().getSize().y / bgTexture1.getSize().y);
        bgSprite1.setPosition(0, 0);

        bgY = bgSprite1.getPosition().y;

        bgSprite1.setTextureRect(sf::IntRect(0, static_cast<int>(bgY), static_cast<int>(window->getView().getSize().x),
                                             static_cast<int>(window->getView().getSize().y)));
}

void Background::update(std::shared_ptr<sf::RenderWindow> window, float move)
{
        move = static_cast<float>((15.0 * move) / 350);
        if (bgY < window->getView().getSize().y) {
                bgY -= move;
        } else {
                bgY = 0;
        }

        bgSprite1.setTextureRect(sf::IntRect(0, static_cast<int>(bgY), static_cast<int>(window->getView().getSize().x),
                                             static_cast<int>(window->getView().getSize().y)));
}

void Background::draw(std::shared_ptr<sf::RenderWindow> window) { window->draw(bgSprite1); }

Background::Background() {}
