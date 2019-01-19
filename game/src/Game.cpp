//
// Created by stijn on 16/11/18.
//

#include "../include/Game.h"
#include "../../roadfighterSFML/include/FactorySFML.h"
#include <chrono>
#include <fstream>
#include <thread>

using json = nlohmann::json;

void Game::run()
{
        initialize();
        //        location pos = {-0.225, -2};
        //        pos = Transformation::getInstance()->to2DWorldSpace(pos, 600, 450);
        //        pos = Transformation::getInstance()->toPixelSpace(pos, 600, 450);
        //        cout << pos.x << endl;

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
                // check if finish is reached
                if (distance >= finishDistance - 100) {
                        background->finish(world->getSpeed());
                }
                if (distance >= finishDistance) {
                        finish();
                } else {
                        // update world
                        update();
                }

                // update background
                background->update(window, world->getSpeed());

                // draw background
                background->draw(window);

                // draw world
                world->draw();

                printDisplayElements();

                window->display();

                auto stopTime = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed = stopTime - startTime;

                while (elapsed.count() < tpf) {
                        stopTime = chrono::high_resolution_clock::now();
                        elapsed = stopTime - startTime;
                }
                if (score > highscore) {
                        highscore = static_cast<int>(score);
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

        case pointsCar:
                this->score += 20;
                break;

        case playerRespawn:
                this->score -= 50;
                if (this->score < 0) {
                        this->score = 0.0;
                }
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
        finishDistance = 6000;
        highscore = 0;
}

void Game::initialize()
{
        ifstream file;
        file.open("../scoreboard/scoreboard.json");
        scoreboard = json::parse(file);
        file.close();

        for (auto& item : scoreboard) {
                scoreboardMap.emplace_back(item["name"], item["score"]);
        }

        sort(scoreboardMap.begin(), scoreboardMap.end(),
             [](const pair<string, int>& lhs, const pair<string, int>& rhs) -> bool {
                     if (lhs.second == 0)
                             return false;
                     return lhs.second > rhs.second;
             });

        highscore = scoreboardMap[0].second;

        window = make_shared<sf::RenderWindow>(sf::VideoMode(600, 450), "Roadfighter");
        this->world = make_shared<roadfighter::World>();
        fac = make_shared<roadfighterSFML::Factory>(window, shared_from_this());

        world->setPlayer(fac->createPlayerCar());
        world->addRacingCars(fac->createRacingCar());
        background = make_shared<Background>(window);
}

void Game::printDisplayElements()
{
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

        sf::Text highScore;
        highScore.setFont(font);
        if (scoreboardMap[0].first != "~Game~") {
                if (highscore == scoreboardMap[0].second) {
                        highScore.setString("highscore: \n\n" + to_string(this->highscore) + "\n" +
                                            scoreboardMap[0].first);
                } else {
                        highScore.setString("highscore: \n\n" + to_string(this->highscore));
                }
        } else {
                highScore.setString("highscore: \n\n" + to_string(this->highscore));
        }
        highScore.setCharacterSize(20);
        highScore.setPosition(430, 100);

        window->draw(dist);
        window->draw(scr);
        window->draw(highScore);
}

void Game::finish()
{
        if (world->finish()) {
                window->close();
                endGame();
        }

        printDisplayElements();
}

void Game::endGame()
{

        string name;
        name += "NAME:\n\n";
        string outscore;
        outscore += "SCORE:\n\n";

        int counter = 100;

        for (auto& item : scoreboardMap) {
                if (counter > 0 && item.first != "~Game~") {
                        name += item.first;
                        name += "\n";
                        outscore += to_string(item.second);
                        outscore += "\n";
                        counter--;
                } else {
                        break;
                }
        }

        shared_ptr<sf::RenderWindow> scoreWindow;
        scoreWindow = make_shared<sf::RenderWindow>(sf::VideoMode(400, 600), "Score Board");
        sf::Font font;
        font.loadFromFile("../font/Arial.ttf");

        sf::Text printName;
        printName.setFont(font);
        printName.setString(name);
        printName.setCharacterSize(15);
        printName.setPosition(10, 40);

        sf::Text printScore;
        printScore.setFont(font);
        printScore.setString(outscore);
        printScore.setCharacterSize(15);
        printScore.setPosition(200, 40);

        sf::Text playerText;
        playerText.setFont(font);
        playerText.setString("");
        playerText.setCharacterSize(25);
        playerText.setPosition(10, 10);

        sf::Text playerScore;
        playerScore.setFont(font);
        playerScore.setString(to_string(static_cast<int>(score)));
        playerScore.setCharacterSize(25);
        playerScore.setPosition(300, 10);

        string playerInput;

        while (scoreWindow->isOpen()) {
                sf::Event event{};
                while (scoreWindow->pollEvent(event)) {
                        if (event.type == sf::Event::Closed) {
                                scoreWindow->close();
                        } else if (event.type == sf::Event::TextEntered) {
                                if (event.text.unicode == 13 && !playerInput.empty()) {
                                        ofstream file;
                                        file.open("../scoreboard/scoreboard.json");
                                        json::value_type out;
                                        out["name"] = playerInput;
                                        out["score"] = static_cast<int>(score);
                                        scoreboard.emplace_back(out);
                                        file << scoreboard;
                                        scoreboardMap.emplace_back(playerInput, static_cast<int>(score));
                                        file.close();
                                        std::this_thread::sleep_for(0.5s);
                                        scoreWindow->close();
                                } else if (event.text.unicode == 8 && !playerInput.empty()) {
                                        playerInput.pop_back();
                                        playerText.setString(playerInput);
                                } else if (event.text.unicode < 127 && event.text.unicode > 31 &&
                                           playerInput.size() < 15) {
                                        playerInput += static_cast<char>(event.text.unicode);
                                        playerText.setString(playerInput);
                                }
                        }
                }
                scoreWindow->clear();
                scoreWindow->draw(printName);
                scoreWindow->draw(printScore);
                scoreWindow->draw(playerText);
                scoreWindow->draw(playerScore);
                scoreWindow->display();
        }
}

void Game::update()
{
        world->update(0, {});

        if (distance > 100 && abs(prevLoadDist - distance) > 30) {
                float chance = ((150 + distance / 40) * (world->getSpeed() / 500)) / 5;
                //            cout << chance << endl;
                if (Random::getInstance()->chance(chance / 100)) {
                        if (Random::getInstance()->chance(0.10)) {
                                world->addEntity(fac->createPassingPointsCar());
                        } else {
                                world->addEntity(fac->createPassingNormalCar());
                        }
                        prevLoadDist = distance;
                }
        }
}
