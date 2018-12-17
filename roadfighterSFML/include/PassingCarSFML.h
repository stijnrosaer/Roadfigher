//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_PASSINGCARSFML_H
#define PROJECTGP_PASSINGCARSFML_H

#include "rf/PassingCar.h"
#include "SFML/Graphics.hpp"

namespace roadfighterSFML {
    class PassingCar : public roadfighter::PassingCar {
    private:
        pair<float, float> pixloc;
        sf::Texture texture;
        sf::Sprite sprite;
        shared_ptr<sf::RenderWindow> window;


    public:
        PassingCar(shared_ptr<sf::RenderWindow> window);

        virtual ~PassingCar();

        void draw() override;
        void update(int speed) override;


    };
}

#endif //PROJECTGP_PASSINGCARSFML_H