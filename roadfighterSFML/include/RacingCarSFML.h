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
        /**
         * constructor racingCar
         * @param window window waar op te tekenen
         */
        explicit RacingCar(shared_ptr<sf::RenderWindow> window);
        /**
         * teken racing car op window
         */
        void draw() override;
        /**
         * update de parameters van racingCar
         * @param speed snelheid van de player
         * @param entities entities waarmee rekening te houden
         */
        void update(float speed, vector<shared_ptr<Entity>> entities) override;
};
} // namespace roadfighterSFML

#endif // PROJECTGP_RACINGCARSFML_H
