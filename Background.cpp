//
// Created by stijn on 13/12/18.
//

#include <iostream>
#include "Background.h"

Background::Background(std::shared_ptr<sf::RenderWindow> window) {
    bgTexture1.loadFromFile("../img/background.png");
    bgTexture1.setRepeated(true);
    bgTexture2.loadFromFile("../img/background.png");
    bgTexture2.setRepeated(true);

    bgSprite1.setTexture(bgTexture1);
    bgSprite2.setTexture(bgTexture2);

    bgSprite1.scale(float(window->getView().getSize().x)/bgTexture1.getSize().x, float(window->getView().getSize().y)/bgTexture1.getSize().y);
    bgSprite2.scale(float(window->getView().getSize().x)/bgTexture2.getSize().x, float(window->getView().getSize().y)/bgTexture2.getSize().y);

    bgSprite2.setPosition(0, -window->getView().getSize().y);

    bgY = bgSprite1.getPosition().y;
    bgY2 = bgSprite2.getPosition().y;

}

void Background::update(std::shared_ptr<sf::RenderWindow> window, float move) {
    if (bgY < window->getView().getSize().y){
        bgY += move;
    } else{
        bgY = window->getView().getSize().y;
        bgY *= -1;
    }
    if (bgY2 < window->getView().getSize().y){
        bgY2 += move;
    } else{
        bgY2 = window->getView().getSize().y;
        bgY2 *= -1;
    }


    bgSprite1.setPosition(0, bgY);
    bgSprite2.setPosition(0, bgY2);

}

void Background::draw(std::shared_ptr<sf::RenderWindow> window) {
    window->draw(bgSprite1);
    window->draw(bgSprite2);

}

Background::Background() {}
