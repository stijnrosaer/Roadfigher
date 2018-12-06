//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_RACINGCARSFML_H
#define PROJECTGP_RACINGCARSFML_H

#include "RacingCar.h"
#include "SFML/Graphics.hpp"

namespace roadfighterSFML {
    class RacingCar : public roadfighter::RacingCar {
    private:
        pair<float, float> pixloc;
        sf::Texture texture;
        sf::Sprite sprite;
        shared_ptr<sf::RenderWindow> window;


    public:
        RacingCar(shared_ptr<sf::RenderWindow> window);
        void draw() override;


    };
}

#endif //PROJECTGP_RACINGCARSFML_H
