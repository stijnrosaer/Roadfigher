//
// Created by stijn on 16/11/18.
//

#include "Game.h"
#include "roadfighterSFML/include/FactorySFML.h"
#include <chrono>

void Game::run()
{
        initialize();
        location pos = {-0.225, -2};
        pos = Transformation::getInstance()->to2DWorldSpace(pos, 600, 450);
        pos = Transformation::getInstance()->toPixelSpace(pos, 600, 450);
        cout << pos.x << endl;

        Background background(window);

        double fps = 30;
        double tpf = 1 / fps;

        while (window->isOpen()) {
                auto startTime = chrono::high_resolution_clock::now();

                sf::Event event{};
                while (window->pollEvent(event)) {
                        if (event.type == sf::Event::Closed)
                                window->close();
                }
                window->clear(sf::Color(200, 0, 0));

                // all actions come here
                // update world
                world->update(0, {});

                if (distance > 100 && abs(prevLoadDist - distance) > 40) {
                        float chance = ((100 + distance / 50) * (world->getSpeed() / 450)) / 10;
                        //            cout << chance << endl;
                        if (Random::getInstance()->chance(chance / 200)) {
                                world->addEntity(fac->createPassingCar());
                                prevLoadDist = distance;
                        }
                }

                // update background
                background.update(window, static_cast<float>((15.0 * world->getSpeed()) / 350));

                // draw background
                background.draw(window);

                // draw world
                world->draw();

                // draw extra display elements
                sf::Font font;
                font.loadFromFile("../font/Arial.ttf");

                sf::Text dist;
                dist.setFont(font);
                dist.setString("distance: " + to_string(static_cast<int>(distance)));
                dist.setCharacterSize(20);
                dist.setPosition(430, 350);

                sf::Text scr;
                scr.setFont(font);
                scr.setString("score: " + to_string(static_cast<int>(score)));
                scr.setCharacterSize(20);
                scr.setPosition(430, 375);

                window->draw(dist);
                window->draw(scr);

                window->display();

                auto stopTime = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed = stopTime - startTime;

                while (elapsed.count() < tpf) {
                        stopTime = chrono::high_resolution_clock::now();
                        elapsed = stopTime - startTime;
                }
        }
}

void Game::react(action act)
{
        switch (act) {
        case shoot:
                world->addEntity(fac->createBullet(world->getPlayer()->getBounds().loc));
                break;

        case hitByBullet:
                this->score += 10;
                break;

        case mv:
                double prevdist = distance;
                distance += world->getSpeed() / 100;
                this->score += ((distance - prevdist) / 100);
                break;
        }
}

Game::~Game() {}

Game::Game()
{
        distance = 0;
        score = 0;
        prevLoadDist = 100;
}

void Game::initialize()
{
        window = make_shared<sf::RenderWindow>(sf::VideoMode(600, 450), "Roadfighter");
        this->world = make_shared<roadfighter::World>();
        fac = make_shared<roadfighterSFML::Factory>(window, shared_from_this());

        world->setPlayer(fac->createPlayerCar());
        world->addEntity(fac->createRacingCar());
}
