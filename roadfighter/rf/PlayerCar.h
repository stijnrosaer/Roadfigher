//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_PLAYERCAR_H
#define PROJECTGP_PLAYERCAR_H

#include "Entity.h"
#include "Observable.h"
#include "World.h"

namespace roadfighter {
class PlayerCar : public roadfighter::Entity, public Observable
{
protected:
        enum direction
        {
                up,
                down,
                left,
                right,
                slow
        };

        float speed;
        float relativeSpeed;

        int exploding;
        int waitForShoot;

        bool del;

        void movePlayerCar(direction dir);

public:
        // constructor
        PlayerCar();

        // functions
        void draw() override = 0;
        void update(float speed, vector<shared_ptr<Entity>> entities) override;

        bool finish() override;

        // getters and setters
        void setLoc(location loc);

        float getSpeed() override;
        void setDelete(bool del) override;
        bool toDelete() override;
        void reload();
};
} // namespace roadfighter

#endif // PROJECTGP_PLAYERCAR_H
