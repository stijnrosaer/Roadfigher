//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_GAME_H
#define PROJECTGP_GAME_H


#include "roadfighterSFML/include/PlayerCarSFML.h"
#include "roadfighter/include/World.h"
#include "roadfighter/include/Factory.h"

class Game {
private:
    shared_ptr<roadfighter::Factory> fac;
    shared_ptr<sf::RenderWindow> window;
    shared_ptr<roadfighter::World> world;

public:
    Game();
    void run();



};


#endif //PROJECTGP_GAME_H
