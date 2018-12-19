//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_BULLETSFML_H
#define PROJECTGP_BULLETSFML_H

#include <SFML/Graphics.hpp>
#include "rf/Bullet.h"

namespace roadfighterSFML {
    class Bullet : public roadfighter::Bullet {
    private:
        pair<float, float> pixloc;
        sf::Texture texture;
        sf::Sprite sprite;
        shared_ptr<sf::RenderWindow> window;


    public:
        Bullet(shared_ptr<sf::RenderWindow> window);
        void draw() override;
        void update(float speed, vector<shared_ptr<Entity>> entities) override;


    };
}

#endif //PROJECTGP_BULLETSFML_H
