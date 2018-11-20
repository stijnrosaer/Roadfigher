//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_PLAYERCARSSFML_H
#define PROJECTGP_PLAYERCARSSFML_H

#include "../roadfighter/PlayerCar.h"
#include <SFML/Graphics.hpp>

namespace roadfighterSFML {
    class PlayerCar : public roadfighter::PlayerCar {
    private:
        sf::Texture texture;
        sf::Sprite sprite;


    public:
        PlayerCar();

    };
}

#endif //PROJECTGP_PLAYERCARSSFML_H
