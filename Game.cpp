//
// Created by stijn on 16/11/18.
//

#include "Game.h"


Game::Game() {
    window.create(sf::VideoMode(800, 600), "Roadfighter");

}

void Game::run() {

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        // all actions come here

        sf::Texture pTexture;
        sf::Sprite pSprite;

        pTexture.loadFromFile("../lib/playerCar.png");
        pSprite.setTexture(pTexture);
        pSprite.setPosition(400, 500);

        window.draw(pSprite);

        window.display();
    }
}

