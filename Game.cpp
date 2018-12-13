//
// Created by stijn on 16/11/18.
//

#include "Game.h"
#include "roadfighterSFML/include/FactorySFML.h"
#include <chrono>

Game::Game() {
    window = make_shared<sf::RenderWindow>(sf::VideoMode(400, 300), "Roadfighter");
    this->world = make_shared<roadfighter::World>();
    fac = make_shared<roadfighterSFML::Factory>(window);

    world->setPlayer(fac->createPlayerCar());
}

void Game::run() {
    Background background(window);

    auto startTime = chrono::high_resolution_clock::now();
    auto stopTime = chrono::high_resolution_clock::now();

    double fps = 30;
    double tpf = 1/fps;

    while (window->isOpen()) {
        startTime = chrono::high_resolution_clock::now();

        sf::Event event{};
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        window->clear();

        // all actions come here
        background.update(window, 2.0);
        background.draw(window);
        world->draw();

        window->display();

        stopTime = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = stopTime - startTime;

        while (elapsed.count() < tpf){
            stopTime = chrono::high_resolution_clock::now();
            elapsed = stopTime - startTime;
        }
    }
}

