//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_PASSINGCARSFML_H
#define PROJECTGP_PASSINGCARSFML_H

#include "SFML/Graphics.hpp"
#include "rf/PassingCar.h"

namespace roadfighterSFML {
class PassingCar : public roadfighter::PassingCar
{
private:
        location pixloc;
        sf::Texture texture;
        sf::Sprite sprite;
        shared_ptr<sf::RenderWindow> window;

public:
        PassingCar(shared_ptr<sf::RenderWindow> window);

        virtual ~PassingCar();

        void draw() override;
        void update(float speed, vector<shared_ptr<Entity>> entities) override;
};
} // namespace roadfighterSFML

#endif // PROJECTGP_PASSINGCARSFML_H