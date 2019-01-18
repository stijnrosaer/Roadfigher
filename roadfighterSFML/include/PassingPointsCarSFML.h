//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_PASSINGPOINTSCARSFML_H
#define PROJECTGP_PASSINGPOINTSCARSFML_H

#include "SFML/Graphics.hpp"
#include <rf/PassingPointsCar.h>

namespace roadfighterSFML {
class PassingPointsCar : public roadfighter::PassingPointsCar
{
private:
        location pixloc;
        sf::Texture texture;
        sf::Sprite sprite;
        shared_ptr<sf::RenderWindow> window;

public:
        /**
         * constructor PassingPointsCar
         * @param window window waar op getekend word
         * @param game Game waaruit aangeroepen wordt
         */
        PassingPointsCar(shared_ptr<sf::RenderWindow> window, shared_ptr<Observer> game);
        /**
         * teken de passingPointsCar op de window
         */
        void draw() override;
        /**
         * update de nodige parameters van passingPointsCar
         * @param speed snelheid van de player
         * @param entities entities waarmee rekening te houden
         */
        void update(float speed, vector<shared_ptr<Entity>> entities) override;
};
} // namespace roadfighterSFML

#endif // PROJECTGP_PASSINGPOINTSCARSFML_H