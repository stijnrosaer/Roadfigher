//
// Created by stijn on 16/11/18.
//

#include "Game.h"
#include "roadfighterSFML/include/FactorySFML.h"
#include <chrono>
#include <sstream>

Game::Game() {
    window = make_shared<sf::RenderWindow>(sf::VideoMode(600, 450), "Roadfighter");
    this->world = make_shared<roadfighter::World>();
    fac = make_shared<roadfighterSFML::Factory>(window);

    world->setPlayer(fac->createPlayerCar());

    distance = 0;
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
        window->clear(sf::Color(200,0,0));

        // all actions come here
        //update world
        world->update();
        distance += world->getSpeed()/100;

        //update background
        background.update(window, static_cast<float>((15.0 * world->getSpeed()) / 400));

        //draw background
        background.draw(window);

        //draw world
        world->draw();

        //draw extra display elements
        sf::Font font;
        font.loadFromFile("../font/Arial.ttf");

        sf::Text dist;
        dist.setFont(font);
        dist.setString("distance: " + to_string(distance));
        dist.setCharacterSize(20);
        dist.setFillColor(sf::Color::White);
        dist.setPosition(430, 350);
        window->draw(dist);

        window->display();

        stopTime = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = startTime - stopTime;

        while (elapsed.count() < tpf){
            stopTime = chrono::high_resolution_clock::now();
            elapsed = stopTime - startTime;
        }
    }
}

