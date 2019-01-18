//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_PASSINGNORMALCARSFML_H
#define PROJECTGP_PASSINGNORMALCARSFML_H

#include "SFML/Graphics.hpp"
#include <rf/Observer.h>
#include <rf/PassingNormalCar.h>

namespace roadfighterSFML {
class PassingNormalCar : public roadfighter::PassingNormalCar
{
private:
        location pixloc;
        sf::Texture texture;
        sf::Sprite sprite;
        shared_ptr<sf::RenderWindow> window;

public:
        explicit PassingNormalCar(shared_ptr<sf::RenderWindow> window);

        void draw() override;
        void update(float speed, vector<shared_ptr<Entity>> entities) override;

        void setDelete(bool del) override;
};
} // namespace roadfighterSFML

#endif // PROJECTGP_PASSINGNORMALCARSFML_H