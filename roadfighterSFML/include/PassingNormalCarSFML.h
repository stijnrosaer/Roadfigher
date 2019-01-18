//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_PASSINGNORMALCARSFML_H
#define PROJECTGP_PASSINGNORMALCARSFML_H

#include "SFML/Graphics.hpp"
#include <rf/Observer.h>
#include <rf/PassingNormalCar.h>

namespace roadfighterSFML {
class PassingNormalCar : public roadfighter::PassingNormalCar
{
private:
        location pixloc;
        sf::Texture texture;
        sf::Sprite sprite;
        shared_ptr<sf::RenderWindow> window;

public:
        /**
         * constructor passingNormalCar
         * @param window window waar op getekend moet worden
         */
        explicit PassingNormalCar(shared_ptr<sf::RenderWindow> window);

        /**
         * teken de passingNormalCar op de window
         */
        void draw() override;
        /**
         * update wat nodig
         * @param speed snelheid van de speler
         * @param entities entities waarmee rekening te houden
         */
        void update(float speed, vector<shared_ptr<Entity>> entities) override;
};
} // namespace roadfighterSFML

#endif // PROJECTGP_PASSINGNORMALCARSFML_H