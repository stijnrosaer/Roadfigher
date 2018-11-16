//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_GAME_H
#define PROJECTGP_GAME_H


#include "PlayerCarSFML.h"

class Game {
private:
    shared_ptr<roadfighterSFML::PlayerCar> player;
    const int width = 800;
    const int height = 600;
public:
    Game();


};


#endif //PROJECTGP_GAME_H
