//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_BULLETSFML_H
#define PROJECTGP_BULLETSFML_H

#include "rf/Bullet.h"
#include <SFML/Graphics.hpp>

namespace roadfighterSFML {
class Bullet : public roadfighter::Bullet
{
private:
        location pixloc;
        sf::Texture texture;
        sf::Sprite sprite;
        shared_ptr<sf::RenderWindow> window;

public:
    /**
     * constructor voor een bullet
     * @param window window waar op te tekenen
     * @param loc locatie van de bullet
     * @param game game waaruit het opgeroepen wordt
     */
        Bullet(shared_ptr<sf::RenderWindow> window, location loc, shared_ptr<Observer> game);
        /**
         * teken de bullet
         */
        void draw() override;
        /**
         * update de bullet
         * @param speed snelheid van de player
         * @param entities enitities waarmee rekening gehouden moet worden
         */
        void update(float speed, vector<shared_ptr<Entity>> entities) override;
};
} // namespace roadfighterSFML

#endif // PROJECTGP_BULLETSFML_H
