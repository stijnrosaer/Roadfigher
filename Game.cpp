//
// Created by stijn on 16/11/18.
//

#include "Game.h"

Game::Game() {
    window.create(sf::VideoMode(400, 300), "Roadfighter");
    window.setFramerateLimit(60);
    this->world = make_shared<roadfighter::World>();

}

void Game::run() {
    sf::Texture pTexture;
    sf::Sprite pSprite;
    pTexture.loadFromFile("../lib/playerCar.png");
    pSprite.setTexture(pTexture);

    while (window.isOpen()) {

        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        // all actions come here
        coordinate loc2 = Transformation::Instance()->transformTo2DWorldSpace(world->getPlayer()->GetLocation(), window.getSize().x, window.getSize().y);

        cout << "========" << endl;
        cout << window.getSize().x << endl;
        cout << loc2.x << endl;
        cout << "========" << endl;

        pSprite.setPosition(loc2.x, loc2.y);

        window.draw(pSprite);

        window.display();

    }
}

