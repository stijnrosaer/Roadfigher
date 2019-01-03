//
// Created by stijn on 16/11/18.
//

#include "../include/BulletSFML.h"
#include <utility>


roadfighterSFML::Bullet::Bullet(shared_ptr<sf::RenderWindow> window) {
    this->window = std::move(window);
    //this->texture.loadFromFile();
    sprite.setTexture(texture);

}

void roadfighterSFML::Bullet::draw() {
     pixloc = Transformation::getInstance()->to2DWorldSpace(bounds.tlLoc, window->getView().getSize().x,
                                                            window->getView().getSize().y);
    sprite.setPosition(static_cast<float>(pixloc.x), static_cast<float>(pixloc.y));
    window->draw(sprite);
}

void roadfighterSFML::Bullet::update(float speed, vector<shared_ptr<Entity>> entities) {
   // Bullet::update();
}
