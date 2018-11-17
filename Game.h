//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_GAME_H
#define PROJECTGP_GAME_H


#include "roadfighterSFML/PlayerCarSFML.h"
#include "roadfighter/World.h"

class Game {
private:
    sf::RenderWindow window;
    shared_ptr<roadfighter::World> world;

public:
    Game();
    void run();



};


#endif //PROJECTGP_GAME_H
