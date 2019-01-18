//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_GAME_H
#define PROJECTGP_GAME_H

#include "../../roadfighterSFML/include/PlayerCarSFML.h"
#include "../../utils/include/Random.h"
#include "../../utils/include/json.hpp"
#include "Background.h"
#include "rf/Factory.h"
#include "rf/World.h"
#include <rf/Observer.h>

using json = nlohmann::json;

class Game : public Observer
{
private:
        shared_ptr<roadfighter::Factory> fac;
        shared_ptr<sf::RenderWindow> window;
        shared_ptr<roadfighter::World> world;
        shared_ptr<Background> background;

        float distance;
        float prevLoadDist;
        float finishDistance;

        double score;
        json scoreboard;
        vector<pair<string, int>> scoreboardMap;

        int highscore;

public:
        /**
         * constructor voor het aanmaken van een game
         */
        Game();
        /**
         * destructor van een game
         */
        virtual ~Game();

        /**
         * initialiseer een game en maak en world aan
         * de world zal de nodige elementen krijgen om te starte
         * background wordt aangemaakt
         */
        void initialize();

        /**
         * run het programma, van hieruit worden andere functies aangeroepen
         */
        void run();
        /**
         * update alle elementen uit world en de background
         */
        void update();
        /**
         * finish het spel door input niet meer te gaan accepteren en de finishlijn naar voor te laten komen
         */
        void finish();
        /**
         * print de scherm elementen score, distance en highscore tijdens het spel
         */
        void printDisplayElements();
        /**
         * eindig het spel en toon eens scherm voor je score op te slagen en het scorebord te bekijken
         */
        void endGame();

        /**
         * reageer op observables voor punten en aanmaken van bullets
         * @param act actie die te ondernemen isf
         */
        void react(action act) override;
};

#endif // PROJECTGP_GAME_H
