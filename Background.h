//
// Created by stijn on 13/12/18.
//

#ifndef PROJECTGP_BACKGROUND_H
#define PROJECTGP_BACKGROUND_H


#include <SFML/Graphics.hpp>
#include <memory>

class Background {
private:
    sf::Texture bgTexture1;
    sf::Texture bgTexture2;

    sf::Sprite bgSprite1;
    sf::Sprite bgSprite2;

    sf::RectangleShape bgShape;

    float bgY;
    float bgY2;

public:
    Background();

    Background(std::shared_ptr<sf::RenderWindow> window);

    void update(std::shared_ptr<sf::RenderWindow> window, float move);
    void draw(std::shared_ptr<sf::RenderWindow> window);

};


#endif //PROJECTGP_BACKGROUND_H
