//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_PASSINGPOINTSCARSFML_H
#define PROJECTGP_PASSINGPOINTSCARSFML_H

#include "SFML/Graphics.hpp"
#include "rf/PassingCar.h"
#include <rf/Observer.h>

namespace roadfighterSFML {
class PassingPointsCar : public roadfighter::PassingCar
{
private:
        location pixloc;
        sf::Texture texture;
        sf::Sprite sprite;
        shared_ptr<sf::RenderWindow> window;

public:
        PassingPointsCar(shared_ptr<sf::RenderWindow> window, shared_ptr<Observer> game);

        virtual ~PassingPointsCar();

        void draw() override;
        void update(float speed, vector<shared_ptr<Entity>> entities) override;

        void setDelete(bool del) override;
};
} // namespace roadfighterSFML

#endif // PROJECTGP_PASSINGPOINTSCARSFML_H