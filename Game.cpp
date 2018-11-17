//
// Created by stijn on 16/11/18.
//

#include "Game.h"


Game::Game() {
    window.create(sf::VideoMode(800, 600), "Roadfighter");

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.display();
    }
}

