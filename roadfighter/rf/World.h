//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_WORLD_H
#define PROJECTGP_WORLD_H

#include "Entity.h"
#include <typeinfo>

namespace roadfighter {
class World : public roadfighter::Entity
{
private:
        float speed;

        shared_ptr<roadfighter::Entity> player;
        vector<shared_ptr<roadfighter::Entity>> entities;
        vector<shared_ptr<roadfighter::Entity>> racingCars;

public:
        // constructor
        World();

        // getters and setters
        const shared_ptr<Entity>& getPlayer() const;

        void setPlayer(const shared_ptr<Entity>& player);
        void addEntity(const shared_ptr<Entity>& object);
    void addRacingCars(const shared_ptr<Entity>& passingCar);


    // functions
        void draw() override;
        void update(float speed, vector<shared_ptr<Entity>> entities) override;

        float getSpeed() override;
        bool toDelete() override;
        void setDelete(bool del) override;

        void remCollisions();
};
} // namespace roadfighter

#endif // PROJECTGP_WORLD_H
