#include <utility>

//
// Created by stijn on 16/11/18.
//

#include "../include/BulletSFML.h"
#include <utility>

roadfighterSFML::Bullet::Bullet(shared_ptr<sf::RenderWindow> window, location loc, shared_ptr<Observer> game)
    : roadfighter::Bullet(loc)
{
        this->window = std::move(window);
        this->texture.loadFromFile("../img/bullet.png");
        sprite.setTexture(texture);
        sprite.scale(2.2f, 2.2f);

        this->addObserver(std::move(game));
}

void roadfighterSFML::Bullet::draw()
{
        pixloc = Transformation::getInstance()->to2DWorldSpace(bounds.tlLoc, this->window->getView().getSize().x,
                                                               this->window->getView().getSize().y);
        sprite.setPosition(static_cast<float>(pixloc.x), static_cast<float>(pixloc.y));
        window->draw(sprite);
}

void roadfighterSFML::Bullet::update(float speed, vector<shared_ptr<Entity>> entities)
{
        roadfighter::Bullet::update(speed, entities);

        moveBullet();
}
