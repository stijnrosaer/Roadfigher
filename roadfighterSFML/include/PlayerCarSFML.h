//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_PLAYERCARSSFML_H
#define PROJECTGP_PLAYERCARSSFML_H

#include <rf/PlayerCar.h>
#include <SFML/Graphics.hpp>

namespace roadfighterSFML {

    class Game;

    class PlayerCar : public roadfighter::PlayerCar {
    private:
        location pixloc;
        vector<sf::Texture> textures;

        sf::Sprite sprite;
        shared_ptr<sf::RenderWindow> window;


    public:
        PlayerCar(shared_ptr<sf::RenderWindow> window, weak_ptr<Observer> game);
        void draw() override;
        void update(float speed, vector<shared_ptr<Entity>> entities) override;


    };
}

#endif //PROJECTGP_PLAYERCARSSFML_H
