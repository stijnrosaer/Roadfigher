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
        /**
         * default constructor voor Background
         */
        Background();
        /**
         * constructor voor background met window waar op getekend moet worden
         * @param window de window van het spel
         */
        explicit Background(std::shared_ptr<sf::RenderWindow> window);

        /**
         * update de achtergrond door deze correct te bewegen
         * @param window de window waar op te tekenen
         * @param move aan welke snelheid de achtergrond bewongen moet worden
         */
        void update(std::shared_ptr<sf::RenderWindow> window, float move);
        /**
         * teken de achtergrond
         * @param window de window waar op te tekenen
         */
        void draw(std::shared_ptr<sf::RenderWindow> window);
        /**
         * beweeg de finishlijn
         * @param move aan welke snelheid de finishlijn bewogen moet worden
         */
        void finish(float move);
};

#endif // PROJECTGP_BACKGROUND_H
