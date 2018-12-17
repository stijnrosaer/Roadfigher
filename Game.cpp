//
// Created by stijn on 16/11/18.
//

#include "Game.h"
#include "roadfighterSFML/include/FactorySFML.h"
#include "Random.h"
#include <chrono>
#include <sstream>
#include <fstream>

Game::Game() {
    window = make_shared<sf::RenderWindow>(sf::VideoMode(600, 450), "Roadfighter");
    this->world = make_shared<roadfighter::World>();
    fac = make_shared<roadfighterSFML::Factory>(window);

    world->setPlayer(fac->createPlayerCar());

    distance = 0;
    prevLoadDist = 200;
}

void Game::run() {
    pair<float, float> pos = {-2, 8};
    pos = Transformation::getInstance()->transformTo2DWorldSpace(pos, 600, 450);
    pos = Transformation::getInstance()->transformToPixelSpace(pos, 600, 450);
    cout << pos.second << endl;

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
        world->update(0);
        distance += static_cast<float>(world->getSpeed())/100;

        if(distance > 100 && abs(prevLoadDist - distance) > 40){
            if(Random::getInstance()->random(1, 200) < 10){
                world->addEntity(fac->createPassingCar());
                prevLoadDist = distance;
            }
        }

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
        dist.setString("distance: " + to_string(static_cast<int>(distance)));
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

