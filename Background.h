//
// Created by stijn on 13/12/18.
//

#ifndef PROJECTGP_BACKGROUND_H
#define PROJECTGP_BACKGROUND_H

#include <SFML/Graphics.hpp>
#include <memory>

class Background
{
private:
        sf::Texture bgTexture1;
        sf::Sprite bgSprite1;
        sf::Texture finishTexture;
        sf::Sprite finishSprite;

        float bgY;

public:
        Background();

        Background(std::shared_ptr<sf::RenderWindow> window);

        void update(std::shared_ptr<sf::RenderWindow> window, float move);
        void draw(std::shared_ptr<sf::RenderWindow> window);
        void finish(float move);
};

#endif // PROJECTGP_BACKGROUND_H
