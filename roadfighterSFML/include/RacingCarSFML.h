//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_RACINGCARSFML_H
#define PROJECTGP_RACINGCARSFML_H

#include "SFML/Graphics.hpp"
#include "rf/RacingCar.h"

namespace roadfighterSFML {
class RacingCar : public roadfighter::RacingCar
{
private:
        location pixloc;
        sf::Texture texture;
        sf::Sprite sprite;
        shared_ptr<sf::RenderWindow> window;

public:
        RacingCar(shared_ptr<sf::RenderWindow> window);
        void draw() override;
        void update(float speed, vector<shared_ptr<Entity>> entities) override;
};
} // namespace roadfighterSFML

#endif // PROJECTGP_RACINGCARSFML_H
