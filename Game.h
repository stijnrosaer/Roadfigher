//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_GAME_H
#define PROJECTGP_GAME_H


#include <rf/Observer.h>
#include "roadfighterSFML/include/PlayerCarSFML.h"
#include "rf/World.h"
#include "rf/Factory.h"
#include "Background.h"

class Game : public Observer {
private:
    shared_ptr<roadfighter::Factory> fac;
    shared_ptr<sf::RenderWindow> window;
    shared_ptr<roadfighter::World> world;

    float distance;
    float prevLoadDist;

    int score;

public:
    Game();

    virtual ~Game();

    void run();

    void react(action act) override;

};


#endif //PROJECTGP_GAME_H
