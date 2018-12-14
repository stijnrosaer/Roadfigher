//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_GAME_H
#define PROJECTGP_GAME_H


#include "roadfighterSFML/include/PlayerCarSFML.h"
#include "rf/World.h"
#include "rf/Factory.h"
#include "Background.h"

class Game {
private:
    shared_ptr<roadfighter::Factory> fac;
    shared_ptr<sf::RenderWindow> window;
    shared_ptr<roadfighter::World> world;

    int distance;
    int prevLoadDist;

public:
    Game();
    void run();



};


#endif //PROJECTGP_GAME_H
